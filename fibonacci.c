#include <stdio.h>
#include <stdlib.h>

int fibo(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    printf("%d", fibo(n));
    return 0;
}