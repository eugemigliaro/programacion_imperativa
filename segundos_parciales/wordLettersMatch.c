#include <stdio.h>
#include <stdlib.h>
#include "../lib/utillist.h"

/* Escribir una función recursiva wordLettersMatch que reciba únicamente dos parámetros,
una lista de caracteres y una string, retorna la cantidad de coincidencias que hay entre
los primeros caracteres del string y los primeros de la lista */

int wordLettersMatch(TList list, char * word);

int main(void) {
    int v[] = {'h', 'o', 'l', 'a'};
    TList list = fromArray(v, sizeof(v)/sizeof(v[0]));
    char * word = "hoa";
    printf("%d\n", wordLettersMatch(list, word));//en este caso tiene que ser 4
    freeList(list);
    return 0;
}

int wordLettersMatch(TList list, char * word) {
    if (list == NULL || word == NULL)
        return 0;
    if (list->elem == word[0])
        return 1 + wordLettersMatch(list->tail, word + 1);
    else
        return 0;
}