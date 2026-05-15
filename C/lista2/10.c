/*Faça um programa que receba a altura e o sexo de uma pessoa, calcule e mostre
seu peso ideal, utilizando as seguintes fórmulas (onde h corresponde à altura): •
Homens: (72.7*h)-58;
• Mulheres: (62.1*h)-44.7;*/
#include<stdio.h>

int main(){
    float h, peso;
    int sexo;
    printf("Digite sua altura(m):");
    scanf("%f", &h);
    printf("Digite seu sexo:\n1-Homens\n2-Mulheres\n");
    scanf("%d", &sexo);

    if(sexo==1){
        //Homens
        peso = (72.7*h)-58;
        printf("o seu peso ideal é igual a: %.2f ", peso);
    }else if(sexo==2){
        //Mulheres
        peso = (62.1*h)-44.7;
        printf("o seu peso ideal é igual a: %.2f", peso);
    }else{
        //indefinido
        printf("GENERO NAO DEFINIDO");
    }


return 0;
}
