#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(void){
    int *arr;
    int i;

    arr = (int*)malloc(100 * sizeof(int));
    arr = (int *)realloc(arr, TAM * sizeof(int));

    for(i = 0; i < TAM; i++){
        arr[i] = 0;
    }

    for(i = 0; i < TAM; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}