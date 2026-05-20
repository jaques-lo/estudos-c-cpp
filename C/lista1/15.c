/* 15.Leia um ângulo em radianos e apresente-o convertido em graus. A
fórmula de conversão é: G=R*180/pi, sendo G o ângulo em graus, R em radianos*/
#include<stdio.h>
int main(){
    float pi, r, g;
    pi=3.1416;
    printf("Digite o angulo desejado em radiano:");
    scanf("%f", &r);
    g=r*180/pi;
    printf("a conversao é: %.5f", g);
return 0;
}
