#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QtDebug>
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


void MainWindow::on_btn_mensagem_clicked()
{
// todos os tipos de message box
    /*
    //criar caixa de mensagem
    QMessageBox::about(this,                                //Qwidget-> quem é o pai desse elemento, qual é o contexto
                       "Titulo da caixa",                   //titulo da caixa de mensagem
                       " Conteudo da caixa de mensagem");   //Conteudo do texto que vai aparecer na caixa de mensagem



    //sobre Qt
    QMessageBox::aboutQt(this, "Titulo da caixa");



    //critico
    QMessageBox::critical(this, "Titulo da caixa", "Conteudo critico");


    //informação
    QMessageBox::information(this,"titulo da caixa", "conteudo informado");


    //alerta
    QMessageBox::warning(this, "Titulo da caixa", "Alerta");



    // question
    QMessageBox::question(this, "titulo da caixa", "Question");
*/

    //variavel do tipo standard
    QMessageBox::StandardButton resposta;

/*
    //por default ele tem dois botoes
    //mesmo que nao coloque os botoens standard
    resposta = QMessageBox::question(this, "finalizar", "deseja fechar o programa");

    if(resposta==QMessageBox::Yes){
        close();
    }else{
        qDebug() << "Programa não foi fechado";
    }
*/

    resposta = QMessageBox::question(this, "finalizar","Deseja fechar o programa?",
        QMessageBox::Ok | QMessageBox::Cancel| QMessageBox::Apply);

    if(resposta==QMessageBox::Ok){
        close();
    }else if(resposta==QMessageBox::Cancel){
       qDebug() << "Programa não foi fechado";
    }else{
         QMessageBox::information(this, "alteracao", "objeto alterado com sucesso");
    };

}

