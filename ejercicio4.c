#include <stdio.h>
#include <math.h>
#include "getnum.h"

//un programa que tome por input los coeficientes de una cuadrática e imprima la solución, tira error si es cuadrática y avisa si tiene raíces complejas

float raiz(int a, int b, int c, int op){
    int prim = ( -1 * b )/( 2 * a );
    if(op == 1){
        return (float) (prim + sqrt(b * b - 4 * a * c) / (2 * a));
    }
    else if(op == 2){
        return (float) (prim - sqrt(b * b - 4 * a * c) / (2 * a));
    }
    else if(op == 0){
        return (float)prim;
    }
}

int main(void){

    int a, b, c, disc;
    float r1, r2;

    a = getint("introduzca el coeficiente principal: ");

    if(a == 0){
        printf("\nLa ecuacion no es una ecuacion cuadratica\n");
        return 1;
    }

    b = getint("introduzca el coeficiente lineal: ");

    c = getint("introduzca el coeficiente independiente: ");

    disc = b * b - 4 * a * c;

    if(disc < 0){
        printf("la ecuacion no tiene raices reales");
        return 1;
    }
    else if(disc==0){
        r1 = raiz(a, b, c, 0);
        printf("la ecuacion tiene una solucion real: %f",r1);
    }
    else{
        r1 = raiz(a, b, c, 1);
        r2 = raiz(a, b, c, 2);
        printf("las soluciones de la ecuacion son: %.3f y %.3f",r1,r2);
    }

    return 0;
}