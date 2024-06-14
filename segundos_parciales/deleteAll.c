#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/utillist.h"

/* Escribir una función recursiva deleteAll que reciba como parámetros dos listas de enteros ordenados de forma ascendente (sin repeticiones) y elimine de la primera lista los elementos que se encuentren en la segunda */

TList deleteAll(TList list1, TList list2);

int main(void) {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int w[] = {1, 2, 3, 4};
    TList list1 = fromArray(v, sizeof(v)/sizeof(v[0]));
    TList list2 = fromArray(w, sizeof(w)/sizeof(w[0]));
    TList list3 = deleteAll(list1, list2);
    printf("done\n");

    printf("%p\n", list3);

    TList aux = list3;

    while(aux){
        printf("%d, ", aux->elem);
        aux = aux->tail;
    }
    printf("\n");

    printf("pasó la aserción\n");

    freeList(list3);
    freeList(list1);
    freeList(list2);
    return 0;
}

TList deleteAll(TList list1, TList list2){
    if(!list1){
        return NULL;
    }

    if(!list2 || list1->elem < list2->elem){
        list1->tail = deleteAll(list1->tail, list2);
        return list1;
    }

    if(list1->elem > list2->elem){
        list1->tail = deleteAll(list1, list2->tail);
        return list1;
    }

    printf("got here\n");

    TList aux = list1;
    free(aux);
    list1 = deleteAll(list1->tail, list2->tail);
    return list1;
}