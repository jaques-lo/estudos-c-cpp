/*Faça um programa que leia um número e, caso seja positivo, calcule e mostre:
• O número digitado ao quadrado;
• A raiz quadrada do número;*/
#include<stdio.h>
#include<math.h>
int main(){
    double number;
    printf("Digite o numero que deseja:");
    scanf("%lf", &number);
    if(number>0){
        double quadrado, raiz;
        quadrado = number * number;
        printf("o numero digitado ao quadrado é: %.2lf\n", quadrado);
        raiz = sqrt(number);
        printf("a raiz do numero digitado é: %.2lf\n", raiz);
    }

return 0;
}
