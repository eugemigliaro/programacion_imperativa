#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "bibleADT.h"

int
main(void) {
    bibleADT b = newBible();
    assert(getVerse(b, 1, 1)==NULL);
    printf("paso assert 1\n");

    char aux[2000];
    strcpy(aux, "En el principio creo Dios los cielos y la tierra.");
    assert(addVerse(b, 1, 1, aux)==1);
    printf("paso assert 2\n");

    strcpy(aux, "Y atardecio y amanecio: dia tercero.");
    assert(addVerse(b, 1, 13, aux)==1);
    printf("paso assert 3\n");

    assert(addVerse(b, 1, 13, "Amaos los unos a los otros")==0); // Ya estaba
    printf("paso assert 4\n");

    strcpy(aux, "los contados de la tribu de Dan fueron sesenta y dos mil setecientos.");
    assert(addVerse(b, 4, 39, aux)==1);
    printf("paso assert 5\n");

    assert(addVerse(b, 4, 46,
      "fueron todos los contados seiscientos tres mil quinientos cincuenta.")==1);
    printf("paso assert 6\n");

    char * v = getVerse(b, 4, 45);
    assert(v==NULL);
    printf("paso assert 7\n");

    v = getVerse(b, 4, 39);
    assert(strncmp(v, "los con", 7)==0);
    printf("paso assert 8\n");

    free(v);
    printf("paso el primer free\n");

    freeBible(b);
    puts("Aleluya !");
    return 0;
}