#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/utillist.h"

/* Realizar una función recursiva depuraLista que recibe una lista de enteros y una función
criterio, y debe eliminar de la lista aquellos nodos cuya información cumplan con el criterio
pedido. La función debe retornar un puntero al primer nodo (que será el mismo si no se tuvo
que borrar el header). */
 
typedef int (*fn) (int);
TList depuraLista(TList, fn);
 
int esImpar(int x) {
    return x % 2;
}
 
int esPositivo(int x) {
    return x > 0;
}
 
int esPar(int x) {
    return !esImpar(x);
}
 
int
main(void) {
    fn f = &esImpar;
    int v1[] = {4,3,7,2,6};
    TList l1 = fromArray(v1, 5);
 
    l1 = depuraLista(l1, f);
    int v1res[] = {4,2,6};
    assert(checkElems(l1, v1res, 3));
    freeList(l1);
 
    TList l2 = fromArray(v1, 5);
    assert(depuraLista(l2, esPositivo) == NULL);
 
    TList l3 = fromArray(v1, 5);
    l3 = depuraLista(l3, esPar);
    int v3res[] = {3,7};
    assert(checkElems(l3, v3res, 2));
    freeList(l3);
 
    printf("OK!\n");
    return 0;
}

TList depuraLista(TList l, fn f) {
    if (l == NULL) {
        return NULL;
    }

    if (!((*f)(l->elem))) {
        l->tail = depuraLista(l->tail, f);
    } else {
        TList aux = l;
        aux = depuraLista(aux->tail, f);
        free(l);
        return aux;
    }
}