#include <stdio.h>
#include <stdlib.h>
#include "../utillist.h"

int main(void){

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    TList list = fromArray(array, 10);
    TList aux = list;

    while(aux != NULL){
        printf("%d ", aux->elem);
        aux = aux->tail;
    }

    return 0;
}