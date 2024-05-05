#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Function declarations */
int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], int notas[]);
static void mostrarNombres(char *arrNombres[], size_t n);


/* Main function */
int main(void) {
    /* Arrays of strings to store names and grades */
    char *arrNombres[] = {"anita", "pepe", "fabi", "carlos", "tere"};
    char *aprobados[5];
    int notas[] = {3, 4, 8, 10, 1};
    int tam, tamApro;

    /* Calculate the length of the names array */
    tam = sizeof(arrNombres) / sizeof(char *);

    /* Print the names */
    mostrarNombres(arrNombres, tam);

    /* Get the approved students and their grades */
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);

    /* Print the approved students */
    printf("Aprobados:\n");
    mostrarNombres(aprobados, tamApro);

    /* Return 0 to indicate successful execution */
    return 0;
}


int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], int notas[]){}

static void mostrarNombres(char *arrNombres[], size_t n){}