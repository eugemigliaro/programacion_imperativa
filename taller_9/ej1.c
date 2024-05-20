#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/utillist.h"

/* Realizar una función recursiva concatenarLista que reciba dos listas y agregue al final de
la primera lista una copia de todos los elementos de la segunda lista. La función debe
retornar el puntero al primer nodo de la lista resultante. No definir funciones ni macros
auxiliares.
La segunda lista no debe ser modificada. */
 
TList concatenarLista(TList, TList);
 
int
main(void) {
    int v1[] = {4,3,7};
    TList l1 = fromArray(v1, 3);
    int v2[] = {3,2,6};
    TList l2 = fromArray(v2, 3);
    int v1yv2[] = {4,3,7,3,2,6};
    TList l1yl2 = concatenarLista(l1, l2);
    assert(checkElems(l1yl2, v1yv2, 6));
    printf("Prueba 1 OK!\n");
    freeList(l1yl2);
    freeList(l2);
 
    TList l3 = NULL;
    TList l4 = fromArray(v1yv2, 6);
    TList l3yl4 = concatenarLista(l3, l4);
    assert(checkElems(l3yl4, v1yv2, 6));
    freeList(l3yl4);
    freeList(l4);
    printf("Todos los tests pasaron!\n");
    printf("OK!\n");
    return 0;
}

TList concatenarLista(TList l1, TList l2) {
    if(l2 == NULL){
        return l1;
    }
    if(l1 == NULL){
        l1 = malloc(sizeof(TNode));
        l1->elem = l2->elem;
        l1->tail = NULL;
        l1->tail = concatenarLista(l1->tail, l2->tail);
    }
    else{
        l1->tail = concatenarLista(l1->tail, l2);
    }
}