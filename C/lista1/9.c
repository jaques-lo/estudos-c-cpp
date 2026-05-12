#include<stdio.h>
/*Leia uma velocidade em km/h (quilômetros por hora) e apresente-a convertida
em m/s (metros por segundo). A formula de conversão é: M=K/3.6, sendo K a
velocidade em km/h e M em m/s.*/
int main(){
    float km,ms;
    printf("digite a velocidade em km/h:");
    scanf("%f", &km);
    ms = km/3.6;
    printf("a velocidade convertida para m/s é: %.2f", ms);
return 0;
}
