#include<stdio.h>
/*Leia uma temperatura em graus Fahrenheit e apresente-a convertida em graus
Celsius. A formula de conversão é: C=0.5*(F-32.0)/9.0, sendo C a temperatura
em Celsius e F a temperatura em Fahrenheit.*/

int main(){
    float c,f;
    printf("digite a temperatura em fahrenheint: ");
    scanf("%f", &f);
    c = (f-32.0)*5.0/9.0;
    printf("a temperatura convertida para celsius é: %.2f", c);
return 0;
}
