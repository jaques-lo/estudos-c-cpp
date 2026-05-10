#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_muda,SIGNAL(clicked()),this,SLOT(mudaTexto()));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::mudaTexto(){

    ui->lbl_texto->setText("Textos");

}
