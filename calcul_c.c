#include <stdio.h>
#include<stdlib.h>
#include "header.h"
#include <math.h>
#include<lapacke.h>
double * C_computation (int m, int n, double * x, double **A )
{

// Déclaration des variables et allocation mémoire

 double *res= malloc((2*m)*sizeof(double));
 double *y0=malloc((n)*sizeof(double));
 double *y1=malloc((n)*sizeof(double));

// Initialisation

 double norme= produit_scalaire (x,x,n);
norme= sqrt(norme);

for (int i=0; i<n;i++){
y0[i]=x[i]/norme;
}

res[0]=1;

// calcul y1;
y1=mat_vec(A,y0,n);

// Boucle
 for (int k=1; k<=m-1 ; k++){
res[2*k-1]= produit_scalaire (y1,y0,n);
res[2*k]= produit_scalaire (y1,y1,n);
y0=y1;
y1=mat_vec(A,y0,n);

} // end for
res[2*m-1]=produit_scalaire (y1,y0,n);

return res;

// Libérer la mémoire 
free(res);
free(y0);
free(y1);

} // fin fonction  
