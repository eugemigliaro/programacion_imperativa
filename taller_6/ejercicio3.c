#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main(void){
    /* Implementar un programa que lea de la entrada estándar hasta EOF y genere elsupervector que todo lo puede guardar.
    Luego imprimir el contenido del vector ensalida estandar. */

    char c;
    char *supervec = NULL;
    int dim = 0;
    while((c = getchar()) != EOF){
        if(dim % TAM == 0){
            supervec = realloc(supervec, (dim + TAM) * sizeof(char));
        }
        supervec[dim] = c;
        dim++;
    }

    for(int i = 0; i < dim; i++){
        printf("%c", supervec[i]);
    }

    return 0;
}