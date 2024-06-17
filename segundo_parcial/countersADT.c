#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countersADT.h"

/* tengo que hacer un vector dinámico de counters
cada counter es una cola (fifo)
no hace falta chequear que un pasajero no esté en un mostrador para agregarlo a la cola, se pueden repetir
nombres de pasajeros cortos, para guardarlos hago malloc con strlen y strcpy
puede pasar que me den un counterNumber inválido o un maxCounters inválido
dentro de la lista que es la cola de cada mostrador tengo un iterador
la funcion checkInCounters popea al primero de cada cola de mostrador
tengo que implementar newCounters, enterCounter, toBeginByCounter, checkInCounters﻿﻿﻿﻿﻿ */
 
#define BLOCK 100
 
typedef struct pNode{
  char *name;
  unsigned int len;
  struct pNode *next;
}tPNode;
 
typedef struct counter{
  tPNode *first, *last, *current;
  size_t cant;
}tCounter;
 
typedef struct countersCDT{
  tCounter *counterVec;
  size_t dim;
}countersCDT;
 
static void pushPassenger(tCounter *counter, tPNode *new){
  if(counter->first == NULL){
    counter->first = new;
    counter->last = new;
  }
  else{
    counter->last->next = new;
    counter->last = new;
  }
  
  (counter->cant)++;
}
 
static tPNode *popPassenger(tCounter *counter){
  if(counter->first == NULL){
    return NULL;
  }
 
  tPNode *ans = counter->first;
  counter->first = counter->first->next;
  ans->next = NULL;
 
  (counter->cant)--;
  
  return ans;
}
 
countersADT newCounters(size_t maxCounters){
  if(!maxCounters){
    return NULL;
  }
  
  countersADT new = calloc(1, sizeof(countersCDT));
  new->counterVec = calloc(maxCounters, sizeof(tCounter)); //ahora ya tengo todos los punteros a nodos de cada counter igualados a NULL
  new->dim = maxCounters;
 
  return new;
}
 
void enterCounter(countersADT counters, size_t counterNumber, const char *passenger){
  if(counterNumber >= counters->dim){
    return;
  }
 
  tPNode *new = malloc(sizeof(tPNode));
  new->len = strlen(passenger);
  new->name = malloc((new->len) * sizeof(char));
  strcpy(new->name, passenger);

  new->next = NULL;
 
  pushPassenger(&(counters->counterVec[counterNumber]), new);
}
 
void toBeginByCounter(countersADT counters, size_t counterNumber){
  counters->counterVec[counterNumber].current = counters->counterVec[counterNumber].first;
}

size_t hasNextByCounter(const countersADT counters, size_t counterNumber){
  if(counters->counterVec[counterNumber].current == NULL){
    return 0;
  }
  return 1;
}

const char * nextByCounter(countersADT counters, size_t counterNumber){
  if(!hasNextByCounter(counters, counterNumber)){
    return NULL;
  }
  const char *ans = counters->counterVec[counterNumber].current->name;
  counters->counterVec[counterNumber].current = counters->counterVec[counterNumber].current->next;
  return ans;
}
 
struct checkInResult * checkInCounters(countersADT counters, size_t * checkInResultDim){
  size_t i = 0;
  size_t aux = 0;
  *checkInResultDim = 0;
 
  struct checkInResult *ans = NULL;
  
  for(i; i < counters->dim; i++){
    if(aux % BLOCK == 0){
      ans = realloc(ans, (aux + BLOCK) * sizeof(struct checkInResult));
    }
 
    tPNode *popped = popPassenger(&(counters->counterVec[i]));
    if(popped){
      ans[aux].counterNumber = i;
      ans[aux].checkedInPassenger = popped->name;
      ans[aux].waitingPassengers = counters->counterVec[i].cant;
      aux++;
    }
  }
  
  (*checkInResultDim) = aux;
  if(!aux){
    free(ans);
    return NULL;
  }
  return ans;
}