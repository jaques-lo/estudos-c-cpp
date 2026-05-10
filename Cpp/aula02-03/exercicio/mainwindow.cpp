#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QtDebug>
//fazer cadastro, com botao para verificar se a variavel esta em branco, botao pra modificar, botao apagar
//pede confirmação toda vez q vai mudar
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
    if(ui->rad_femea->isChecked()){
        sexo = "femea";
    }
    else if(ui->rad_macho->isChecked()){
        sexo = "macho";
    }
    else{
        sexo = "indeterminado";
    }
    if (nome.isEmpty()) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "O nome esta vazio");
    }
    if (idade==0) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "a idade esta vazia");
    }
    ui->btn_salvar->deleteLater();


}


void MainWindow::on_btn_dados_clicked()
{
    ui->lbl_nome->setText(nome);
    ui->lbl_idade->setText(QString::number(idade));
    ui->lbl_sexo->setText(sexo);

}


void MainWindow::on_btn_alterar_clicked()
{
    //set
    nome = ui->edt_nome->text();
    idade = ui->edt_idade->text().toInt();
    ui->edt_idade->clear();
    ui->edt_nome->clear();
    ui->edt_nome->setFocus();


    if(ui->rad_femea->isChecked()){
        sexo = "femea";
    }
    else if(ui->rad_macho->isChecked()){
        sexo = "macho";
    }
    else{
        sexo = "indeterminado";
    }

    //verificacao se esta null

    if (nome.isEmpty()) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "O nome esta vazio");
    }
    if (idade==0) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "a idade esta vazia");
    }

/*
    //isso nao esta sendo efetivo ou funcionando
    if (sexo.isEmpty()) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "o sexo esta vazio");
    }
*/

    //confirmacao
    QMessageBox::StandardButton alteracao;
    alteracao = QMessageBox::question(this, "CONFIRMAÇÂO DA ALTERAÇÂO","Deseja alterar?",
        QMessageBox::Ok | QMessageBox::Cancel);

    if(alteracao==QMessageBox::Ok){

        QMessageBox::information(this, "alteracao", "cadastro alterado com sucesso");
    }else{
        nome = ui->lbl_nome->text();
        idade = ui->lbl_idade->text().toInt();
        QMessageBox::information(this, "alteracao", "cadastro nao alterado");
    }
}


void MainWindow::on_btn_limpar_clicked()
{
    QMessageBox::StandardButton limpeza;
     limpeza = QMessageBox::warning(this, "CONFIRMAÇÂO DA LIMPEZA","DESEJA EXCLUIR CADASTROS?",
     QMessageBox::Ok | QMessageBox::Cancel);

     if (limpeza==QMessageBox::Ok){
         QMessageBox::information(this, "Limpeza de Cadastro", "LIMPEZA DE CADASTRO EFETUADA");
         nome.clear();
         idade = 0;
         sexo = "inderterminado";
     }else{
         nome = ui->lbl_nome->text();
         idade = ui->lbl_idade->text().toInt();
         QMessageBox::information(this, "Limpeza de Cadastro", "Limpeza de cadastro CANCELADA");
     }

}

