#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/utillist.h"

/*
    Escribir una función recursiva listUnion que reciba como únicos parámetros
    dos listas ordenadas ascendentemente y retorne una nueva lista con la
    unión de ambas.
*/

TList listUnion  (const TList list1, const TList list2);


int main(void) {

    int v[] = {1, 4, 5, 6, 7, 8};
    int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x[] = {2, 3, 9};

    TList l4 = NULL;
    TList l5 = NULL;
    assert(listUnion(l4, l5) == NULL);
    printf("nice");

    TList l1 = fromArray(v, 6);
    TList l2 = fromArray(w, 9);
    TList l3 = listUnion(l1, l2);
    assert(checkElems(l3, w, 9));
    printf("Prueba 1 OK!\n");
    freeList(l3);

    l3 = listUnion(l2, l1);
    assert(checkElems(l3, w, 9));
    for(TList aux = l3; aux != NULL; aux = aux->tail) {
        printf("%d ", aux->elem);
    }
    printf("Prueba 2 OK!\n");
    freeList(l3);

    l3 = listUnion(l2, l2);
    assert(checkElems(l3, w, 9));
    printf("Prueba 3 OK!\n");
    freeList(l3);

    l3 = listUnion(l2, NULL);
    assert(checkElems(l3, w, 9));
    printf("Prueba 4 OK!\n");
    freeList(l3);

    l3 = listUnion(NULL, l2);
    assert(checkElems(l3, w, 9));
    printf("Prueba 5 OK!\n");
    freeList(l3);
    freeList(l1);
    freeList(l2);

    l1 = fromArray(v, 6);
    l2 = fromArray(x, 3);
    l3 = listUnion(l1, l2);
    freeList(l1);
    freeList(l2);
    assert(checkElems(l3, w, 9));
    printf("Prueba 6 OK!\n");
    freeList(l3);


    printf ("OK!\n");
    return 0;
}

TList listUnion (const TList list1, const TList list2){

    printf("listUnion(list1 = %p, list2 = %p)\n", (void*)list1, (void*)list2);

    if(list1 == NULL && list2 == NULL) {
        printf("  both are NULL, returning NULL\n");
        return NULL;
    }

    TList result = malloc(sizeof(TList));

    if ((list2 == NULL) || (list1 != NULL && list1->elem < list2->elem))  {
        printf("  list1 is not NULL and list2 is NULL or list1->elem (<) list2->elem, returning elem = %d and listUnion(list1->tail, list2)\n", list1->elem);
        result->elem = list1->elem;
        result->tail = listUnion(list1->tail, list2);
    }
    else if ((list1 == NULL) || (list2 != NULL && list1->elem > list2->elem)) {
        printf("  list1 is NULL or list1->elem (>) list2->elem, returning elem = %d and listUnion(list1, list2->tail)\n", list2->elem);
        result->elem = list2->elem;
        result->tail = listUnion(list1, list2->tail);
    }
    else{
    printf("  list1 is not NULL and list1->elem (==) list2->elem, returning elem = %d and listUnion(list1->tail, list2->tail)\n", list1->elem);
    result->elem = list1->elem;
    result->tail = listUnion(list1->tail, list2->tail);
    }
    return result;
}

