#include <stdio.h>
#include <assert.h>
 
#define FILAS 7
#define COLS 6
 
#define ERROR (-1)
enum direcciones {N = 0, NE, E, SE, S, SO, O, NO}; // man fuck that shit im out of shit
 
int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y){
    int res = ERROR;
    if(y >= 0 && y < ancho && x >= 0 && x < alto){
        if(mat[x][y] == 'X' || mat[x][y] == '1'){
            return ERROR;
        }
    
        int mov[][2] = {
            {0, 1},
            {-1, 1},
            {-1, 0},
            {-1, -1},
            {0, -1},
            {1, -1},
            {1, 0},
            {1, 1}
        };

        int i = 0, j = 1, distancia = 0, distancia_anterior = 0;
        for(i = 0; i < 8; i++){
            j = 1;
            distancia = 0;
            while((mat[x + j * mov[i][0]][y + j * mov[i][1]] == '0') && (x + j * mov[i][0] >= 0 && x + j * mov[i][0] < alto && y + j * mov[i][1] >= 0 && y + j * mov[i][1] < ancho)){
                j++;
                distancia++;
            }
            if(distancia > distancia_anterior){
                distancia_anterior = distancia;
                res = i;
            }
        }
        return res * 45;
    }

    return res;
}
 
int
main(void) {
    char tablero[][COLS] = {
            {'0', '0', '0', '0', '1', '0'},
            {'X', 'X', '0', '0', '0', '0'},
            {'0', '0', '0', '0', 'X', 'X'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', 'X', '0', '0'},
            {'1', '0', '0', 'X', 'X', 'X'}
    };
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    assert(res == 0 || res == 45);
 
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
    assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
    assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
    assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);
 
    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
    assert(res == 0 || res == 45 || res == 90 || res == 270);
 
    // Jugador fuera del tablero
    assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);
 
    printf("OK!\n");
    return 0;
}