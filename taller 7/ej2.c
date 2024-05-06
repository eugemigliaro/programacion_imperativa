#include <stdio.h>
#include <stdlib.h>
  
#define TOTAL_ITEMS 2
#define MAX_LONG 10
 
typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;
 
typedef tItem tFactura[TOTAL_ITEMS];
 
void cargar(tFactura fact, int cant);
float importe(tFactura fact, int cant);
 
int
main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f", importe(f, TOTAL_ITEMS));
    return 0;
}

void cargar(tFactura fact, int cant){
    for(int i = 0; i < cant; i++){
        printf("Ingresá el código del item %d: ", i + 1);
        scanf(" %d", &(fact[i].codigo));
        printf("Ingresá la descripción del item %d: ", i + 1);
        scanf(" %[^\n]%*c", fact[i].desc);
        printf("Ingresá el precio del item %d: ", i + 1);
        scanf(" %f", &(fact[i].precio));
    }
}

float importe(tFactura fact, int cant){
    float total = 0;
    for(int i = 0; i < cant; i++){
        total += fact[i].precio;
    }
    return total;
}