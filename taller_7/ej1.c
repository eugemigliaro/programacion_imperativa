#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
 
#define OK 1
#define NOOK !OK
#define NOTA_APROBADO 6
 
int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], const int notas[]);
static void mostrarNombres(char * arrNombres[], size_t n);
static void liberarAprobados(char * aprobados[], size_t n);
 
int
main(void) {
    char * arrNombres[] = {"anita","pepe","fabi","carlos","tere"};
    char * aprobados[5];
    int notas[] = {3,4,8,10,1};
    int tam, tamApro;
    tam = sizeof(arrNombres) / sizeof(char*);
    mostrarNombres(arrNombres, tam);
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
    printf("Aprobados:\n");
    mostrarNombres(aprobados, tamApro);
 
    // Test del ejemplo
    char * aprobados1[5];
    assert(obtenerAprobados(arrNombres, 0, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 1, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 2, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 3, aprobados1, notas) == 1);
    assert(strcmp(aprobados1[0], "fabi") == 0);
    char * aprobados2[5];
    assert(obtenerAprobados(arrNombres, 4, aprobados2, notas) == 2);
    assert(strcmp(aprobados2[0], "fabi") == 0);
    assert(strcmp(aprobados2[1], "carlos") == 0);
    char * aprobados3[5];
    assert(obtenerAprobados(arrNombres, 5, aprobados3, notas) == 2);
    assert(strcmp(aprobados3[0], "fabi") == 0);
    assert(strcmp(aprobados3[1], "carlos") == 0);
 
    printf("\nOK!\n");

    liberarAprobados(aprobados, tamApro);

    return 0;
}

int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], const int notas[]){
/*     int ntam = 0;
    for(int i = 0; i < tam; i++){
        if(notas[i] >= NOTA_APROBADO){
            aprobados[ntam++] = arrNombres[i];
        }
    }

    return ntam; */ //this works, but now i want to try it copying the strings, not just the pointers to said strings

    int ntam = 0, i, isOk = OK;

    for(i = 0; i < tam && isOk; i++){
        if(notas[i] >= NOTA_APROBADO){
            aprobados[ntam] = malloc(strlen(arrNombres[i]) + 1);
            if(aprobados[ntam] == NULL || errno == ENOMEM){
                isOk = NOOK;
            }
            else{
                strcpy(aprobados[ntam], arrNombres[i]);
                ntam++;
            }
        }
    }

    return isOk ? ntam : 0;
}

static void mostrarNombres(char *arrNombres[], size_t n){
    for(int i = 0; i < n; i++){
        printf("%s ", arrNombres[i]);
    }
    printf("\n");
}

static void liberarAprobados(char *aprobados[], size_t n){
    for(int i = 0; i < n; i++){
        free(aprobados[i]);
    }
}