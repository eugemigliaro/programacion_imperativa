#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ej1.h"

struct palabraCDT{
    char *letras;
    unsigned int len;
};

palabraADT crearVacia(){
    palabraADT pal = malloc(sizeof(struct palabraCDT));
    pal->letras = NULL;
    pal->len = 0;
    return pal;
}

palabraADT crearDesde(char *palabra){
    palabraADT pal = malloc(sizeof(struct palabraCDT));
    pal->letras = (char *)malloc(strlen(palabra) * sizeof(char));
    strcpy(pal->letras, palabra);
    pal->len = strlen(palabra);
    return pal;
}

void destruirPalabra(palabraADT pal){
    free(pal->letras);
    free(pal);
}

void mostrarPalabra(palabraADT pal){
    printf("%s\n", pal->letras);
}

palabraADT agregarLetra(palabraADT pal, char letra){
    pal->letras = (char *)realloc(pal->letras, (pal->len + 1) * sizeof(char));
    pal->letras[pal->len] = letra;
    pal->len++;
    return pal;
}

palabraADT concatenar(palabraADT pal1, palabraADT pal2){
    palabraADT pal = malloc(sizeof(struct palabraCDT));
    pal->letras = (char *)malloc((pal1->len + pal2->len) * sizeof(char));
    strcpy(pal->letras, pal1->letras);
    strcat(pal->letras, pal2->letras);
    pal->len = pal1->len + pal2->len;
    return pal;
}

palabraADT pasarAMayusculas(palabraADT pal){
    for(int i = 0; i < pal->len; i++){
        pal->letras[i] = toupper(pal->letras[i]);
    }
    return pal;
}

palabraADT pasarAMinusculas(palabraADT pal){
    for(int i = 0; i < pal->len; i++){
        pal->letras[i] = tolower(pal->letras[i]);
    }
    return pal;
}