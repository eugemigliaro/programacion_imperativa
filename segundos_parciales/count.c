#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../lib/utillist.h"

int wordLettersMatch(TList list, char *word){
    if(list==NULL || word==0) {return 0;}
    if(list->elem == *word){
        return 1 + wordLettersMatch(list->tail, word+1);
    }
    return 0; //si ya uno no coincide, no sigo
}

void count(char *vec, int *pares, int *impares){
    if(*vec == 0) {return;}
    if(!isdigit(*vec)){
        count(vec+1, pares, impares);
        
    }
    else if((*vec - '0') % 2 ==0){
        (*pares)++;
        count(vec+1, pares, impares);
    }
    else {
        (*impares)++;
        count(vec+1, pares, impares);
    }
    return;
}

int main(void){
    int pares=0, impares=0;
    char *vec = "hola0123456789";
    count(vec, &pares, &impares);
    printf("Hay %d pares y %d impares\n", pares, impares);
    return 0;
}