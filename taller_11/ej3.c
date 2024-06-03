#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ej2.h"
#include "ej3.h"

struct queueCDT{
    tNode *first;
    tNode *actual;
    tNode *last;
};

queueADT newQueue(){
    queueADT ans = calloc(1, sizeof(struct queueCDT));
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

/* ahora se definen nuevas funciones para iterar sobre la cola */

void toBegin(queueADT q){
    q->actual = q->first;
}

int hasNext(queueADT q){
    return q->actual != NULL;
}

elemType next(queueADT q){
    elemType ans = q->actual->data;
    q->actual = q->actual->next;
    return ans;
}

int main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    toBegin(q);
    assert(hasNext(q) && next(q) == 5);
    assert(hasNext(q) && next(q) == 9);
    assert(hasNext(q) && next(q) == 3);
    assert(hasNext(q) == 0);
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
    toBegin(q);
    assert(hasNext(q) == 0);
    freeQueue(q);
    printf("OK!\n");
    return 0;
}