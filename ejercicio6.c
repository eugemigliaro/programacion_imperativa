#include <stdio.h>

int main(void){

    float inp;
    int sum = 0;
    int cifra, ent, dec;
    printf("ingresa un numero, yo sumo los digitos decimales: ");
    scanf(" %f", &inp);
    printf("input %f\n", inp);
    
    ent = inp;
    printf("la parte entera %d\n", ent);
    inp -= ent;
    while(inp - ((int)inp) != 0){
        inp *= 10;
    }
    printf("la parte decimal es %f\n", inp);

    dec = inp;

    while(dec > 0){
        cifra = dec % 10;
        sum += cifra;
        dec /= 10;
    }

    printf("la suma es %d\n", sum);

    return 0;
}