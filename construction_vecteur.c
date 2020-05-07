#include <stdio.h>
#include<stdlib.h>
#include "header.h"
#include <math.h>
#include<lapacke.h>

double * construction_vecteur(double *c, int m){
double * tab= malloc (m*sizeof(double));
for (int i=0; i<m;i++){
tab[i]=-c[i+m];
}
return tab;
free (tab);
} // fin fonction 
