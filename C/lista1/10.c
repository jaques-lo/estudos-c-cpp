#include<stdio.h>
/*Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em
km/h (quilômetros por hora). A formula de conversão é: K=M*3.6, sendo K
velocidade em km/h e M em m/s*/
int main(){
    float km,ms;
    printf("digite a velocidade em m/s:");
    scanf("%f", &ms);
    km = ms*3.6;
    printf("a velocidade convertida para km/h é: %.2f", km);
return 0;
}

