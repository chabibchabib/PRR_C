#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

void normalisation(double *x, int n ){
double norme= norme_vec(x,n);
for(int i =0 ;i<n ; i++) x[i]=x[i]/norme;
} 
void PRR(int n, int m , int r, double **A,double **vec, double *val, double *x ){

double eps=pow(10,-10); double kmax=6; double err=1; int NRHS=m-1; 

// Allocation 
int *ind=calloc(r,sizeof(int));
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
//double *lambda=malloc(m*sizeof(double));
/////////////////////////////////////
normalisation(x,n);
for(int k=0;k<kmax;k++){
// Calcul des coefficient C
//printf("prr1\n");
C=C_computation (m,n,x,A );
// resolution du système (63) Yule-Walker
construction_matrice(C,m,bm);
cm=construction_vecteur(C,m);
bm_l=lineariser_matrice(bm,m,m);
resolution_systeme(bm_l,m, cm,NRHS);
//racines polynomes
//racine_polynome(cm,m,val );
// Ritz vecteurs 
calcul_Vm(A,Vm,x,n,m);
calcul_matrice_BmCm(bmcm,Vm,A,n,m );
vec_ritz=vecteur_ritz(bmcm,Vm,n,m );
for(int i=0; i<m; i++) val[i]=vec_ritz[i][m];
vec= copier( vec_ritz,n,m);
// erreur
//for (int i=0; i<m; i++) lambda[i]=val[i][0];
ind=tri(val,m,r);
for(int i=0;i<r;i++) {printf("tri : %d\n",ind[i]);}
//err=erreur_check(A,vec,val,n,m);
err=erreur_check(A,vec,val,n,r,ind);
printf("\n veleur propres \n");
afficher_tableau(val,m);
printf("vect propres \n");
afficher_matrice(vec,n,m );

if(err< eps) exit(0);
else {
//for (int i=0; i<n ; i++) x[i]=vec[i][ind[0]];
for (int i =0 ; i<n;i++) x[i]=0.0;   
	for(int j=0;j<n;j++){
		for(int c=0;c<r;c++){
			x[j]+=vec[j][ind[0]];
		}
	}
printf("vecteur de redemarrage choisi\n");
afficher_tableau(x,n);
printf("iteration= %d\n",k);
printf("erreur= %f \n",err);
}
}

// desallouer la memoire
free(ind);
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
//free(lambda);

free(bm_l);
printf("\nfin boucle\n"); 
}

