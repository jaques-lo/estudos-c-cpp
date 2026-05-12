/*Leia um número fornecido pelo usuário. Se esse número for positivo, calcule a raiz quadrada
do número. Se o número for negativo, mostre uma mensagem dizendo número é
inválido*/
#include<stdio.h>
#include <math.h>

int main(){
    double number, raiz;
    printf("digite um numero:");
    scanf("%lf", &number);

    if (number>=0){
        raiz =  sqrt(number);
        printf("a raiz quadrada do numero é: %.2lf\n", raiz);
    }else{
        printf("O numero é invalido!!!\n");
    }
return 0;
}
