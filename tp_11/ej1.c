#include <stdio.h>
#include <assert.h>
#include "../lib/utillist.h"
#include <stdlib.h>

/*
 * Escribir una función recursiva removeIf, que reciba una lista de enteros
 * (de tipo TList) y un puntero a función que reciba un entero y retorne un
 * entero; dicha función se debe aplicar a cada elemento de la lista y
 * eliminar aquellos que cumplan con la condición, esto es, que teniendo como
 * parámetro el valor del nodo, lo elimine si retorna verdadero, y lo
 * conserve si retorna cero. Por ejemplo, si la lista fuera los enteros del 1
 * al 10, y la función recibida retorna 1 (uno) si el número es par, en la
 * lista solo deben quedar los impares.
 */

typedef int (*fnint)(int);

TList removeIf (TList list, fnint f);

int esPar(int n) {
    return n % 2 == 0;
}

int esImpar(int n) {
    return n % 2;
}

int true(int n) {
    return 1;
}

int main(void) {

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v_i[] = {1, 3, 5, 7, 9};
    int v_p[] = {2, 4, 6, 8};
    int p[] = {2, 4, 6, 8, 4, 2, 0, -10};

    TList l1 = fromArray(v, 9);
    l1 = removeIf(l1, esPar);
    assert(checkElems(l1, v_i, 5));
    freeList(l1);

    l1 = fromArray(v, 9);
    l1 = removeIf(l1, esImpar);
    assert(checkElems(l1, v_p, 4));
    freeList(l1);

    l1 = fromArray(v, 9);
    l1 = removeIf(l1, true);
    assert(l1 == NULL);
    freeList(l1);

    l1 = fromArray(p, 8);
    l1 = removeIf(l1, esPar);
    assert(l1 == NULL);
    freeList(l1);

    l1 = fromArray(p, 8);
    l1 = removeIf(l1, esImpar);
    assert(checkElems(l1, p, 8));
    freeList(l1);

    l1 = removeIf(NULL, esImpar);
    assert(l1 == NULL);
    freeList(l1);

    printf("OK!\n");
    return 0;
}

TList removeIf(TList list, fnint f){
    if(list == NULL){
        return NULL;
    }
    if((*f)(list->elem)){
        TList aux = list;
        list = removeIf(list->tail, f);
        free(aux);
        return list;
    }
    list->tail = removeIf(list->tail, f);
    return list;
}