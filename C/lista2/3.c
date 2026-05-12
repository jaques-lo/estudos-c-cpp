/*Leia um número real. Se o número for positivo imprima a raiz quadrada. Do contrário
imprima o número ao quadrado*/
#include<stdio.h>

int main(){
    double number, raiz, quad;
    printf("digite um numero real:");
    if(scanf("%lf", &number) >= 0){
        raiz =  sqrt(number);
        printf("o numero é real entao a raiz quadrada dele é:%.2lf", raiz);
    }else{
        quad = number * number;
        printf("o numero nao é real entao o quadrado dele é:.2lf", quad);
    }
return 0;
}
