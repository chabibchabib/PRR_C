#include <stdio.h>
#include<stdlib.h>
#include "header.h"
#include <math.h>
#include<lapacke.h>

double * poly_racine(double *a,int degre){
int  IERR=0;
double *Z=malloc(2*(degre)*(sizeof(double)));
double *H=malloc(2*(degre)*(sizeof(double)));
LAPACK_dpolz(a,degre , Z, H, IERR);
printf("erreur %d",IERR);
return Z;
free(Z);
free(H);
}
int main(){
int degre=3;
double *Z=malloc(2*degre*(sizeof(double)));
double *a=malloc((1+degre)*(sizeof(double)));
for (int i=0; i<=degre;i++){
scanf("%lf",&a[i]);

}
Z= poly_racine(a,degre);
for (int i=0; i<2*degre;i++){
printf("%f\t",Z[i]);

}
}
