#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_salvar_clicked()
{
    nome = ui->edt_nome->text();
    idade = ui->edt_idade->text().toInt();
    ui->edt_idade->clear();
    ui->edt_nome->clear();
    ui->edt_nome->setFocus();

    if(ui->chk_femea->isChecked()){
        sexo = "femea";
         //ui->chk_macho->setChecked(false);
    }else if(ui->chk_macho->isChecked()){
        sexo = "macho";
    }else{
        sexo = "indeterminado";
    }

}


void MainWindow::on_btn_dados_clicked()
{

    ui->lbl_nome->setText(nome);
    ui->lbl_idade->setText(QString::number(idade));
    ui->lbl_sexo->setText(sexo);
}



void MainWindow::on_chk_femea_stateChanged(int)
{

}

