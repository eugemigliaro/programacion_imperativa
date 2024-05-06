#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char desde, char hasta, char intermedio);

int main(void){

    hanoi(6, 'A', 'C', 'B');
    return 0;
}

void hanoi(int n, char desde, char hasta, char intermedio){
    if(n == 1){
        printf("Mover disco de %c a %c\n", desde, hasta);
    }
    else{
        hanoi(n - 1, desde, intermedio, hasta);
        hanoi(1, desde, hasta, intermedio);
        hanoi(n - 1, intermedio, hasta, desde);
    }
}