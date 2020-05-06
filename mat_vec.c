#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"
// Fonction calcul matrice x vector 

double *mat_vec(double ** A, double *x, int n){
 double *res= malloc(n* sizeof(double));

for (int i =0 ; i< n ; i++){
res[i]=0;
for (int j =0 ; j< n ; j++){
res[i]+=A[i][j]*x[j];

} // fin for j
} // fin for i

return res;
} // fin mat_vec 

