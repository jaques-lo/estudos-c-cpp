#include "blocodenotas.h"
#include "ui_blocodenotas.h"
#include <QFileDialog>
#include <qmessagebox.h>
#include <QFontDialog>
#include <QTextStream>
#include<QColorDialog>
#include<QPrinter>
#include<QPrintDialog>
BlocoDeNotas::BlocoDeNotas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BlocoDeNotas)
{
    ui->setupUi(this);

    this -> setCentralWidget(ui->textEdit);
}

BlocoDeNotas::~BlocoDeNotas()
{
    delete ui;
}

void BlocoDeNotas::on_actionnovo_triggered()
{
    local_arquivo = "";
    ui->textEdit->clear();
    ui->textEdit->setFocus();
}


void BlocoDeNotas::on_actionabrir_triggered()
{
    QString filtro = "Todos Arquivos (*.*) ;; Arquivos de texto (*.txt)";
    QString nome_arquivo = QFileDialog::getOpenFileName(this, "abrir", QDir::homePath(), filtro);
    QFile arquivo(nome_arquivo);
    local_arquivo = nome_arquivo;
    if(!arquivo.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "abrir", "arquivo nao pode ser aberto");
    }
    QTextStream entrada(&arquivo);
    QString texto = entrada.readAll();
    ui->textEdit->setText(texto);
    arquivo.close();
}


void BlocoDeNotas::on_actionsalvar_como_triggered()
{
    QString filtro = "Todos Arquivos (*.*) ;; Arquivos de texto (*.txt)";
    QString nome_arquivo = QFileDialog::getSaveFileName(this, "Salvar como", QDir::homePath(), filtro);
    QFile arquivo(nome_arquivo);
     if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
         QMessageBox::warning(this, "Salvar como", "arquivo nao pode ser salvo");
     }
    QTextStream saida(&arquivo);
    QString texto = ui->textEdit->toPlainText();
    saida << texto;
    arquivo.flush();
    arquivo.close();
    local_arquivo=nome_arquivo;

}


void BlocoDeNotas::on_actionsalvar_triggered()
{
    QFile arquivo(local_arquivo);
    if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "salvar como", "nao pode ser salvo");
        return;
    }
    QTextStream saida(&arquivo);
    QString texto = ui->textEdit->toPlainText();
    saida<<texto;
    arquivo.flush();
    arquivo.close();


}


void BlocoDeNotas::on_actionsair_triggered()
{
    close();
}


void BlocoDeNotas::on_actionRecortar_triggered()
{
    ui->textEdit->cut();
}


void BlocoDeNotas::on_actionCopiar_triggered()
{
    ui->textEdit->copy();

}


void BlocoDeNotas::on_actionColar_triggered()
{
    ui->textEdit->paste();
}


void BlocoDeNotas::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}


void BlocoDeNotas::on_actionRefazer_triggered()
{
    ui->textEdit->redo();
}


void BlocoDeNotas::on_actionFonte_triggered()
{
    bool font_ok;
    QFont fonte = QFontDialog::getFont(&font_ok,this);
    if(font_ok){
        ui->textEdit->setFont(fonte);
    }else{
        return;
    }
}


void BlocoDeNotas::on_actionCor_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::black,this,"Escolha a cor");
    if(cor.isValid()){
        ui->textEdit->setTextColor(cor);
    }else return;
}


void BlocoDeNotas::on_actionCor_de_Fundo_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::black,this,"Escolha a cor");
    if(cor.isValid()){
        ui->textEdit->setTextBackgroundColor(cor);
    }else return;
}


void BlocoDeNotas::on_actionPrimeiro_Software_QT_triggered()
{
    QMessageBox::aboutQt(this, "QT creator");


}


void BlocoDeNotas::on_actionimprimir_triggered()
{
    QPrinter imp;
    imp.setPrinterName("impressora");
    QPrintDialog cx_imp(&imp, this);
    if(cx_imp.exec()==QDialog::Rejected)return;
      ui->textEdit->print(&imp);
}

