#include<stdio.h>
/*Leia uma temperatura em graus Celsius e apresente-a convertida em graus
Fahrenheit. A fórmula de conversão é: F=C*(9.0/5.0)+32.0, sendo F a temperatura
em Fahrenheit e C a temperatura em Celsius.*/

int main(){
    float c,f;
    printf("digite uma temperatura em graus celsius: ");
    scanf("%f", &c);
    f = c*(9.0/5.0)+32.0;
    printf("a temperatura convertida é: %.2f",f);

return 0;
}
