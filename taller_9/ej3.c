#include <stdio.h>
#include <assert.h>

/* Escribir una función recursiva que reciba un arreglo de enteros, un valor para caso base y
le aplique una función provista por el usuario.
La función opera sobre pares de elementos y devuelve un número entero. */
 
typedef int (*fn) (int, int);
int operatoria(int v[], size_t dim, int base, fn f);
 
int producto(int x, int y) {
    return x * y;
}
 
int suma(int x, int y) {
    return x + y;
}
 
int
main(void) {
    int v1[] = {2,3,4,5};
    assert(operatoria(v1, 4, 1, producto) == 120);
    assert(operatoria(v1, 4, 0, suma) == 14);
 
    printf("OK!\n");
    return 0;
}

int operatoria(int v[], size_t dim, int base, fn f) {
    if (dim == 0) {
        return base;
    } else {
        return f(v[dim-1], operatoria(v, dim-1, base, f));
    }
}