#include <stdio.h>

int main(void){

    int numero;
    printf("Ingresá un numero: ");
    scanf(" %d", &numero);

    int respuesta = (numero >= 0 && numero <= 15) ? (numero <= 9 ? numero + '0' : (numero - 10) + 'A') : numero;

    printf(" %c\n", respuesta);

    return 0;
}