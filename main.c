#include<stdio.h>
#include<stdlib.h>
#include<lapacke.h>
#include "header.h"


int main(){

int n =4 ;int  m=2; int r=1;
double *x=calloc(n,sizeof(double));
//double **val= malloc(m*sizeof(double*));
//for (int i=0;i<m;i++) val[i]=malloc(2*sizeof(double));
double *val= malloc(m*sizeof(double));
double **vec= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) vec[i]=malloc(m*sizeof(double));
double **A= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) A[i]=malloc(n*sizeof(double));
// x
//for (int i=0; i<n ; i++) x[i]=1; x
x[0]=1;
// 
/*for (int i=0; i<n ; i++){
for (int j=0; j<n ; j++){
scanf("%lf",&A[i][j]);
}}*/
A[0][0]=9; A[0][1]=1;A[0][2]=-2;A[0][3]=1;A[1][0]=1;A[1][1]=8;A[1][2]=-3 ;A[1][3]=-2;
A[2][0]=-2;A[2][1]=-3;A[2][2]=7;A[2][3]=-1;A[3][0]=1;A[3][1]=-2;A[3][2]=-1;A[3][3]=6;
//{{9 ,1 , -2 ,1 },{1,8,-3,-2 },{-2,-3,7 ,-1},{ 1 , -2  ,-1   ,6}};
//afficher_matrice(A,n,n);
// PRR
PRR(n,  m ,  r, A,vec, val, x );

free(x);
//for (int i=0; i<m ; i++) free(val[i]);
free(val);
for (int i=0; i<n ; i++) free(vec[i]);
free(vec);

for (int i=0; i<n ; i++) free(A[i]);
free(A);


}

