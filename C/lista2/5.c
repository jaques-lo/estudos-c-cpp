/*Faça um programa que receba um número inteiro e verifique se este número é par ou
ímpar.*/
#include<stdio.h>
int main(){
    int number ;
    printf("digite um numero inteiro:");
    scanf("%d", &number);
    if (number%2 ==0){
        //caso o resto seja 0 o numero é par!
        printf("o numero %d é par!", number);
    }else{
        printf("o numero é impar");
    }
return 0;
}
