#include <stdio.h>

int main(void){

    int num;
    printf("ingresa un numero, yo sumo los digitos: ");
    scanf(" %d", &num);
    //Declaramos una variable "sum" que almacenara la sumatoria de los digitos del numero ingresado por el usuario
    
    int sum = 0;

    while(num > 0){
        int cifra = num%10; //Obtener la última cifra
        printf("%d ", cifra); //Imprimirla como carácter ascii
        num /= 10;                     //Eliminar la última cifra
        sum += cifra;
    }

    printf("\nLa suma de todos los dígitos es: %d\n", sum);

    return 0;
}