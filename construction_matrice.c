#include <stdio.h>
#include<stdlib.h>
#include "header.h"
#include <math.h>
#include<lapacke.h>

void construction_matrice(double *c, int m, double **M){

for (int i=0; i<m;i++){
for (int j=0; j<m;j++){
M[i][j]=c[j+i];
}}

} // fin fonction 
