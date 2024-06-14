/*  Escribir la función recursiva contarGrupos que reciba como únicos parámetros
un string (cadena de chars null terminated) y un carácter. La función debe retornar la
cantidad de grupos de caracteres consecutivos iguales al carácter pasado por
parámetro. Un grupo está formado por uno o más caracteres iguales de manera
consecutiva */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t contarGrupos(char *s, char c){
    if(*s == '\0'){
        return 0;
    }

    size_t suma = contarGrupos(s + 1, c);

    if(*s == c){
        if(suma == 0){
            return suma + 1;
        }
        if(*s != *(s+1)){
            return suma + 1;
        }
    }

    return suma;
}

int main(void){
    size_t repeticiones = contarGrupos("aabcn bnfug a nbgvjf a ngjfa", 'a');

    printf("%d\n", repeticiones);

    return 0;
}