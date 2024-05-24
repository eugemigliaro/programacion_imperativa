#include <stdio.h>
#include "../lib/utillist.h"
#include <assert.h>
#include <stdlib.h>

/* Realizar una función recursiva subList que reciba una lista y dos valores enteros from y to
y retorne una nueva sublista que contenga los elementos ubicados entre from y to
inclusive, considerando que el primer elemento es el elemento 0 (cero).
La función debe retornar el puntero al primer nodo de la lista resultante.
No usar funciones ni macros auxiliares.
Se asegura que la función se invoca con valores correctos de from y to.
Asumir que hay memoria suficiente para la nueva lista (no hace falta validar el malloc) */

TList subList(TList list, int from, int to);

int main(void) {
    int v[] = { -10, -5, 0, 5, 10, 15, 20, 25};
    // Test para subList
    TList l1 = fromArray(v, 0);
    assert(subList(l1, 0, 10)==NULL);
    assert(subList(l1, 1, 2)==NULL);
    assert(subList(l1, 0, 0)==NULL);

    // Un solo elemento
    l1 = fromArray(v, 1);
    TList l2 = subList(l1, 0, 10);
    assert(checkElems(l2, v, 1));
    freeList(l2);
    l2 = subList(l1, 1, 3);
    assert(l2==NULL);
    l2 = subList(l1, -1, 0);
    assert(l2==NULL);

    freeList(l1);
    l1 = fromArray(v, 8);
    l2 = subList(l1, 0, 10);
    assert(checkElems(l2, v, 8));
    freeList(l2);
    l2 = subList(l1, 1, 3);
    assert(checkElems(l2, v+1, 3));
    freeList(l2);
    l2 = subList(l1, 7, 10);
    assert(checkElems(l2, v+7, 1));
    freeList(l2);

    freeList(l1);
    puts("OK subList");
}

TList subList(TList list, int from, int to){
    if(list == NULL || to < from){
        return NULL;
    }
    if(from == 0){
        TList aux = malloc(sizeof(TNode));
        aux->elem = list->elem;
        aux->tail = subList(list->tail, from, to-1);
        return aux;
    }
    if(from > 0){
        return subList(list->tail, from-1, to-1);
    }

}