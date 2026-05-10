#include "mainwindow.h"
#include "ui_mainwindow.h"
bool cont;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap minions (":/images/gato1.png");
    ui->lbl_minions->setPixmap(minions);

    //duas imagens
    QPixmap images (":/images/images2.jpg");
    ui->lbl_images->setPixmap(images);
    cont=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_images_clicked()
{
    /*botao com as duas imagens*/
    if(cont){
        QPixmap images (":/images/images1.jpg");
        ui->lbl_images->setPixmap(images);
        cont = 0;
        ui->btn_images->setText("Imagem tipo yng yang");
    }else{
        QPixmap images (":/images/images2.jpg");
        ui->lbl_images->setPixmap(images);
        cont = 1;
        ui->btn_images->setText("Imagem olhos");
    }
}

