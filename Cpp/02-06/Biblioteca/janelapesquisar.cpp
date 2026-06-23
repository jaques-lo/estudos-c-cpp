#include "janelapesquisar.h"
#include "ui_janelapesquisar.h"
#include "QtSql"
#include "qmessagebox.h"
#include "janelaeditar.h"
JanelaPesquisar::JanelaPesquisar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaPesquisar)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from tb_livros");
    if(query.exec()){
        int cont = 0;
        ui->tw_livros->setColumnCount(6);
        while (query.next()){
            ui->tw_livros->insertRow(cont);
            ui->tw_livros->setItem(cont, 0 , new QTableWidgetItem(query.value(0).toString()) );
            ui->tw_livros->setItem(cont, 1 , new QTableWidgetItem(query.value(1).toString()) );
            ui->tw_livros->setItem(cont, 2 , new QTableWidgetItem(query.value(2).toString()) );
            ui->tw_livros->setItem(cont, 3 , new QTableWidgetItem(query.value(3).toString()) );

            ui->tw_livros->setItem(cont, 4 , new QTableWidgetItem(query.value(4).toString()) );
            ui->tw_livros->setItem(cont, 5 , new QTableWidgetItem(query.value(5).toString()) );

            ui->tw_livros->setRowHeight(cont,20);
            cont++;
        }
        ui->tw_livros->setColumnWidth(0,30);
        ui->tw_livros->setColumnWidth(1,150);
        ui->tw_livros->setColumnWidth(3,100);
        ui->tw_livros->setColumnWidth(3,100);
        ui->tw_livros->setColumnWidth(3,100);
        ui->tw_livros->setColumnWidth(3,100);


        QStringList cabecalho = {"id", "titulo", "autor", "ano", "editora", "quantidade"};
        ui->tw_livros->setHorizontalHeaderLabels(cabecalho);

        ui->tw_livros->setEditTriggers(QAbstractItemView::NoEditTriggers);//faz com que nao altere
        ui->tw_livros->setSelectionBehavior(QAbstractItemView::SelectRows);//seleciona a linha inteira
        ui->tw_livros->verticalHeader()->setVisible(false);//tira os numeros latetais
        ui->tw_livros->setStyleSheet("QTableView {selection-backgorund-color:blue};");

    }
}

JanelaPesquisar::~JanelaPesquisar()
{
    delete ui;
}

void JanelaPesquisar::on_btn_excluir_clicked()
{
    int linha = ui->tw_livros->currentRow();
    int id = ui->tw_livros->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_livros where codigo_livro='"+QString::number(id)+"'");
    if(query.exec()){
        ui->tw_livros->removeRow(linha);
        QMessageBox::information(this, "", "Registro Removido");
    }else{
        QMessageBox::warning(this, "Erros", "Erro ao excluir");
    }

}


void JanelaPesquisar::on_btn_editar_clicked()
{
    int linha = ui->tw_livros->currentRow();
    int id = ui->tw_livros->item(linha, 0)->text().toUInt();
    JanelaEditar editar(id);
    editar.exec();

    QSqlQuery query;
    query.prepare("select * from tb_livros where id='"+QString::number(id)+"'");
    if(query.exec()){
        query.first();
        ui->tw_livros->setItem(linha,1,new QTableWidgetItem(query.value(1).toString()) );
        ui->tw_livros->setItem(linha,2,new QTableWidgetItem(query.value(3).toString()) );
        ui->tw_livros->setItem(linha,3,new QTableWidgetItem(query.value(3).toString()) );


        ui->tw_livros->setItem(linha,4,new QTableWidgetItem(query.value(4).toString()) );
        ui->tw_livros->setItem(linha,5,new QTableWidgetItem(query.value(5).toString()) );
        ui->tw_livros->setItem(linha,6,new QTableWidgetItem(query.value(6).toString()) );

    }else{
        QMessageBox::warning(this, "ERROR", "Não foi possivel atualizar a tabela");
    }

}


void JanelaPesquisar::on_btn_pesquisar_clicked()
{
    QString pesquisa = ui->edt_pesquisar->text();

    QSqlQuery query;
    //concatenacao por livros
    query.prepare(
        "SELECT * FROM tb_livros "
        "WHERE titulo LIKE '%" + pesquisa + "%' "
        "OR autor LIKE '%" + pesquisa + "%'"
    );

    if(query.exec()){
        ui->tw_livros->setRowCount(0);
        int linha = 0;
        while (query.next()){
            ui->tw_livros->insertRow(linha);

            ui->tw_livros->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_livros->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_livros->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tw_livros->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tw_livros->setItem(linha, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->tw_livros->setItem(linha, 5, new QTableWidgetItem(query.value(5).toString()));

            linha++;
        }
    }else{
        QMessageBox::warning(this,"ERROR", "nao foi possivel pesquisar os dados");
    }
}

