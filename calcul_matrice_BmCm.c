#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

void calcul_matrice_BmCm(double **bmcm, double **Vm, double **A, int n, int m ){
double ** tmp1=malloc(m*sizeof(double*));
for (int i=0;i<m;i++) tmp1[i]=malloc(m*sizeof(double));
double ** tmp2=malloc(m*sizeof(double*));
for (int i=0;i<m;i++) tmp2[i]=malloc(n*sizeof(double));
double ** tmp3=malloc(m*sizeof(double*));
for (int i=0;i<m;i++) tmp3[i]=malloc(m*sizeof(double));
double ** Vmtt=malloc(m*sizeof(double*));
for (int i=0;i<m;i++) Vmtt[i]=malloc(n*sizeof(double));
double *tab=malloc(m*m*sizeof(double));
/////////////////////////// 
transpose(Vm,n,m,Vmtt);
mat_mat(Vmtt,Vm,tmp1,m,n,m);
mat_mat(Vmtt,A,tmp2,m,n,n);
mat_mat(tmp2,Vm,tmp3,m,n,m);
tab= lineariser_matrice(tmp1,m,m); // Lineariser une matrice 
inverse_matrice(tab,m); // inverser une matrice
fact_matrice (tab, m, tmp1); // Passer d'un tableau à matrice
mat_mat(tmp1,tmp3, bmcm,m,m, m);
free(tab);
for(int i = 0; i < m; i++)
    free(tmp1[i]);
free(tmp1);
for(int i = 0; i < m; i++)
    free(tmp2[i]);
free(tmp2);
for(int i = 0; i < m; i++)
    free(tmp3[i]);
free(tmp3);
for (int i=0;i<m;i++) free(Vmtt[i]);
free(Vmtt);
}


/*int main(){ double n=4; double m=2;
double ** Vm=malloc(n*sizeof(double*));
for (int i=0;i<n;i++) Vm[i]=malloc(m*sizeof(double));

double ** bmcm=malloc(m*sizeof(double*));
for (int i=0;i<m;i++) bmcm[i]=malloc(m*sizeof(double));
double ** A=malloc(n*sizeof(double*));
for (int i=0;i<n;i++) A[i]=malloc(n*sizeof(double));
////
for (int i=0;i<n;i++){
for (int j=0;j<n;j++){
scanf("%lf",&A[i][j]);
}}
for (int i=0;i<n;i++){
for (int j=0;j<m;j++){
scanf("%lf",&Vm[i][j]);
}}
//
calcul_matrice_BmCm(bmcm,Vm,A,n,m );
for (int i=0;i<m;i++){
printf("\n");
for (int j=0;j<m;j++){
printf("%f",bmcm[i][j]);
}}
//
for(int i = 0; i < n; i++)
    free(Vm[i]);
free(Vm);
for(int i = 0; i < m; i++)
    free(bmcm[i]);
free(bmcm);

for(int i = 0; i < n; i++)
    free(A[i]);
free(A);
}*/
