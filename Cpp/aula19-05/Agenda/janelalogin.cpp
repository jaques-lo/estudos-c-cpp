#include "janelalogin.h"
#include "ui_janelalogin.h"
#include "janelaprincipal.h"
#include <QMessageBox>

JanelaLogin::JanelaLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JanelaLogin)
{
    ui->setupUi(this);
    //    QString end_banco = "/CaminhoDoArquivoDoDb/Agenda/db_agenda";
    QString end_banco = "/home/usuario/Documentos/estudos-c-cpp/Cpp/aula19-05/Agenda/db_agenda";
    bancoDeDados.setDatabaseName(end_banco);

    if(!bancoDeDados.open()){
        QMessageBox::warning(this, "Banco de Dados", "Banco de dados não abriu");
    }
}


JanelaLogin::~JanelaLogin()
{
    delete ui;
}

void JanelaLogin::on_pushButton_clicked()
{
    QString user = ui->edt_username->text();
    QString code = ui->edt_senha->text();

    if(!bancoDeDados.open()){
        QMessageBox::warning(this, "Banco de Dados", "Banco de dados não abriu");
        return;
    }

    QSqlQuery query;
    if(query.exec("Select * from tb_colaboradores where username='"+user+"' and senha='"+code+"'")){
        int cont=0;
        while(query.next()){
            cont++;
        }
        if(cont>0){
            JanelaPrincipal *principal = new JanelaPrincipal();
            principal->show();
            close();
        }else{
        QMessageBox::warning(this,"Login","Usuário ou senha incorretos");
        ui->edt_senha->clear();
        ui->edt_username->clear();
        ui->edt_username->setFocus();
        }
    }
}

/*
    if(user == nome){
        if(senha == code){
            JanelaPrincipal *principal = new JanelaPrincipal();
            principal->show();
            ui->edt_senha->clear();
            ui->edt_username->clear();
            close();
        }else{
            QMessageBox::warning(this,"Login","Usuário ou senha incorretos");
            ui->edt_senha->clear();
            ui->edt_username->clear();
            ui->edt_username->setFocus();
        }
    }else{
        QMessageBox::warning(this,"Login","Usuário ou senha incorretos");
        ui->edt_username->setFocus();
*/




