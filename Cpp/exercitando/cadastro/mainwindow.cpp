#include "mainwindow.h"
#include "ui_mainwindow.h"

//caixa de mensagem
#include <QMessageBox>
//uso do terminal
#include<QtDebug>

//nao ensinado em aula, faz com que eu possa determinar o tamanho de uma string
//usado no cpf
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ===== VALIDAÇÃO DO CPF =====

    // Cria uma expressão regular que aceita APENAS 11 dígitos numéricos.
    // ^  -> início da string
    // \d -> qualquer número de 0 a 9
    // {11} -> exatamente 11 repetições
    // $  -> fim da string
    // Ou seja, só aceita algo como: 12345678901
    QRegularExpression regex("^\\d{11}$");

    // Cria um validador usando a expressão regular criada.
    // Esse objeto será responsável por verificar se o texto digitado
    // corresponde ao padrão definido (11 números).
    // "this" indica que o objeto atual será o pai do validator,
    // fazendo com que o Qt gerencie automaticamente a memória.
    QRegularExpressionValidator *validator =
            new QRegularExpressionValidator(regex, this);

    // Aplica o validador ao campo de texto "edt_cpf" da interface.
    // Assim, o usuário só poderá digitar valores que sigam o padrão
    // definido na expressão regular (11 dígitos numéricos).
    ui->edt_cpf->setValidator(validator);}

MainWindow::~MainWindow()
{
    delete ui;
}


//comeca realmente aqui
void MainWindow::on_btn_salvar_clicked()
{

//===CAPTURANDO DADOS && SETANDO ===
    nome = ui->edt_nome->text();
    idade = ui->edt_idade->text().toInt();
    cpf = ui->edt_cpf->text();

    //confirmação de genero

    if(ui->rad_femea->isChecked()){
        sexo = "mulher";
    }
    else if(ui->rad_macho->isChecked()){
        sexo = "homem";
    }
    else{
        sexo = "indeterminado";
    }

//===JANELAS DE AVISOS===

    //avisos na tela para verificações se esta sem os dados
    if (nome.isEmpty()) {
        QMessageBox::critical(this, "CRITICO", "O nome esta vazio");
    }
    if (idade==0) {
        QMessageBox::critical(this, "CRITICO", "a idade esta vazia");
    }
    //check de genero
    if(!ui->rad_macho->isChecked() && !ui->rad_femea->isChecked()){
        QMessageBox::critical(this, "CRITICO", "O genero nao foi informado");
    }
    //explicação dessas funções na linha 158
    if(cpf.isEmpty()) {
        QMessageBox::critical(this, "CRITICO", "O cpf esta vazio");
        //coloco isso para que o cpf apareça somente se estiver direitinho
        cpf="indeterminado";
    }else if(ui->edt_cpf->text().length() != 11){
        QMessageBox::critical(this, "CRITICO", "CPF inválido! Deve ter 11 números.");
        //coloco isso para que o cpf apareça somente se estiver direitinho
        cpf="indeterminado";
    }
    else if (cpf.isEmpty() && ui->edt_cpf->text().length() != 11) {
        QMessageBox::critical(this, "CRITICO", "O cpf esta vazio, e nao tem o numero de digitos");
        //coloco isso para que o cpf apareça somente se estiver direitinho
        cpf="indeterminado";
    }
//==limpa os campos==
    ui->edt_cpf->clear();
    ui->edt_idade->clear();
    ui->edt_nome->clear();
    ui->edt_nome->setFocus();
    ui->btn_salvar->deleteLater();
}

void MainWindow::on_btn_dados_clicked()
{
    //mostrar os dados setados
    ui->lbl_cpf->setText(cpf);
    ui->lbl_nome->setText(nome);
    ui->lbl_idade->setText(QString::number(idade));
    ui->lbl_sexo->setText(sexo);
    //se o cpf nao esta definido aparece a mensagem no lbl(label)
    if(cpf.isEmpty()){
        //mensagem do lbl
          ui->lbl_cpf->setText("cpf nao especificado");
      }
}

//=== EXPLICAÇÃO ===
    /*aqui eu basicamente replico tudo que eu fiz no botao salvar
    pois o botao de alterar ele é um salvar so que pt.2 kkk*/

void MainWindow::on_btn_alterar_clicked()
{
    //setando dados
    nome = ui->edt_nome->text();
    idade = ui->edt_idade->text().toInt();
    cpf = ui->edt_cpf->text();

    //confirmando o genero
    if(ui->rad_femea->isChecked()){
        sexo = "mulher";
    }
    else if(ui->rad_macho->isChecked()){
        sexo = "homem";
    }
    else{
        sexo = "indeterminado";
    }

    //verificacao se esta sem os dados
    if (nome.isEmpty()) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "O nome esta vazio");
    }
    if (idade==0) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "a idade esta vazia");
    }

//==EXPLICACAO DA CONFIRMÇÃO DO CPF===

    /*se o cpf esta vazio e esta diferente dos 11 caracteres necessarios
    ele apresenta a mensagem "O cpf esta vazio, e nao tem o numero de digitos"
    se ele so esta vazio "O cpf esta vazio"
    se ele esta diferente dos 11 caracteres "CPF inválido! Deve ter 11 números.
    */
    if(cpf.isEmpty()) {
        QMessageBox::critical(this, "CRITICO", "O cpf esta vazio");
        //coloco isso para que o cpf apareça somente se estiver direitinho
        cpf="indeterminado";
    }else if(ui->edt_cpf->text().length() != 11){
        QMessageBox::critical(this, "CRITICO", "CPF inválido! Deve ter 11 números.");
        //coloco isso para que o cpf apareça somente se estiver direitinho
        cpf="indeterminado";
    }
    else if (cpf.isEmpty() && ui->edt_cpf->text().length() != 11) {
        QMessageBox::critical(this, "CRITICO", "O cpf esta vazio, e nao tem o numero de digitos");
        //coloco isso para que o cpf apareça somente se estiver direitinho
        cpf="indeterminado";
    }
    //check de genero
    if(!ui->rad_macho->isChecked() && !ui->rad_femea->isChecked()){
        QMessageBox::critical(this, "CRITICO", "O genero nao foi informado");
    }
    //limpando os textos
    ui->edt_cpf->clear();
    ui->edt_idade->clear();
    ui->edt_nome->clear();
    ui->edt_nome->setFocus();

/*
    //isso nao esta sendo efetivo ou funcionando e to com preguiça de arrumar
    if (sexo.isEmpty()) {
        // Está vazio ou nulo
        QMessageBox::critical(this, "CRITICO", "o sexo esta vazio");
    }
*/

    //confirmacao da alteração
    QMessageBox::StandardButton alteracao;
    alteracao = QMessageBox::question(this, "CONFIRMAÇÂO DA ALTERAÇÂO","Deseja alterar?",
        QMessageBox::Ok | QMessageBox::Cancel);

    //se a alteração esta ok
    if(alteracao==QMessageBox::Ok){
        QMessageBox::information(this, "alteracao", "cadastro alterado com sucesso");
    }/*se a */else{
        nome = ui->lbl_nome->text();
        idade = ui->lbl_idade->text().toInt();
        cpf = ui->lbl_cpf->text();
        sexo = ui->lbl_sexo->text();
        QMessageBox::information(this, "alteracao", "cadastro nao alterado");

    }

}


//==BOTÃO DE LIMPEZA DE DADOS==
void MainWindow::on_btn_limpar_clicked()
{
   //aviso para limpeza(escolhas)
    QMessageBox::StandardButton limpeza;
     limpeza = QMessageBox::warning(this, "CONFIRMAÇÂO DA LIMPEZA","DESEJA EXCLUIR CADASTROS?",
     QMessageBox::Ok | QMessageBox::Cancel);


     //aqui é a parte efetiva da escolha

     //se a limpeza for igual a ok
     if (limpeza==QMessageBox::Ok){
         QMessageBox::information(this, "Limpeza de Cadastro", "LIMPEZA DE CADASTRO EFETUADA");
         //limpa o nome para nao aparecer nada
         nome.clear();
         //poderia fazer a mesma coisa que fiz com o nome de limpar
         //mas decidi colocar "nao especificado so pra eu ter de base"
         cpf = "não especificado";
         idade = 0;
         sexo = "inderterminado";

     }/*se nao for ok roda isso ou seja não faz(nada)*/else{
         nome = ui->lbl_nome->text();
         idade = ui->lbl_idade->text().toInt();
         cpf = ui->lbl_cpf->text();
         QMessageBox::information(this, "Limpeza de Cadastro", "Limpeza de cadastro CANCELADA");
     }

}

