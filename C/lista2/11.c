/*Escreva um programa que leia um número inteiro maior que zero e devolva, na tela,
a soma de todos os seus algarismos. Por exemplo, ao número 251 corresponderá o
valor 8 (2+5+1). Se o número lido não for maior que zero, o programa terminará com
a mensagem “Número inválido”*/
#include<stdio.h>

int main(){
    int number, soma;
    printf("escreva um numero inteiro maior que zero:");
    scanf("%d", &number);
    if(number<=0){
        printf("Numero Invalido!!");
    }else{
        while(number>0){
            soma+=number%10;
            number=number/10;
        }
        printf("a soma dos algarismos é %d", soma);
    }
return 0;
}
