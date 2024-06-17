#include <stdio.h>
#include "../lib/utillist.h"
#include <assert.h>
#include <stdlib.h>

/* Escribir una función recursiva sortedList que reciba como único parámetro una lista y
elimine de la misma aquellos elementos que hagan que la lista no esté ordenada en
forma ascendente (cada elemento debe ser menor al siguiente) teniendo en cuenta
que el último elemento está correctamente ubicado (no se lo debe borrar).
La función no debe crear una nueva lista, sino eliminar elementos de la lista recibida. */

TList sortedList(TList list);

int main(void) {
    int v[] = { -10, -5, 0, 5, 10, 15, 20, 25};

    // Test para sortedList
    TList l1 = fromArray(v, 8);
    l1 = sortedList(l1);
    assert(checkElems(l1, v, 8));
    freeList(l1);

    int v2[] = { -10, -5, 0, 5, 10, 15, 20, 5};
    l1 = fromArray(v2, 8);
    l1 = sortedList(l1);
    int v3[] = { -10, -5, 0, 5};
    assert(checkElems(l1, v3, 4));
    l1 = sortedList(l1);
    assert(checkElems(l1, v3, 4));
    freeList(l1);

    int v4[] = { 10, 5, 8, 3, 10, 5, 2, 0};
    l1 = fromArray(v4, 8);
    l1 = sortedList(l1);
    assert(l1->elem==0 && l1->tail==NULL);
    freeList(l1);

    l1 = sortedList(NULL);
    assert(l1==NULL);

    puts("OK sortedList");
    return 0;
}

TList sortedList(TList list){
    if(list == NULL){
        return NULL;
    }
    if(list->tail == NULL){
        return list;
    }
    TList max = sortedList(list->tail);
    if(list->elem >= max->elem){
        free(list);
        return max;
    }
    list->tail = max;
    return list;
}

TList sortedListBeginning(TList list){
    if(list == NULL){
        return NULL;
    }
    if(list->tail != NULL && list->elem >= list->tail->elem){
        TList aux = list->tail->tail;
        free(list->tail);
        list->tail = aux;
        list->tail = sortedListBeginning(list);
        return list;
    }

    list->tail = sortedListBeginning(list->tail);
    return list;
}