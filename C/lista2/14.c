/*-A nota final de um estudante é calculada a partir de três notas atribuídas entre o
intervalo 0 até 10, respectivamente, a um trabalho de laboratório, a uma avaliação
semestral e a um exame final. A média das três notas mencionadas anteriormente
obedece aos pesos: Trabalho de laboratório: 2; Avaliação Semestre: 3; Exame final:
5. De acordo com o resultado, mostre na tela se o aluno está reprovado (média entre
0 e 2.9), de recuperação (entre 3 e 4.9) ou se foi aprovado. Faça todas as
verificações necessárias.*/
#include<stdio.h>

int main(){
    float n1, n2, n3, media;
    printf("digite as notas do aluno.\n");
    printf("digite a primeira nota (trabalho de laboratorio):");
    scanf("%f", &n1);
    printf("digite a segunda nota(avaliação do semestre):");
    scanf("%f", &n2);
    printf("digite a terceira nota(exame final):");
    scanf("%f", &n3);

    media = ((n1*2)+(n2*3)+(n3*5))/10;
    //validacao
    if(n1 < 0 || n1 > 10 || n2 < 0 || n2 > 10 || n3 < 0 || n3 > 10){
        printf("nota invalida!");
        return 1;
    }
    //notas
    printf("a media do aluno é %.2f\n", media);
    if(media>=5){
        printf("aluno foi aprovado!");
    }else if(media>=3){
        printf("aluno esta de recuperação!");
    }else{
        printf("aluno foi reprovado");

    }
return 0;
}
