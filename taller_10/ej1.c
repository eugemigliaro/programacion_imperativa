#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../lib/utillist.h"

#define BLOCK 100

/* Realizar una función recursiva strToListUpper que reciba una cadena terminada en ‘\0’ y
pase a una lista sólo las letras mayúsculas.
La función debe retornar el puntero al primer nodo de la lista resultante. No definir
funciones ni macros auxiliares.
Definir también una función showListStr para mostrar la lista resultante. */

char *listToString(TList);

void freeList(TList);

TList strToListUpper(const char *);
void showListStr(TList);

int main()
{
    TList aux = strToListUpper("AbCdEfG");
    char *strList = listToString(aux);
    assert(!strcmp(strList, "ACEG"));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper("");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper("Hoy vinimos a ver a Messi al Monumental");
    strList = listToString(aux);
    assert(!strcmp(strList, "HMM"));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper("no va a quedar ninguna porque son todas minusculas");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper(NULL);
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper("solo van a quedar las siguientes letras ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strList = listToString(aux);
    assert(!strcmp(strList, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    showListStr(aux);
    freeList(aux);
    free(strList);

    puts("OK!");
}

TList strToListUpper(const char *s) {
    if(s == NULL || s[0] == '\0') {
        return NULL;
    }

    if(s[0] >= 'A' && s[0] <= 'Z'){
        TList ans = malloc(sizeof(TNode));
        ans->elem = s[0];
        ans->tail = strToListUpper(s + 1);
        return ans;
    }

    return strToListUpper(s + 1);
}

void showListStr(TList l) {
    for(TList aux = l; aux != NULL; aux = aux->tail) {
        printf("%c ", aux->elem);
    }
    printf("\n");
}

char *listToString(TList l)
{
    TList aux = l;
    char *s = NULL;
    int i = 0;
    while (aux != NULL)
    {
        if (i % BLOCK == 0)
            s = realloc(s, i + BLOCK);
        s[i] = aux->elem;
        aux = aux->tail;
        i++;
    }
    s = realloc(s, i + 1);
    s[i] = 0;
    return s;
}

void freeList(TList l)
{
    if (l != NULL)
    {
        freeList(l->tail);
        free(l);
    }
}