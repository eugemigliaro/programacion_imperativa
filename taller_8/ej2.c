#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
int igualesRet(const int[], const int[]);
void igualesVoid(const int[], const int[], int * rta);
 
int
main(void) {
    int resultado;
    int a[] = {9, 4, 3, 2, 3, 7,-1};
    int b[] = {9, 4, 3, 2, 3, 7,-1};
    int c[] = {7, 3, 2, 3, 4, 9,-1};
    int d[] = {9, 4, 3, -1};
    int e[] = {-1};
 
    assert(igualesRet(a, b) == 1);
    assert(igualesRet(b, c) == 0);
    assert(igualesRet(c, d) == 0);
    assert(igualesRet(d, e) == 0);
 
    igualesVoid(a, b, &resultado);
    assert(resultado == 1);
    igualesVoid(b, c, &resultado);
    assert(resultado == 0);
    igualesVoid(c, d, &resultado);
    assert(resultado == 0);
    igualesVoid(d, e, &resultado);
    assert(resultado == 0);
 
    printf("OK!\n");
    return 0;
}

int igualesRet(const int a[], const int b[]) {
    if (a[0] == b[0]){
        if(a[0] == -1){
            return 1;
        }

        return igualesRet(a + 1, b + 1);
    }
    return 0;
}

void igualesVoid(const int a[], const int b[], int * rta) {
    *rta = 0;
    if (a[0] == b[0]){
        if(a[0] == -1){
            *rta = 1;
        }
        else{
            igualesVoid(a + 1, b + 1, rta);
        }
        return;
    }
}
