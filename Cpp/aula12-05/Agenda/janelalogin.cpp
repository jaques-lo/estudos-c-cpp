#include "janelalogin.h"
#include "ui_janelalogin.h"
#include "janelaprincipal.h"
#include <QMessageBox>
#include <QDir>

JanelaLogin::JanelaLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JanelaLogin)
{
    ui->setupUi(this);

    QString end_banco = qApp->applicationDirPath() + "/db/db_agenda";

    // Cria a pasta "db" caso não exista
    QDir dir;
    dir.mkpath(qApp->applicationDirPath() + "/db");

    bancoDeDados.setDatabaseName(end_banco);

    if (!bancoDeDados.open()) {
        QMessageBox::warning(this, "Banco de Dados", "Banco de dados não abriu");
        return;
    }

    // Cria a tabela e usuário padrão na primeira execução
    QSqlQuery query;
    query.exec(
        "CREATE TABLE IF NOT EXISTS tb_colaboradores ("
        "id                 INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome_colaborador   TEXT,"
        "username           TEXT NOT NULL UNIQUE,"
        "senha              TEXT NOT NULL,"
        "acesso_colaborador TEXT)"
    );

    query.exec("SELECT COUNT(*) FROM tb_colaboradores");
    if (query.next() && query.value(0).toInt() == 0) {
        query.exec("INSERT INTO tb_colaboradores (nome_colaborador, username, senha) "
                   "VALUES ('Administrador', 'admin', '1234')");
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
