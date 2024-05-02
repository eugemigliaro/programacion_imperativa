#include <stdio.h>

void firstN(unsigned char vec[], int dim, unsigned int n, int *ndim, int *del){
  *ndim = dim;
  *del = 0;
  int rep[256] = {0};
  for(int i = 0; i < *ndim; i++){
    if(rep[vec[i]] < n){
      rep[vec[i]]++;
    }
    else{
      for(int j = i; j < (*ndim) - 1; j++){
        vec[j] = vec[j + 1];
      }
      (*ndim)--;
      (*del)++;
      i--;
    }
  }
}

int main(void) {unsigned char v[] = {1, 2, 1, 3, 1, 4, 5, 2};
int dim, del;
/* firstN(v, 8, 3, &dim, &del); // dim es 8, del es 0, v no cambia
firstN(v, 8, 8, &dim, &del); // dim es 8, del es 0, v no cambia
for(int i = 0; i < 8; i++) printf("%d ", v[i]);
printf("\n");
firstN(v, 8, 4, &dim, &del); // dim es 8, del es 0, v no cambia
for(int i = 0; i < 8; i++) printf("%d ", v[i]);
printf("\n"); */
firstN(v, 8, 1, &dim, &del); // dim=5, del=3, v = {1, 2, 3, 4, 5};
for(int i = 0; i < dim; i++) printf("%d ", v[i]);
printf("\n");
unsigned char w[] = {1, 2, 1, 3, 1, 4, 5, 2};
firstN(w, 8, 0, &dim, &del); // dim=0, del=8, w = {}
for(int i = 0; i < dim; i++) printf("%d ", w[i]);
printf("\n");
unsigned char t[] = {1, 2, 1, 3, 1, 4, 5, 2};
firstN(t, 8, 2, &dim, &del); // dim=7, del=1, t = {1, 2, 1, 3, 4, 5, 2}
for(int i = 0; i < dim; i++) printf("%d ", t[i]);
printf("\n");
return 0;}