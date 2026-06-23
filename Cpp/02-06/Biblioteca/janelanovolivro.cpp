#include "janelanovolivro.h"
#include "ui_janelanovolivro.h"
#include <QtSql>
#include <QMessageBox>

JanelaNovoLivro::JanelaNovoLivro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaNovoLivro)
{
    ui->setupUi(this);
}

JanelaNovoLivro::~JanelaNovoLivro()
{
    delete ui;
}

void JanelaNovoLivro::on_btn_gravar_clicked()
{

    QString titulo = ui->edt_titulo->text();
    QString autor = ui->edt_autor->text();
    QString editora = ui->edt_editora->text();
    //==REVISAR COMO FAZER COM INT==
    int codigo_livro = ui->edt_codigo->text().toInt();
    int ano = ui->edt_ano->text().toInt();
    int quantidade = ui->edt_quantidade->text().toInt();

    QSqlQuery query;
    //falta adicionar oq é int.
    query.prepare(
        "INSERT INTO tb_livros "
        "(titulo, autor, editora, quantidade, ano, codigo_livro) "
        "VALUES ('" + titulo + "', '" +
                      autor + "', '" +
                      editora + "', " +
                      QString::number(quantidade) + ", " +
                      QString::number(ano) + ", " +
                      QString::number(codigo_livro) + ")"
    );

    if(query.exec()) {
        QMessageBox::information(this, "", "registro gravado com sucesso" );

        ui->edt_ano->clear();
        ui->edt_autor->clear();
        ui->edt_codigo->clear();
        ui->edt_editora->clear();
        ui->edt_titulo->clear();
        ui->edt_quantidade->clear();

        ui->edt_titulo->setFocus();
    }else{
        qDebug() << query.lastQuery();
        qDebug() << query.lastError().text();
        QMessageBox::warning(this,"AVISO", query.lastError().text());
    }

}


void JanelaNovoLivro::on_btn_cancelar_clicked()
{
    close();
}

