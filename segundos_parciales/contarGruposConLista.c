#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *next;
}tNode;

size_t contarGrupos(tNode *lista, char c){
    if(lista->next == NULL){
        return 0;
    }

    size_t suma = contarGrupos(lista->next, c);

    if(lista->data == c){
        if(lista->next == NULL){
            return 1;
        }

        if(lista->data != lista->next->data){
            return suma + 1;
        }
    }

    return suma;
}

int main(void){
    char v[] = {'a', 'b', 'a', 'a', 'c', 'c', 'c', 'a', 'a', 'b', '\0'};
    tNode *lista = NULL;
    int i;
    for(i = sizeof(v)/sizeof(v[0]) - 2; i >= 0; i--){
        tNode *nuevo = malloc(sizeof(tNode));
        nuevo->data = v[i];
        nuevo->next = lista;
        lista = nuevo;
    }
    size_t repeticiones = contarGrupos(lista, 'a');

    printf("%d\n", repeticiones);

    while(lista){
        tNode *aux = lista;
        lista = lista->next;
        free(aux);
    }

    return 0;
}