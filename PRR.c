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

double eps=pow(10,-10); double kmax=4; double err=1; int NRHS=m-1;

// Allocation 
 double *C= malloc((2*m)*sizeof(double));
double **bm= malloc(m*sizeof(double*));
for (int i=0;i<m;i++) bm[i]=malloc(m*sizeof(double));
double * cm= malloc (m*sizeof(double));
double *bm_l=calloc (m*m,sizeof(double));
double **Vm= malloc(n*sizeof(double*));
for (int i=0;i<n;i++) Vm[i]=malloc(m*sizeof(double));
double **bmcm= malloc(m*sizeof(double*));
for (int i=0;i<m;i++) bmcm[i]=malloc(m*sizeof(double));
double **vec_ritz= calloc(n,sizeof(double*));
for (int i=0;i<n;i++) vec_ritz[i]=calloc((m+1),sizeof(double));
double *lambda=malloc(m*sizeof(double));
/////////////////////////////////////
normalisation(x,n);
for(int k=0;k<kmax;k++){
// Calcul des coefficient C
//printf("prr1\n");
C=C_computation (m,n,x,A );
// resolution du système (63) Yule-Walker
//printf("apres prr 2\n");
construction_matrice(C,m,bm);
//printf("apres prr3\n");
cm=construction_vecteur(C,m);
//printf("apres prr 4\n");
bm_l=lineariser_matrice(bm,m,m);
//printf("apres prr5\n");
resolution_systeme(bm_l,m, cm,NRHS);
//racines polynomes
racine_polynome(cm,m,val );
//afficher_matrice(val,m,2);
// Ritz vecteurs 
calcul_Vm(A,Vm,x,n,m);
//printf("apres prr8\n");
calcul_matrice_BmCm(bmcm,Vm,A,n,m );
//printf("apres prr9\n");
vec_ritz=vecteur_ritz(bmcm,Vm,n,m );
vec= copier( vec_ritz,n,m);
// erreur
for (int i=0; i<m; i++) lambda[i]=val[i][0];
err=erreur_check(A,vec,lambda,n,m);
printf("\n veleur propres \n");
afficher_tableau(lambda,m);
printf("vect propres \n");
afficher_matrice(vec,n,m );
if(err< eps) exit(0);
else {
for (int i=0; i<n ; i++) x[i]=vec[i][0];
printf("iteration= %d\n",k);
printf("erreur= %f \n",err);
}
}

// desallouer la memoire
free(C);
for (int i=0;i<m;i++) free(bm[i]);
free(bm);
free(cm);
for (int i=0;i<n;i++) free(Vm[i]);
free(Vm);
for (int i=0;i<m;i++) free(bmcm[i]);
free(bmcm);
for (int i=0;i<n;i++) free(vec_ritz[i]);
free(vec_ritz);
free(lambda);

free(bm_l);
printf("\nfin boucle\n"); 
}

