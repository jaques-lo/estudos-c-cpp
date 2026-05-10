#include "janela2.h"
#include "ui_janela2.h"
#include "mainwindow.h"
Janela2::Janela2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela2)
{
    ui->setupUi(this);
    QPixmap imagem("/home/usuario/Imagens/inutil/gato1.png");
    ui->lbl_imagem->setPixmap(imagem);
}

Janela2::~Janela2()
{
    delete ui;
}

void Janela2::on_MainWindow_clicked()
{
    MainWindow *form = new MainWindow();
    form->show();
    close();
}



