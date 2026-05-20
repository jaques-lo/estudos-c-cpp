#include "janelanovocontato.h"
#include "ui_janelanovocontato.h"
#include <QtSql>
#include <QMessageBox>

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

void JanelaNovoContato::on_btn_gravar_clicked()
{
    QString nome = ui->edt_nome->text();
    QString telefone = ui->edt_telefone->text();
    QString email = ui->edt_email->text();

    QSqlQuery query;
    query.prepare("insert into tb_contatos  (nome, telefone, email) values (' "+nome+ " ', ' "+telefone+" ',' "+email+" ') ") ;
    if(query.exec()) {
        QMessageBox::information(this, "", "registro gravado com sucesso" );
        ui->edt_nome->clear();
        ui->edt_telefone->clear();
        ui->edt_email->clear();
        ui->edt_nome->setFocus();
    }

}


void JanelaNovoContato::on_btn_cancelar_clicked()
{
        close();
}

