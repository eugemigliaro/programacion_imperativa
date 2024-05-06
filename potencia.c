#include <stdio.h>
#include <stdlib.h>

int pow(int base, int exp){
    if(exp == 0){
        return 1;
    }
    return base * pow(base, exp - 1);
}

int main(){
    int base, exp;
    printf("Base: ");
    scanf("%d", &base);
    printf("Exponente: ");
    scanf("%d", &exp);
    printf("%d^%d = %d", base, exp, pow(base, exp));
    return 0;
}