/*Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em
km/h (quilômetros por hora). A formula de conversão é: K=M*3.6, sendo K
velocidade em km/h e M em m/s.*/
#include<stdio.h>

int main(){
    float ms, km;
    printf("digite a velocidade em m/s:");
    scanf("%f", &ms);
    km = ms*3.6;
    printf("a velocidade de m/s convertida para km/h é:%.2f", km);

return 0;
}
