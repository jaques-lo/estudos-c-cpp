/*Leia o salário de um trabalhador e o valor da prestação de um empréstimo. Se a
prestação for maior que 20 % do salário imprima: Empréstimo não concedido, caso
contrário imprima: Empréstimo concedido.*/
#include<stdio.h>
int main(){
    float salario, emprestimo, prestacao, meses, vintepc;
    printf("digite o seu salario:");
    scanf("%f", &salario);
    printf("digite o valor do emprestimo que voce deseja:");
    scanf("%f", &emprestimo);
    printf("digite em quantos meses pretende pagar sem juros:");
    scanf("%f", &meses);

    prestacao = emprestimo/meses;
    vintepc = salario * 0.2;

    if(prestacao>vintepc){
        printf("emprestimo no concedido");
        return 0;
    }else{
        printf("PARABENS, GANHOU SEU EMPRESTIMO\n");
        printf("o valor da prestação a pagar por mes é: %f", prestacao);
    }


return 0;
}
