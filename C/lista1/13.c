/*Leia uma distância em quilômetros e apresente-a em milhas. A formula de
conversão é: M=k/1.61, sendo K a distância em quilômetros e M em milhas.*/
#include<stdio.h>
int main(){
    float km,milhas;
    printf("Digite a distancia em quilometros:");
    scanf("%f", &km);
    milhas=km/1.61;
    printf("A distancia convertida em milhas é %.2f.", milhas);
return 0;
}
