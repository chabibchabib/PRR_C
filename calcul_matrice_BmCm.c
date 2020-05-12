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
/////////////////////////// 
double *tab=malloc(m*m*sizeof(double));
double ** Vmt=malloc(m*sizeof(double*));
for (int i=0;i<m;i++) Vmt[i]=malloc(m*sizeof(double));
transpose(Vm,n,m,Vmt);
printf("1--\n");
mat_mat(Vmt,Vm,tmp1,m,n,m);
printf("2--\n");
mat_mat(Vmt,A,tmp2,m,n,n);
printf("3--\n");
mat_mat(tmp2,Vm,tmp3,m,n,m);
printf("4--\n");
tab= lineariser_matrice(tmp1,m,m); // Lineariser une matrice 
printf("5--\n");
inverse_matrice(tab,m); // inverser une matrice
printf("6--\n");
fact_matrice (tab, m, tmp1); // Passer d'un tableau à matrice
mat_mat(tmp1,tmp3, bmcm,m,m, m);
// desalloouer la mémoire 
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

for(int i = 0; i < m; i++)
    free(Vmt[i]);
free(Vmt);
}


/*int main(){ double n=3; double m=2;
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
