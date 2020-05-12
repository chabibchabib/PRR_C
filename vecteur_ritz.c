#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

double ** vecteur_ritz(double ** bmcm, double **Vm, int n,int m ){
double **res= malloc(m*sizeof(double*));
for (int i=0;i<m;i++) res[i]=malloc((m+1)*sizeof(double));
res=vecteur_yi_ritz(bmcm,m);
double ** tmp=malloc(m*sizeof(double*));
for (int i=0;i<m;i++) tmp[i]=malloc((m)*sizeof(double));
for (int i=0;i<m;i++){
for (int j=0;j<m;j++){ tmp[i][j]=res[i][j];
}}
double **res2= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) res2[i]=malloc((m+1)*sizeof(double));

mat_mat(Vm, tmp, res2,n,m,m);
for (int i=0;i<m;i++){ res2[i][m]=res[i][m];
}
return res2;
for (int i=0;i<m;i++) free(res[i]);
free(res);
for (int i=0;i<m;i++) free(tmp[i]);
free(tmp);
for (int i=0;i<n;i++) free(res2[i]);
free(res2);
}

/*int main(){ int m=2; int n =3;
double ** Vm= malloc ( n*sizeof(double*));
for (int i =0 ; i<n ; i++){
Vm[i]=malloc(m*sizeof(double));
}
double ** res= calloc ( n,sizeof(double*));
for (int i =0 ; i<n ; i++){
res[i]=calloc(m+1,sizeof(double));
}

double ** bmcm=malloc ( m*sizeof(double*));
for (int i =0 ; i<m ; i++){
bmcm[i]=malloc(m*sizeof(double));
}
for(int i=0; i<m ;i++)
{
for(int j=0; j<m ;j++){ scanf("%lf",&bmcm[i][j]);
}}
printf("\n Vm\n");
for(int i=0; i<n ;i++)
{
for(int j=0; j<m ;j++){ scanf("%lf",&Vm[i][j]);
}}
res=vecteur_ritz(bmcm,Vm,n, m );
for(int i=0; i<n ;i++)
{printf("\n");
for(int j=0; j<=m ;j++){ printf("%f\t",res[i][j]);
}}
// desallouer 
for (int i =0 ; i<n ; i++) free(Vm[i]);
free(Vm);
for (int i =0 ; i<n ; i++) free(res[i]);
free(res);
for (int i =0 ; i<m ; i++) free(bmcm[i]);
free(bmcm);
}*/
