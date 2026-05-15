/*Faça um programa que leia 2 notas de um aluno, verifique se as notas são válidas e
exiba na tela a média destas notas. Uma nota válida deve ser, obrigatoriamente, um
valor entre 0.0 e 10.0, onde caso a nota possua um valor válido, este fato deve ser
informado ao usuário e o programa termina.*/

#include<stdio.h>
int main(){
    float nota1,nota2, media;
    printf("digite a primeira nota de 0.0 a 10.0:");
    scanf("%f", &nota1);
    if (nota1>10.0 || nota1<0.0){
        printf("nota invalida!!");
        return 0;
    }
    printf("digite a segunda nota de 0.0 a 10.0:");
    scanf("%f", &nota2);
    if(nota2>10.0 || nota2<0.0){
        printf("nota invalida!!");
        return 0;
    }

    media = (nota1+nota2) /2;
    printf("a media dessas notas é: %.2f\n", media);
    //eu coloco essa \n no final pra fica bonito
return 0;
}
