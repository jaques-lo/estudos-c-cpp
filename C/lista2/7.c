/*Faça um programa que receba dois números e mostre o maior. Se por acaso, os dois
números forem iguais, imprima a mensagem “números iguais”.*/
#include<stdio.h>
int main(){
    float number, number2;
    printf("digite o primeiro numero:");
    scanf("%f", &number);
    printf("digite o segundo numero:");
    scanf("%f", &number2);
    if (number>number2){
        printf("o numero maior é %.2f", number);
    }else if(number==number2){
        printf("os numeros sao iguais");
    }else{
        printf("o numero maior é %.2f", number2);
    }
return 0;
}
