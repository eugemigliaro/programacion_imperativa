#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Escribir la función recursiva recMinMax que reciba un arreglo de enteros
positivos y su dimensión y retorne en dos parámetros de salida el valor
mínimo y el valor máximo del mismo.
Si el arreglo está vacío, tanto el mínimo como el máximo es cero.
Si alguno de los elementos fuera cero o negativo, tanto el mínimo como el
máximo deben valer -1.
No se deben escribir funciones auxiliares. */
 
void recMinMax(const int v[], int dim, int * min, int * max);
 
int 
main(void) {
    int v[] = {3, 1, 5, 2, 6, 99, -3, 2};
    int min, max;
    recMinMax(v, 0, &min, &max);
    assert(min == 0 && max == 0);
    recMinMax(v, 1, &min, &max);
    assert(min == 3 && max == 3);
    recMinMax(v, 2, &min, &max);
    assert(min == 1 && max == 3);
    recMinMax(v, 3, &min, &max);
    assert(min == 1 && max == 5);
    recMinMax(v, 6, &min, &max);
    assert(min == 1 && max == 99);
    recMinMax(v, 8, &min, &max);
    assert(min == -1 && max == -1);
    printf("OK!\n");
    return 0;
}

void recMinMax(const int v[], int dim, int * min, int * max){

    if(dim == 0){
        *min = 0;
        *max = 0;

        return;
    }
    if(v[dim - 1] <= 0){
        *min = -1;
        *max = -1;

        return;
    }
    if(dim == 1){
        *min = v[0];
        *max = v[0];

        return;
    }
    recMinMax(v, dim - 1, min, max);
    if(v[dim - 1] < *min && *min > 0){
        *min = v[dim - 1];
    }
    if(v[dim - 1] > *max && *max > 0){
        *max = v[dim - 1];
    }
}