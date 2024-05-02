#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main(void){
    int *arr, i;
    arr = (int *)calloc(TAM, sizeof(int));

    for(i = 0; i < TAM; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}