#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

void normalisation(double *x, int n ){
double norme= norme_vec(x,n);
for(int i =0 ;i<n ; i++) x[i]=x[i]/norme;
} 
void PRR(int n, int m , int r, double **A,double **vec, double **val, double *x ){
double eps=pow(10,-10); double kmax=100; double err=1; int NRHS;
// Allocation 
 double *C= malloc((2*m)*sizeof(double));
double **bm= malloc(m*sizeof(double*));
for (int i=0;i<m;i++) bm[i]=malloc(m*sizeof(double));
double * cm= malloc (m*sizeof(double));
double *bm_l=malloc (m*m*sizeof(double));
double **Vm= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) Vm[i]=malloc(m*sizeof(double));
double **bmcm= malloc(m*sizeof(double*));
for (int i=0;i<m;i++) bmcm[i]=malloc(m*sizeof(double));
double **vec_ritz= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) vec_ritz[i]=malloc((m+1)*sizeof(double));
double *lambda=malloc(m*sizeof(double));
/////////////////////////////////////
normalisation(x,n);
for(int k=0;k<kmax;k++){
// Calcul des coefficient C
C=C_computation (m,n,x,A );
// resolution du système (63) Yule-Walker
construction_matrice(C,m,bm);
cm=construction_vecteur(C,m);
bm_l=lineariser_matrice(bm,m,m);
resolution_systeme(bm_l,m, cm, NRHS);
//racines polynomes
racine_polynome(cm,m,val );
// Ritz vecteurs 
calcul_Vm(A,Vm,x,n,m);
printf("desall prr--7\n");
calcul_matrice_BmCm(bmcm,Vm,A,n,m );
printf("desall prr8");
vec_ritz=vecteur_ritz(bmcm,Vm,n,m );
printf("desall prr9");
vec= copier( vec_ritz,n,m);

// erreur
for (int i=0; i<m; i++) lambda[i]=val[i][0];
err=erreur_check(A,vec,lambda,n,m);
printf("veleur propres \n");
afficher_tableau(lambda,m);
printf("vect propres \n");
afficher_matrice(vec,n,m );
if(err< eps) exit(0);
else {
for (int i=0; i<n ; i++) x[i]=vec[i][0];
}
}
// desallouer la memoire 
free(C);

for (int i=0;i<m;i++) free(bm[i]);
free(bm);
free(cm);
free(bm_l);

for (int i=0;i<n;i++) free(Vm[i]);
free(Vm);
for (int i=0;i<m;i++) free(bmcm[i]);
free(bmcm);
for (int i=0;i<n;i++) free(vec_ritz[i]);
free(vec_ritz);
free(lambda);
}

