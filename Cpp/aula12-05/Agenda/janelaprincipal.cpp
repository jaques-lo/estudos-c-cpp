#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include "janelanovocontato.h"

JanelaPrincipal::JanelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

void JanelaPrincipal::on_btn_adicionar_clicked()
{
    JanelaNovoContato *novo = new JanelaNovoContato();
    novo->show();
}

