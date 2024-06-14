#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "landmarkADT.h"
#define BLOCK 100

/* un landmarkADT es una colección de landmarks, hago un vector dinámico de sites */

typedef struct site{
    landmarkType elem;
    size_t dist;
    size_t nBlock;
    char isOc;
}tSite;

typedef struct landmarkCDT{
    tSite *sites;
    size_t cant;
    size_t dim;
    comparefn cmp;
}landmarkCDT;

static tSite *findSite(landmarkADT lm, tSite site){
    for(size_t i = 0; i < lm->dim; i++){
        if(lm->sites[i].isOc && lm->cmp(lm->sites[i].elem, site.elem) == 0){
            return &(lm->sites[i]);
        }
    }

    return NULL;
}

/**
* Crea una nueva colección de sitios de interés. Sólo se registrará un sitio cada
* 100 metros (uno entre los 0 y 99 metros, posiblemente otro entre los 100 y 199, etc.)
*/
landmarkADT newLandmark(comparefn cmp){
    landmarkADT new = calloc(1, sizeof(landmarkCDT));
    new->cmp = cmp;
    return new;
}
/**
* Agrega un punto de interés #site a #meters metros del origen. Si ya había
* un sitio, sólo queda #site (ver programa de testeo)
*/
void addLandmark(landmarkADT landmark, size_t meters, landmarkType site){
    size_t block = meters / BLOCK;

    tSite new = {.elem = site, .dist = meters, .nBlock = block};

    if(block + 1 > landmark->dim){
        landmark->sites = realloc(landmark->sites, (block + 1) * sizeof(tSite));
        for(size_t i = landmark->dim; i < block + 1; i++){
            landmark->sites[i].isOc = 0;
        }

        landmark->dim = block + 1;
    }

    if(landmark->sites[block].isOc == 0){
        landmark->cant++;
        printf("bloque n %d, cantidad %d\n", block, landmark->cant);
    }

    landmark->sites[block].elem = new.elem;
    landmark->sites[block].dist = new.dist;
    landmark->sites[block].nBlock = new.nBlock;
    landmark->sites[block].isOc = 1;
    printf("elem %s\n", new.elem);
}
/*
* Retorna 1 si a esa distancia aproximada hay un sitio de interés. Ejemplo: si
* meters es 135 retorna 1 si se registró algún sitio de interés entre los 100 y 199
* metros), 0 sinó
*/
int hasLandmark(const landmarkADT landmark, size_t meters){
    size_t block = meters / BLOCK;

    return landmark->sites[block].isOc;
}
/*
* Retorna la distancia aproximada en la cual se encuentra el sitio de interés
* o -1 si no existe. Ejemplo: si el sitio de interés se indicó que está a 135
* metros retorna 100, si se indicó a 1240 metros retorna 1200
*/
int distance(const landmarkADT landmark, landmarkType site){
    tSite aux = {site, 0, 0, 1};
    tSite *aux2;
    int ans = -1;

    if(aux2 = findSite(landmark, aux)){
        ans = aux2->nBlock * BLOCK;
    }
    
    return ans;
}
/*
* Retorna cuántos sitios de interés se registraron
*/
size_t landmarkCount(const landmarkADT landmark){
    return landmark->cant;
}
/*
* Retorna un vector con los sitios de interés, en orden ascendente por distancia
* al origen. Si no hubiera sitios de interés retorna NULL
*/
landmarkType * landmarks(const landmarkADT landmark){
    landmarkType *ans = NULL;
    size_t i = 0;
    size_t aux = i;
    for(i; i < landmark->dim; i++){
        if(aux % BLOCK == 0){
            ans = realloc(ans, (aux + BLOCK) * sizeof(landmarkType));
        }

        if(landmark->sites[i].isOc){
            ans[aux++] = landmark->sites[i].elem;
        }
    }

    return ans;
}
/*
* Retorna un vector con los sitios de interés entre dos distancias,
* en orden ascendente por distancia al origen, dejando en *dim la cantidad
* Si from es mayor que to o no hay sitios de interés en ese rango retorna NULL y
* deja *dim en cero
*/
landmarkType * landmarksBetween(const landmarkADT landmark, size_t from, size_t to, size_t *dim){
    landmarkType *ans = NULL;
    size_t i = from / BLOCK;
    size_t aux = 0;
    for(i; i <= to / BLOCK && i < landmark->dim; i++){
        if(aux % BLOCK == 0){
            ans = realloc(ans, (aux + BLOCK) * sizeof(landmarkType));
        }

        if(landmark->sites[i].isOc){
            ans[aux++] = landmark->sites[i].elem;

            printf("agruegue esto al between: %s\n", ans[aux - 1]);
        }
    }

    if(ans){
        ans = realloc(ans, aux * sizeof(landmarkType));
    }

    *dim = aux;

    return ans;
}

void freeLandmark(landmarkADT landmark){
    free(landmark->sites);
    free(landmark);
}