/*Escreva um programa que, dados dois inteiros, mostre na tela o maior deles, assim
como a diferença existente entre ambos.*/
#include<stdio.h>
int main(){
    int number, number2;
    int dif;
    printf("vamos descobrir qual numero é maior e qual a diferença deles!!");
    printf("\ndigite o primeiro numero inteiro:");
    scanf("%d", &number);
    printf("digite o segundo numero inteiro:");
    scanf("%d", &number2);
    if (number>number2){
        dif = number - number2;
        printf("\no numero maior é o primeiro digitado %d\na diferença é: %d\n", number, dif);
    }else{
        dif = number2-number;
        printf("\no numero maior é o segundo digitado %d\na diferença é: %d\n", number2, dif);
    }
return 0;
}
