#include <stdio.h>
#include <stdlib.h>

char nuevo_repetido(int *arr, int dim, int nuevo){
    for(int i = 0; i < dim; i++){
        if(arr[i] == nuevo){
            return 1;
        }
    }

    return 0;
}

int *cargarNumeros(int *dim){

/* Hacer una función que lea números enteros de entrada estándar (los lee con getint) y los
guarde en un arreglo. El arreglo debe crecer a medida que se necesita.
La carga en el arreglofinaliza cuando un valor se repite por primera vez. */
    
    int *arr;
    int i;
    char same = 0;
    *dim = 0;
    arr = (int *)malloc(sizeof(int));

    while(!same) {
        scanf(" %d", &i);
        same = nuevo_repetido(arr, *dim, i);
        if(!same){
            arr = (int *)realloc(arr, (*dim + 1) * sizeof(int));
            arr[*dim] = i;
            (*dim)++;
        }   
    }

    return arr;
}

int main(void) {
    int dim;
    int *arr;

    arr = cargarNumeros(&dim);

    for (int i = 0; i < dim; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
