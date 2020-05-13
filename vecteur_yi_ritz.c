#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

double ** vecteur_yi_ritz(double ** bmcm, int m){
double *tab_M=malloc(m*m*sizeof(double));
double ** res= malloc ( m*sizeof(double*));
for (int i =0 ; i<m ; i++){
res[i]=malloc((m+1)*sizeof(double));
}
double *wr=malloc(m*sizeof(double));
double *wi=malloc(m*sizeof(double));
double *vr=malloc(m*m*sizeof(double));
//mat_scal(Identite, -lambda[i],Li, m);
//add_matrice(bmcm, Li , M,m );
//tab_M=lineariser_matrice( M,m,m);
tab_M=lineariser_matrice( bmcm,m,m);
val_vec_propre(tab_M,m,wr,wi,vr);

//for (int i=0; i<m*m ; i++) printf("\t %f",vr[i]);
for (int i=0; i<m ; i++){for (int j =0 ; j<m ; j++) res[j][i]=vr[i*m+j];}
for (int i=0; i<m ; i++) res[i][m]=wr[i];
return (res);
////
for (int i=0; i<m ; i++) free(res[i]);
free(res); 
 free(tab_M); free(wr); free(wi); free(vr);
}


/*int main(){ int m=3;
double ** res= malloc ( (m+1)*sizeof(double*));
for (int i =0 ; i<m ; i++){
res[i]=malloc(m*sizeof(double));
}

double ** bmcm=malloc ( m*sizeof(double*));
for (int i =0 ; i<m ; i++){
bmcm[i]=malloc(m*sizeof(double));
}
for(int i=0; i<m ;i++)
{
for(int j=0; j<m ;j++){ scanf("%lf",&bmcm[i][j]);
}}
res=vecteur_yi_ritz(bmcm,m);
for(int i=0; i<m ;i++)
{printf("\n");
for(int j=0; j<=m ;j++){ printf("%f\t",res[i][j]);
}}
// desallouer 

for (int i =0 ; i<m ; i++) free(res[i]);
free(res);
for (int i =0 ; i<m ; i++) free(bmcm[i]);
free(bmcm);
}*/
