#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    printf("%d", factorial(n));
    return 0;
}