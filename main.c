#include<stdio.h>
#include<stdlib.h>
#include<lapacke.h>
#include "header.h"


int main(){

int n =4 ;int  m=3; int r=1;
double *x=malloc(n*sizeof(double));
double **val= malloc(m*sizeof(double*));
for (int i=0;i<m;i++) val[i]=malloc(2*sizeof(double));
double **vec= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) vec[i]=malloc(m*sizeof(double));
double **A= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) A[i]=malloc(n*sizeof(double));
// x
for (int i=0; i<n ; i++) x[i]=1;
// 
for (int i=0; i<n ; i++){
for (int j=0; j<n ; j++){
scanf("%lf",&A[i][j]);
}}

// PRR
PRR(n,  m ,  r, A,vec, val, x );
printf("apres prr\n");
//
free(x);
for (int i=0; i<m ; i++) free(val[i]);
free(val);
for (int i=0; i<n ; i++) free(vec[i]);
free(vec);

for (int i=0; i<n ; i++) free(A[i]);
free(A);


}

