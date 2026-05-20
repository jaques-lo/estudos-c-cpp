/*Leia um ângulo em graus e apresente-o convertido em radianos. A fórmula de
conversão é: R=G*pi/180, sendo G o ângulo em graus, R em radianos e
pi=3.1416.*/
#include<stdio.h>
int main(){
    float pi,r,g;
    pi=3.1416;
    printf("digite o angulo em graus:");
    scanf("%f", &g);
    r=g*pi/180;
    printf("o angulo convertido para radiano: %.5f", r);
return 0;
}
