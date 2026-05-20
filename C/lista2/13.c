/*Faça um algoritmo que calcule a média ponderada das noras de 3 provas. A primeira e a
segunda têm peso 1 e a terceira tem peso 2. Ao final, mostrar a média do aluno e
indicar se o aluno foi aprovado ou reprovado. A nota para aprovação deve ser igual ou
superior a 60 pontos.*/


//primeira por 1, segunda por 1, teceira por 2, divide por 4
#include<stdio.h>
int main(){
    float n1,n2,n3, media;
    printf("digite a nota da primeira prova:");
    scanf("%f", &n1);
    printf("digite a nota da segunda prova:");
    scanf("%f", &n2);
    printf("digite a nota da teceira prova:");
    scanf("%f", &n3);
    media=(n1+n2+(n3*2))/4;
    printf("a media do aluno é %.2f\n", media);
    if(media>=60){
        printf("o aluno foi aprovado!!");
    }else{
        printf("o aluno foi reprovado!!");
    }
return 0;
}
