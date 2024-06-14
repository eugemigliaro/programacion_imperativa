#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "museumTicketADT.h"

#define BLOCK 10

/* Se desea implementar un TAD para la venta de tickets para un museo, que permita
saber cuántos tickets hay por día y por año, como así también obtener los nombres de las
personas que reservaron tickets para un día determinado. Cada día se identifica por el orden
dentro del año, al primero de enero le corresponde 1, al 2 de enero 2, al 1 de febrero 32, etc.

Entonces ya sé que voy a tener que usar un vector estático para los días,
después cada uno apunta a un vector dinámico de tickets
en cada ticket guardo la información del día y el nombre de la persona
el orden de los tickets por ahora no está especificado
asumo que el año es siempre biciesto

Voy a hacer listas para ordenar los visitors alfabéticamente en cada día

Cada struct de día tiene su propio iterador */

typedef struct visitorNode{
    char *name;
    size_t len;
    struct visitorNode *next;
}tVisitorNode;

/* struct de día, con pointer a la lista de nombres e iterador */

typedef struct dia{
    tVisitorNode *visitors;
    tVisitorNode *current;
    size_t cantVisit;
}tDia;

/* yo haría un vector de pointers a structs de dia, esto en el struct de museumCDT */

typedef struct museumTicketCDT{
    tDia *dias[366];
}museumTicketCDT;

static char *strtoptr(const char *s, size_t *len){
    char *ans = NULL;

    size_t i = 0;

    for(i; s[i]; i++){
        if(i % BLOCK == 0){
            ans = realloc(ans, (i + BLOCK) * sizeof(char));
        }

        ans[i] = s[i];
    }

    ans[i] = '\0';

    *len = i;

    return ans;
}

static tVisitorNode *findVisitor(tDia *dia, const char *name){
    tVisitorNode *aux = dia->visitors;
    int comparacion;
    char flag = 1;
    
    while(aux && flag){
        comparacion = strcasecmp(name, aux->name);

        if(comparacion == 0){
            flag = 0;
        }

        else if(comparacion < 0){
            aux = NULL;
        }

        else{
            aux = aux->next;
        }
    }

    return aux;
}

static char validDay(size_t day){
    return (day >= 1 && day <= 366);
}

static tVisitorNode *insertTicketRec(tVisitorNode *lista, tVisitorNode *new){
    if(!lista || strcasecmp(new->name, lista->name) < 0){
        new->next = lista;
        return new;
    }

    lista->next = insertTicketRec(lista->next, new);
    return lista;
}

museumTicketADT newMuseumTicket(void){
    museumTicketADT new = calloc(1, sizeof(museumTicketCDT));

    for(int i = 0; i < 366; i++){
        new->dias[i] = calloc(1, sizeof(tDia));
    }

    return new;
}

int addTicket(museumTicketADT mt, size_t dayOfYear, const char * visitor){
    if(!validDay(dayOfYear) || mt == NULL || visitor == NULL || findVisitor(mt->dias[dayOfYear - 1], visitor)){
        return 0;
    }

    tVisitorNode *new = calloc(1, sizeof(tVisitorNode));
    new->name = strtoptr(visitor, &(new->len));
    mt->dias[dayOfYear - 1]->visitors = insertTicketRec(mt->dias[dayOfYear - 1]->visitors, new);
    (mt->dias[dayOfYear - 1]->cantVisit)++;

    return (mt->dias[dayOfYear - 1]->cantVisit);
}

int dayTickets(const museumTicketADT mt, size_t dayOfYear){
    if(!validDay(dayOfYear) || !mt){
        return -1;
    }

    return mt->dias[dayOfYear - 1]->cantVisit;
}

int yearTickets(const museumTicketADT mt){
    if(!mt){
        return -1;
    }

    size_t suma = 0;

    for(int i = 0; i < 366; i++){
        suma += mt->dias[i]->cantVisit;
    }

    return suma;
}

void toBeginByDay(museumTicketADT mt, size_t dayOfYear){
    if(!mt || !validDay(dayOfYear)){
        return;
    }

    mt->dias[dayOfYear - 1]->current = mt->dias[dayOfYear - 1]->visitors;
    return;
}

size_t hasNextByDay(museumTicketADT mt, size_t dayOfYear){
    if(!mt || !validDay(dayOfYear)){
        return 0;
    }

    return (mt->dias[dayOfYear - 1]->current->next != NULL);
}

char * nextByDay(museumTicketADT mt, size_t dayOfYear){
    if(hasNextByDay(mt, dayOfYear)){
        tVisitorNode *aux = mt->dias[dayOfYear - 1]->current;
        mt->dias[dayOfYear - 1]->current = mt->dias[dayOfYear - 1]->current->next;
        return aux->name;
    }
    else{
        return mt->dias[dayOfYear - 1]->current->name;
    }
}

void freeDay(tDia *dia){
    while(dia->visitors){
        tVisitorNode *aux = dia->visitors;
        dia->visitors = dia->visitors->next;
        free(aux->name);
        free(aux);
    }

    return;
}

void freeMuseumTicket(museumTicketADT mt){
    for(int i = 0; i < 366; i++){
        if(mt->dias[i]){
            freeDay(mt->dias[i]);
        }
    }

    free(mt);
}