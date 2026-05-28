#include "janelaeditar.h"
#include "ui_janelaeditar.h"
#include<QtSql>
#include<QMessageBox>
JanelaEditar::JanelaEditar(int id_contato, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaEditar)
{
    ui->setupUi(this);
    id = id_contato;
    ui->lbl_id->setText(QString::number(id));
    QSqlQuery query;
    query.prepare("select * from tb_contatos where id='"+QString::number(id)+"'");
    if(query.exec()){
        query.first();
        ui->edt_nome->setText(query.value(1).toString());
        ui->edt_nome->setText(query.value(2).toString());
        ui->edt_nome->setText(query.value(3).toString());
    }else{
        QMessageBox::warning(this, "error", "Erro ao selecionar contato");
    }
}

JanelaEditar::~JanelaEditar()
{
    delete ui;
}

void JanelaEditar::on_btn_gravar_clicked()
{
    QString nome = ui->edt_nome->text();
    QString telefone = ui->edt_telefone->text();
    QString email = ui->edt_email->text();

    QSqlQuery query;
    query.prepare("update tb_contatos set nome='"+nome+"', telefone='"+telefone+"', email='"+email+"' where id='"+QString::number(id)+"'");
    if(query.exec()){
    QMessageBox::information(this,"","Contato alterado com sucesso");
    this->close();
    }else{
    QMessageBox::warning(this,"Error","Contato não alterado");
    }
}


void JanelaEditar::on_btn_cancelar_clicked()
{
    close();
}

