#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "landmarkADT.h"

char cmp(landmarkType site1, landmarkType site2){
    return strcmp(site1, site2);
}

int
main(void) {
landmarkADT lm = newLandmark(cmp);
assert(landmarkCount(lm)==0);
landmarkType * v = landmarks(lm);
assert(v==NULL);
size_t dim;
v = landmarksBetween(lm, 0, 300, &dim);

assert(v==NULL && dim==0);
addLandmark(lm, 50, "Atalaya");
addLandmark(lm, 70, "YPF abandonada");
addLandmark(lm, 99, "El estadio del Chelsea");
assert(landmarkCount(lm)==1);
addLandmark(lm, 650, "Restos de un OVNI");
addLandmark(lm, 350, "Pulpería de 1800");
addLandmark(lm, 200, "Otra pulperia");

printf("llego hasta aca\n");

v = landmarksBetween(lm, 0, 299, &dim);

printf("%d\n", dim);

assert(dim==2);
assert(strcmp(v[0], "El estadio del Chelsea")==0);
assert(strcmp(v[1], "Otra pulperia")==0);
free(v);
v = landmarksBetween(lm, 100, 199, &dim);
assert(v==NULL && dim==0);
// El siguiente ciclo imprime:
// El estadio del Chelsea
// Otra pulpería
// Pulpería de 1800
// Restos de un OVNI
v = landmarks(lm);
for(int i=0; i < landmarkCount(lm); i++) {
puts(v[i]);
}
free(v);
assert(distance(lm, "Atalaya")==-1);

printf("pase el 51\n");

assert(distance(lm, "El estadio del Chelsea")==0);
assert(distance(lm, "Restos de un OVNI")==600);

printf("pase el 56\n");

for(int i=600; i<=699; i++)
assert(hasLandmark(lm, i));
for(int i=0; i<=99; i++)
assert(hasLandmark(lm, i));
for(int i=100; i<=199; i++)
assert(!hasLandmark(lm, i));

printf("casicasi\n");

freeLandmark(lm);
puts("OK!");
return 0;
}