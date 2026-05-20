/*Ler um número inteiro. Se o número lido for negativo, escreva a mensagem “Número
inválido”. Se o número for positivo, calcular o logaritmo deste número.*/
#include<stdio.h>
#include<math.h>
int main(){
    int number;
    double resultado;
    printf("Digite um numero:");
    scanf("%d", &number);
    if(number<0){
        printf("numero invalido");
    }else{
        resultado = log10(number);
        printf("O logaritimo de %d na base 10 =  %.2lf", number, resultado);

    }
return 0;
}
