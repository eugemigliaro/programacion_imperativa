#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGO 10
#define BLOQUE 100
#define MAX_DIM 10000

/* Hacer un programa que genere aleatoriamente el movimiento de
una partícula en el plano 2D y registre en un arreglo cada una de las
posiciones que fue tomando hasta volver al origen de coordenadas. */

typedef struct{
    int x;
    int y;
}tPunto2D;

typedef struct{
    int x;
    int y;
}tVec2;

tPunto2D mover_particula(tPunto2D *pos, tVec2 mov);
tVec2 generar_movimiento();

int main(void){

    srand(time(NULL));

    tPunto2D particula = {0,0};

    tPunto2D *posiciones = NULL;
    int dim = 0;

    do{
        if(dim % BLOQUE == 0){
            posiciones = realloc(posiciones, (dim + BLOQUE) * sizeof(tPunto2D));
        }

        if(dim == MAX_DIM){break;}

        posiciones[dim] = particula;

        printf("(%d; %d)\n", particula.x, particula.y);

        tVec2 mov = generar_movimiento();
        mover_particula(&particula, mov);

        dim++;
        
    }while(particula.x != 0 || particula.y != 0);

    posiciones[dim++] = particula;
    printf("(%d; %d)\n%d\n", particula.x, particula.y, dim);

    posiciones = realloc(posiciones, dim * sizeof(tPunto2D));

    free(posiciones);

    return 0;
}

tPunto2D mover_particula(tPunto2D *pos, tVec2 mov){
    
    pos->x += mov.x;
    pos->y += mov.y;

    return *pos;
}

tVec2 generar_movimiento(){
    tVec2 mov;
    mov.x = (rand() % ((2 * RANGO) + 1)) - RANGO;
    mov.y = (rand() % ((2 * RANGO) + 1)) - RANGO;

    return mov;
}