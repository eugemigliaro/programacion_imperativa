#include <stdio.h>

int main(void){

    int joni;

    printf("ingresá joni: ");
    scanf(" %d", &joni);

    printf("%d\n", joni);

    int a, b, c;
    int maximo;
    printf("Ingrese el valor de A: \n");
    scanf(" %d",&a);
    
    printf("Ingrese el valor de B: \n");
    scanf(" %d",&b);

    printf("Ingrese el valor de C: \n");
    scanf(" %d",&c);

    maximo = a > b ? (a > c ? a : c) : (b > c ? b : c);

    printf("el maximo es: %d\n",maximo);

    return 0;
}