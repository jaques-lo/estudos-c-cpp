/*faça um programa que receba dois números e mostre qual deles é o maior*/
#include<stdio.h>

int main(){
    float n1,n2;
    printf("escreva o primeiro numero:");
    scanf("%f", &n1);
    printf("escreva o segundo numero:");
    scanf("%f", &n2);
    if(n1>n2){
        printf("o numero maior é o primeiro numero: %.2f", n1);
    }else{
        printf("o numero maior é o segundo numero: %.2f", n2);
    }

return 0;
}
