#include <stdlib.h>
#include <stdio.h>

#include "dataADT.h"

typedef int (*compfn)(elemtype, elemtype);
 
typedef struct elemNode{
  elemType data;
  struct elemNode *next;
}tNode;
 
typedef struct dataCDT{
  tNode *elements;
  size_t cant;
  compfn cmp;
}dataCDT;
 
static tNode *insertNode(compfn cmp, tNode *list, tNode *new){
  if(!list || cmp(new->data, list->data) < 0){
    new->next = list;
    return new;
  }
 
  list->next = insertNode(cmp, list->next, new);
  return list;
}
 
dataADT newData(compfn cmp){
  dataADT new = calloc(1, sizeof(dataCDT));
  new->cmp = cmp;
  return new;
}
 
int addElement(dataADT data, elemType elem){
  if(isElement(data, elem)){
    return 0;
  }
  
  tNode *new = malloc(sizeof(tNode));
  new->data = elem;
  new->next = NULL;
 
  data->elements = insertNode(data->cmp, data->elements, new);
}
 
static tNode * deleteElemRec(compfn cmp, tNode *list, elemType elem){
  if(!list){
    return NULL;
  }
  if(cmp(list->data, elem) == 0){
    tNode *aux = list;
    free(aux);
    return list->next;
  }
  
  list->next = deleteElemRec(cmp, list->next, elem);
}
 
int deleteElement(dataADT data, elemType elem){
  if(!isElement(data, elem)){
    return 0;
  }
 
  deleteElemRec(data->cmp, data->elements, elem);
  return 1;
}
 
//no me alcanza el tiempo para implementar la ultima funcion, pero como ya estoy añadiendo elementos en orden ascendente debería ser simple