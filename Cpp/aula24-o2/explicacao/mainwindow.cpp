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
    ui->edt_nome->clear();
    ui->edt_nome->setFocus();
}


void MainWindow::on_btn_dados_clicked()
{
    ui->lbl_nome->setText(nome);
}

