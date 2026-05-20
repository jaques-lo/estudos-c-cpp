/*Leia uma distância em milhas e apresente-a convertida em quilômetros. A fórmula
de conversão é: K=1.61*M, sendo K a distância em quilômetros e M em milhas.*/
#include<stdio.h>

int main(){
    float milhas, km;
    printf("Digite as milhas:");
    scanf("%f", &milhas);
    km=1.61*milhas;
    printf("A distancia em quilometros é: %.2f", km);
return 0;
}
