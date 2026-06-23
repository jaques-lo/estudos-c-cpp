#include "janelaeditar.h"
#include "ui_janelaeditar.h"
#include<QtSql>
#include<QMessageBox>
JanelaEditar::JanelaEditar(int codigo_livro,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaEditar)
{
    ui->setupUi(this);
    id = codigo_livro;
    ui->lbl_id->setText(QString::number(id));
    QSqlQuery query;
    query.prepare("select * from tb_livros where codigo_livro='"+QString::number(id)+"'");
    if(query.exec()){
        query.first();
        ui->edt_titulo->setText(query.value(1).toString());
        ui->edt_editora->setText(query.value(2).toString());
        ui->edt_autor->setText(query.value(3).toString());

        ui->edt_ano->setText(query.value(4).toString());
        ui->edt_codigo->setText(query.value(5).toString());
        ui->edt_quantidade->setText(query.value(6).toString());

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

    QString titulo = ui->edt_titulo->text();
    QString autor = ui->edt_autor->text();
    QString editora = ui->edt_editora->text();
    //numeros int
    int codigo_livro = ui->edt_codigo->text().toInt();
    int ano = ui->edt_ano->text().toInt();
    int quantidade = ui->edt_quantidade->text().toInt();

    QSqlQuery query;
    query.prepare(
    "UPDATE tb_livros SET "
    "titulo='" + titulo + "', "
    "autor='" + autor + "', "
    "editora='" + editora + "', "
    "ano=" + QString::number(ano) + ", "
    "quantidade=" + QString::number(quantidade) +
    " WHERE codigo_livro=" + QString::number(codigo_livro)
            );
    if(query.exec()){
    QMessageBox::information(this,"","Livro alterado com sucesso");
    this->close();
    }else{
    QMessageBox::warning(this,"Error","Livro não alterado");
    }
}


void JanelaEditar::on_btn_cancelar_clicked()
{
    close();
}

