#include <stdio.h>

int eliminar_repetidos_ordenados(int vec1[], int vec2[], int dim1, int dim2){
    int i = 0, j = 0;
    while(i < dim1 && j < dim2){
        if(vec1[i] < vec2[j]){
            i++;
        }
        else if(vec1[i] > vec2[j]){
            j++;
        }
        else{
            for(int k = i; k < dim1 - 1; k++){
                vec1[k] = vec1[k+1];
            }
            dim1--;
        }
    }

    return dim1;
}

int main(void){
    int vec1[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int vec2[] = {-5, -3, -1, 1, 3, 5, 7, 9, 11, 13};
    int dim = eliminar_repetidos_ordenados(vec1, vec2, 20, 10);
    for(int i = 0; i < dim; i++){
        printf("%d ", vec1[i]);
    }
    return 0;
}