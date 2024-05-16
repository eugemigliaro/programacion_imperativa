#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DIM 9

/* Escribir una función sudokuSolver, que reciba una matriz de 9x9 de un sudoku incompleto y retorne 1 si tiene solución y 0 si no tiene solución.
En caso de tener solución debe completar la matriz con una solución posible (podría haber más de una solución válida).
Como estrategia se debe usar un algoritmo de tipo "fuerza bruta", esto es, tratar de llenar cada casilla vacía con todos los números válidos posibles, combinando a su vez con todos los posibles números válidos de las casillas libres restantes.
Se asegura que en cada celda de la matriz recibida hay un número entre 0 y 9, donde 0 indica que la casilla está libre. También se asegura que no hay números repetidos en una misma fila, columna o subcuadrado.
 */

int sudokuSolver(char matriz[DIM][DIM]);

int main(void) {
    // Una vacia tiene que tener solucion
    char sudoku[DIM][DIM] = {{0}};

    assert(sudokuSolver(sudoku)==1);
    for(int i=0; i < DIM; i++) {
        for(int j=0; j < DIM; j++) {
            printf("%1d ", sudoku[i][j]);
        }
        putchar('\n');
    }

    printf("\nUno sin solucion\n");
    char sudoku2[DIM][DIM] = {{1,2,3,4,5,6,7,8,9},
                            {5,6,7,8,9,1,2,3,4},
                            {8,9,1,2,3,7,5,6,0},
                           };

    assert(sudokuSolver(sudoku2)==0);
    for(int i=0; i < DIM; i++) {
        for(int j=0; j < DIM; j++) {
            printf("%1d ", sudoku2[i][j]);
        }
        putchar('\n');
    }

    printf("\nUno con solucion pero con celdas no vacias\n");
    char sudoku3[DIM][DIM] = {
                            {0,2,0,3,0,0,0,0,0},
                            {9,4,0,6,8,7,0,0,0},
                            {1,6,0,0,0,0,0,0,0},
                            {0,0,0,0,9,2,5,4,0},
                            {0,0,0,0,6,0,0,0,0},
                            {8,0,0,4,0,3,0,1,6},
                            {0,1,0,0,7,6,0,8,2},
                            {0,0,0,9,0,0,6,0,0},
                            {7,0,6,0,0,4,9,3,0}
                            };

    assert(sudokuSolver(sudoku3)==1);
    for(int i=0; i < DIM; i++) {
        for(int j=0; j < DIM; j++) {
            printf("%1d ", sudoku3[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

int recursiveSolver(char matrix[DIM][DIM], int row, int col){
    if(row == DIM-1 && col == DIM){
        return 1;
    }

    if(col == DIM){
        return recursiveSolver(matrix, row+1, 0);
    }

    if(matrix[row][col] != 0){
        return recursiveSolver(matrix, row, col+1);
    }

    for(int i=1; i <= DIM; i++){
        if(esValido(matrix, row, col, i)){
            matrix[row][col] = i;
            if(recursiveSolver(matrix, row, col+1) == 1){
                return 1;
            }
            matrix[row][col] = 0;
        }
    }

    return 0;
}

int sudokuSolver(char matriz[DIM][DIM]){
    return recursiveSolver(matriz, 0, 0);
}

int esValido(char matrix[DIM][DIM], int row, int col, int num){
    for(int i=0; i<DIM; i++){
        if(matrix[row][i] == num){
            return 0;
        }
    }

    for(int i=0; i<DIM; i++){
        if(matrix[i][col] == num){
            return 0;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i=startRow; i < (startRow + 3); i++){
        for(int j=startCol; j < (startCol + 3); j++){
            if(matrix[i][j] == num){
                return 0;
            }
        }
    }

    return 1;
}