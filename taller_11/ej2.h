#ifndef QUEUEADT_H_INCLUDED
#define QUEUEADT_H_INCLUDED

/* crear un ADT que maneje una cola de enteros (queueADT)
Funcionalidades:
Crear instancia: newQueue
Liberar recursos: freeQueue
Cargar elemento: queue
Sacar elemento: dequeue
Saber si está vacía: isEmpty */

typedef int elemType;

typedef struct node{
    elemType data;
    struct node *next;
} tNode;

typedef struct queueCDT *queueADT;

queueADT newQueue(void);
void freeQueue(queueADT q);
void queue(queueADT q, elemType e);
void dequeue(queueADT q, elemType *e);
char isEmpty(queueADT q);

#endif