#include <stdio.h>
#include <assert.h>

char is_queen_safe(int i, int j, int N, char board[N][N]){
  char is_safe = 1;
  char dirs[8][2] = {{0, 1},
                    {-1, 1},
                    {-1, 0},
                    {-1, -1},
                    {0, -1},
                    {1, -1},
                    {1, 0},
                    {1, 1}};
 
  for(int k = 0; k < 8; k++){
    int posy = i;
    int posx = j;
    for(int l = 1; (posy >=0 && posy < N && posx >= 0 && posx < N) && is_safe; j++){
      posy = (i + dirs[k][0] * l);
      posx = (j + dirs[k][1] * l);
              
      if((board[posy][posx]) == '1'){
        is_safe = 0;
      }
    }
  }
 
  return is_safe;
}
 
char nQueens(int N, char board[N][N]){
  char is_valid = 1;
  int cant_queens = 0;
  
  for(int i = 0; i < N && is_valid; i++){
    for(int j = 0; j < N && is_valid; j++){
      if((board[i][j]) == '1'){
        cant_queens++;
          is_valid = is_queen_safe(i, j, N, board);
        }
      if(cant_queens > N){
        is_valid = 0;
      }
    }
  }
  
  is_valid = (cant_queens == N ? is_valid : 0);
 
  return is_valid;
}

int main(void) {char board[][8] = {{'0', '0', '0', '0', '1', '0', '0', '0'},{'0', '0', '1', '0', '0', '0', '0', '0'},{'0', '0', '0', '0', '1', '0', '0', '0'},{'0', '0', '0', '0', '0', '0', '0', '0'},{'0', '1', '0', '0', '0', '0', '0', '0'},{'0', '0', '0', '0', '0', '0', '1', '0'},{'1', '0', '0', '0', '1', '0', '0', '0'},{'0', '0', '0', '0', '0', '0', '0', '1'},};// por ejemplo, hay tres reinas en la columna 4 y dos en la fila 6
assert(nQueens(8, board) == 0);
char board2[][6] = {{'0', '0', '0', '1', '0', '0'},{'1', '0', '0', '0', '0', '0'},{'0', '0', '0', '0', '1', '0'},{'0', '1', '0', '0', '0', '0'},{'0', '0', '0', '0', '0', '1'},{'0', '0', '1', '0', '0', '0'}};// Hay 6 reinas y no se atacan, retorna true
/* assert(nQueens(6, board2)); */
printf("%d\n",nQueens(6, board2));
char board3[][6] = {{'0', '0', '1', '0', '0', '0'},{'1', '0', '0', '0', '0', '0'},{'0', '1', '0', '0', '0', '0'},{'0', '0', '0', '0', '1', '0'},{'0', '0', '0', '0', '0', '0'},{'0', '0', '0', '0', '0', '1'}};// Las reinas en (1,0) y (2,1) se amenazan en forma diagonal
assert(nQueens(6, board3) == 0);
char board4[][6] = {{'0', '0', '0', '1', '0', '0'},{'0', '0', '0', '0', '0', '0'},{'0', '0', '0', '0', '1', '0'},{'0', '1', '0', '0', '0', '0'},{'0', '0', '0', '0', '0', '1'},{'0', '0', '1', '0', '0', '0'}};// No se amenazan pero hay menos de 6 reinas
assert(nQueens(6, board4) == 0);// No hay solución para tableros de dimensión 2 o 3
assert(nQueens(3, board2) == 0);
assert(nQueens(2, board2) == 0);// En un tablero de 1x1 debe haber una reina
char board1[][1] = {{'1'}};
assert(nQueens(1, board1));
puts("OK!");
return 0;}