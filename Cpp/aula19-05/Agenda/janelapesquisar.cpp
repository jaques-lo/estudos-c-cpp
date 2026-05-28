#include "janelapesquisar.h"
#include "ui_janelapesquisar.h"
#include<qmessagebox.h>
#include <QtSql>
#include "janelaeditar.h"

JanelaPesquisar::JanelaPesquisar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JanelaPesquisar)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from tb_contatos");
    if(query.exec()){
        int cont = 0;
        ui->tw_contatos->setColumnCount(4);
        while (query.next()){
            ui->tw_contatos->insertRow(cont);
            ui->tw_contatos->setItem(cont, 0 , new QTableWidgetItem(query.value(0).toString()) );
            ui->tw_contatos->setItem(cont, 1 , new QTableWidgetItem(query.value(1).toString()) );
            ui->tw_contatos->setItem(cont, 2 , new QTableWidgetItem(query.value(2).toString()) );
            ui->tw_contatos->setItem(cont, 3 , new QTableWidgetItem(query.value(3).toString()) );
            ui->tw_contatos->setRowHeight(cont,20);
            cont++;
        }
        ui->tw_contatos->setColumnWidth(0,30);
        ui->tw_contatos->setColumnWidth(1,150);
        ui->tw_contatos->setColumnWidth(3,100);

        QStringList cabecalho = {"ID", "Nome", "Telefone", "e-mail"};
        ui->tw_contatos->setHorizontalHeaderLabels(cabecalho);

        ui->tw_contatos->setEditTriggers(QAbstractItemView::NoEditTriggers);//faz com que nao altere
        ui->tw_contatos->setSelectionBehavior(QAbstractItemView::SelectRows);//seleciona a linha inteira
        ui->tw_contatos->verticalHeader()->setVisible(false);//tira os numeros latetais
        ui->tw_contatos->setStyleSheet("QTableView {selection-backgorund-color:blue};");

    }
}

JanelaPesquisar::~JanelaPesquisar()
{
    delete ui;
}

void JanelaPesquisar::on_btn_excluir_clicked()
{
    int linha = ui->tw_contatos->currentRow();
    int id = ui->tw_contatos->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_contatos where id='"+QString::number(id)+"'");
    if(query.exec()){
        ui->tw_contatos->removeRow(linha);
        QMessageBox::information(this, "", "Registro Removido");
    }else{
        QMessageBox::warning(this, "Erros", "Erro ao excluir");
    }
}

void JanelaPesquisar::on_btn_editar_clicked()
{
    int linha = ui->tw_contatos->currentRow();
    int id = ui->tw_contatos->item(linha, 0)->text().toUInt();
    JanelaEditar editar(id);
    editar.exec();

    QSqlQuery query;
    query.prepare("select * from tb_contatos where id='"+QString::number(id)+"'");
    if(query.exec()){
        query.first();
        ui->tw_contatos->setItem(linha,1,new QTableWidgetItem(query.value(1).toString()) );
        ui->tw_contatos->setItem(linha,2,new QTableWidgetItem(query.value(3).toString()) );
        ui->tw_contatos->setItem(linha,3,new QTableWidgetItem(query.value(3).toString()) );
    }else{
        QMessageBox::warning(this, "ERROR", "Não foi possivel atualizar a tabela");
    }

}
