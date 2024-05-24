#include <stdio.h>
#include <stdlib.h>
#include "../lib/utillist.h"

/*
 * Escribir un programa para hallar las raíces de una función matemática en un
 * intervalo cerrado, recorriéndolo de forma tal que el intervalo quede dividido
 * en 100000 (cien mil) particiones o subintervalos. Ejemplo: si el intervalo es
 * [1, 50000] deberá evaluar la función en los puntos 1, 1.5, 2, etc.
 * (también se tomarán como válidos los puntos 1, 1.49999, etc.).
 *
 * El programa ofrecerá un menú de funciones matemáticas y deberá solicitar los
 * extremos del intervalo, imprimiendo los resultados en la salida estándar.
 * Todas las funciones reciben y devuelven un valor real.
 *
 * La función que realice la búsqueda de las raíces debe recibir como parámetros
 * una estructura que represente al intervalo y una función a la cual se le
 * quieren Hallar las raíces, regresando en su nombre una estructura que empaquete
 * un arreglo con aquellas particiones donde haya raíces y la dimensión de
 * dicho arreglo.
 *
 * Para detectar una raíz se deben considerar dos casos:
 * Que la función cambie de signo entre dos puntos: En ese caso se agrega al
 * arreglo una partición con ambos puntos.
 * Que la función se haga cero en un punto (considerando un error de
 * EPSILON): En ese caso la partición que se agrega al arreglo de resultados
 * está formada por el punto anterior al que se detectó como raíz y el próximo que
 * no lo sea.
 */

typedef struct {
    double a;
    double b;
} TInterval;

typedef struct {
    double *roots;
    int size;
} TRoots;

