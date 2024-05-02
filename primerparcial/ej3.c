#include <stdio.h>
#include <assert.h>

int WordLadder(int len, char a[len], char b[len]){
/* funcion auxiliar que toma dos palabras y 
﻿retorna el índice de la letra diferente si forman una escalera, 
﻿sino lo son retorna -1 */

    int is_ladder = 0;
  
  int dif = 0;
  int i = 0;
  for(i; i < len && dif <= 1; i++){
    if(a[i] != b[i]){
      dif++;
      is_ladder = i;
    }
  }
 
  if(!((i == len) && (dif == 1))){
    is_ladder = -1;
  }
 
  return is_ladder;
}
 
char isWordLadder(int rows, int cols, char mat[rows][cols]){
  char is_ladder = 1;
  int ladder_index = -2, next_ladder_index = -2;
 
  for(int i = 0; (i < rows - 1) && (ladder_index != -1); i++){
    next_ladder_index = WordLadder(cols, mat[i], mat[i + 1]);
    ladder_index = (ladder_index == next_ladder_index) ? -1 : next_ladder_index;
  }
  
  is_ladder = (ladder_index == -1) ? 0 : is_ladder;  
 
  return is_ladder;
}

int main(void) {
    char wordMatrix[][4] = {{'t', 'e', 's', 't'},{'b', 'e', 's', 't'},{'b', 'e', 's', 'o'},{'b', 'e', 's', 'a'}};
    // Considerando todas las filas no es escalera// pues los últimos dos cambios son en la última letra
    assert(!isWordLadder(4, 4, wordMatrix));// Considerando una sola fila es escalera
    printf("%d\n", isWordLadder(3, 4, wordMatrix));
    assert(isWordLadder(1, 4, wordMatrix) == 1);// Considerando las tres primeras filas es escalera
    assert(isWordLadder(3, 4, wordMatrix) == 1);
    char wordMatrix2[][3] = {{'t', 'e', 's'},{'t', 'b', 'e'},{'s', 'b', 'e'},{'b', 'b', 'e'}};// TeS -> Tbe cambian dos letras
    assert(!isWordLadder(4, 3, wordMatrix2));
    char wordMatrix3[][3] = {{'a', 'm', 'o'},{'a', 'r', 'o'},{'o', 's', 'a'}};// aro -> osa cambian tres letras
    assert(!isWordLadder(3, 3, wordMatrix3));
    puts("OK!");
return 0;}