#include<stdio.h>

int main(){
    float k,c;
    printf("digite a temperatura em kelvin: ");
    scanf("%f", &k);
    c = k-273.15;
    printf("a temperatura em graus celsius é de: %.2f", c);
return 0;
}
