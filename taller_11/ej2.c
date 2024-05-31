#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ej2.h"

struct queueCDT{
    tNode *first;
    tNode *last;
};

queueADT newQueue(){
    queueADT ans = malloc(sizeof(struct queueCDT));
    ans->first = NULL;
    ans->last = NULL;
    return ans;
}

void freeQueue(queueADT q){
    tNode *aux;
    while(q->first != NULL){
        aux = q->first;
        q->first = q->first->next;
        free(aux);
    }
    free(q);
}

void queue(queueADT q, elemType e){
    tNode *aux = malloc(sizeof(tNode));
    aux->data = e;
    aux->next = NULL;
    if(q->first == NULL){
        q->first = aux;
    }else{
        q->last->next = aux;
    }
    q->last = aux;
}

void dequeue(queueADT q, elemType *e){
    tNode *aux = q->first;
    if(q->first == q->last || q->first == NULL){
        q->first = NULL;
        q->last = NULL;
    }else{
        q->first = q->first->next;
    }
    *e = aux->data;
    free(aux);
}

char isEmpty(queueADT q){
    return q->first == NULL;
}

int
main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    int aux;
    dequeue(q, &aux);
    assert(aux == 5);
    dequeue(q, &aux);
    assert(aux == 9);
    queue(q, 1);
    dequeue(q, &aux);
    assert(aux == 3);
    dequeue(q, &aux);
    assert(aux == 1);
    assert(isEmpty(q) == 1);
    freeQueue(q);
    printf("OK!\n");
    return 0;
}