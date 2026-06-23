#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include "janelanovolivro.h"
#include "janelapesquisar.h"
#include "QMessageBox"

JanelaPrincipal::JanelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaPrincipal)

{
    ui->setupUi(this);
    QString end_banco = "/home/usuario/Documentos/programacao/02-06/Biblioteca/db_biblioteca";
    bancoDeDados.setDatabaseName(end_banco);

    if(!bancoDeDados.open()){
        QMessageBox::warning(this, "Banco de Dados", "Banco de dados não abriu");
    }
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}


void JanelaPrincipal::on_btn_adicionar_clicked()
{
    JanelaNovoLivro *novo = new JanelaNovoLivro();
    novo->show();
}


void JanelaPrincipal::on_btn_pesquisar_clicked()
{
    JanelaPesquisar *pesquisar = new JanelaPesquisar;
    pesquisar->show();
}

