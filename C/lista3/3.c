/*Faça um algoritmo utilizando o comado while que mostra uma contagem
regressiva na tela, iniciando em 10 e terminando em 0. Mostrar uma mensagem
FIM! Após a contagem;*/
#include<stdio.h>
int main(){
    printf("---ALGORITIMO DE CONTAGEM REGRESSIVA---");
    int contagem=10;
    while(contagem>-1){
        printf("\n\t\t%d", contagem);
        contagem--;
    }
return 0;
}
