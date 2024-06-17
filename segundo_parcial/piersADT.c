#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piersADT.h"

/* tengo que hacer un vector dinámico de puertos
cada puerto tiene un vector dinámico de muelles y la cantidad de muelles, como también la cantidad de barcos (muelles ocupados)
cada muelle tiene que tener un isoccupied
tengo que implementar newPiers, addPierDock, dockShip, shipInDock﻿ */
 
typedef struct dock{
  char exists;
  char isOc;
}tDock;
 
typedef struct pier{
  tDock *dockVec;
  size_t dim;
  size_t cant;
  size_t shipCant;
  char exists;
}tPier;
 
typedef struct piersCDT{
  tPier *pierVec;
  size_t dim;
}piersCDT;
 
static char isPier(piersADT piers, size_t pierNumber){
  if(!(piers->pierVec) || pierNumber >= piers->dim || piers->pierVec[pierNumber].exists == 0){
    printf("el puerto no existe\n");
    return 0;
  }
  return 1;
}
 
static char isDock(piersADT piers, size_t pierNumber, size_t dockNumber){
  if(!(piers->pierVec[pierNumber].dockVec) || dockNumber >= piers->pierVec[pierNumber].dim || piers->pierVec[pierNumber].dockVec[dockNumber].exists == 0){
    return 0;
  }
 
  return 1;
}
 
piersADT newPiers(void){
  piersADT new = calloc(1, sizeof(piersCDT));
  return new;
}

size_t addPier(piersADT piers, size_t pierNumber){
  if(isPier(piers, pierNumber)){
    return 0;
  }

  if(pierNumber >= piers->dim){
    piers->pierVec = realloc(piers->pierVec, (pierNumber + 1) * sizeof(tPier));
    for(size_t i = piers->dim; i <= pierNumber; i++){
      piers->pierVec[i].dim = 0;
      piers->pierVec[i].dockVec = NULL;
      piers->pierVec[i].cant = 0;
      piers->pierVec[i].shipCant = 0;
      piers->pierVec[i].exists = 0;
    }

    piers->dim = pierNumber + 1;
  }

  piers->pierVec[pierNumber].exists = 1;

  return 1;
}
 
size_t addPierDock(piersADT piers, size_t pierNumber, size_t dockNumber){
  if(!isPier(piers, pierNumber) || isDock(piers, pierNumber, dockNumber)){
    return 0;
  }
 
  if(dockNumber >= piers->pierVec[pierNumber].dim){
    piers->pierVec[pierNumber].dockVec = realloc(piers->pierVec[pierNumber].dockVec, (dockNumber + 1) * sizeof(tDock));
    for(size_t i = piers->pierVec[pierNumber].dim; i <= dockNumber; i++){
      piers->pierVec[pierNumber].dockVec[i].exists = 0;
      piers->pierVec[pierNumber].dockVec[i].isOc = 0;
    }
 
    piers->pierVec[pierNumber].dim = dockNumber + 1;
  }
 
  piers->pierVec[pierNumber].dockVec[dockNumber].exists = 1;
  (piers->pierVec[pierNumber].cant)++;
  
  return 1;
}
 
size_t dockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
  if(!isPier(piers, pierNumber) || !isDock(piers, pierNumber, dockNumber) || piers->pierVec[pierNumber].dockVec[dockNumber].isOc == 1){
    return 0;
  }
 
  piers->pierVec[pierNumber].dockVec[dockNumber].isOc = 1;
  (piers->pierVec[pierNumber].shipCant)++;
  return 1;
}
 
int shipInDock(const piersADT piers, size_t pierNumber, size_t dockNumber){
  if(!isPier(piers, pierNumber) || !isDock(piers, pierNumber, dockNumber)){
    return -1;
  }
 
  return piers->pierVec[pierNumber].dockVec[dockNumber].isOc;
}
 
size_t pierShips(const piersADT piers, size_t pierNumber){
  if(!isPier(piers, pierNumber)){
    return -1;
  }
 
  return piers->pierVec[pierNumber].shipCant;
}
 
size_t undockShip(piersADT piers, size_t pierNumber, size_t dockNumber){
  if(!isPier(piers, pierNumber) || !isDock(piers, pierNumber, dockNumber) || piers->pierVec[pierNumber].dockVec[dockNumber].isOc == 0){
    return 0;
  }
 
  piers->pierVec[pierNumber].dockVec[dockNumber].isOc = 0;
  (piers->pierVec[pierNumber].shipCant)--;
  return 1;
}
 
void freePiers(piersADT piers){
  for(size_t i = 0; i < piers->dim; i++){
    free(piers->pierVec[i].dockVec);
  }

  free(piers->pierVec);
  free(piers);
}