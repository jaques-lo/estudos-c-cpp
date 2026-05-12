#include "janelanovocontato.h"
#include "ui_janelanovocontato.h"

JanelaNovoContato::JanelaNovoContato(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaNovoContato)
{
    ui->setupUi(this);
}

JanelaNovoContato::~JanelaNovoContato()
{
    delete ui;
}
