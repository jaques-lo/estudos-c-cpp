#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "janela2.h"

//desafio é fazer um jogo da forca

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


void MainWindow::on_btn_janela2_clicked()
{
    Janela2 *form2 = new Janela2();
    form2->show();
    close();
}


void MainWindow::on_btn_carrega_clicked()
{
    palavra = ui->edt_palavra->text();
    palavraAdivinha = "";

    for(int i = 0; i < palavra.length(); i++){
        palavraAdivinha += "_";
    }

    ui->lbl_tentativa->setText(palavraAdivinha);
}

void MainWindow::on_btn_testa_clicked()
{
    QString tentativa = ui->edt_tentativa->text();
    if(tentativa.isEmpty()) return;

    QChar letra = tentativa.at(0);
    bool acertou = false;

    for(int i = 0; i < palavra.length(); i++){
        if(palavra[i] == letra){
            palavraAdivinha[i] = letra;
            acertou = true;

            ui->edt_tentativa->clear();
            ui->edt_tentativa->setFocus();
        }
    }

    ui->lbl_tentativa->setText(palavraAdivinha);

    if(!acertou){
        qDebug("Errou!");
    }

    // Verifica vitória
    if(palavraAdivinha == palavra){
        ui->lbl_tentativa->setText("GANHOU!");
        Janela2 *form2 = new Janela2();
        form2->show();
        close();
    }
}
