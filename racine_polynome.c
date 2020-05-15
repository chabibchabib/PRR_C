#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

void racine_polynome(double *b, int m, double *racines ){
double *H=calloc(m*m,sizeof(double));
matrice_companion(b, m,H);
afficher_tableau(H,m*m);
double *wr=calloc(m,sizeof(double));
 double *wi=calloc(m,sizeof(double));
double *vr=calloc(m*m,sizeof(double));
val_vec_propre(H,m,wr,wi,vr);
for(int i=0; i<m;i++){
//racines[i][0]=wr[i];
//racines[i][1]=wi[i];
racines[i]=wr[i];
}
//for(int i=0; i<m;i++) printf("racine %d: \n%f+i %f\n",i+1, wr[i],wi[i]);

free(H); free(wr); free(wi); free(vr);
} // Fin racine polynome 







///////////////////////////////////////
/*

void matrice_companion(double *b,int m, double *H){
if(b[m]!=0) { double coef=b[m];
for (int i=0; i<m;i++) H[i]=0;
	for(int k=1;k<=m;k++) H[k-1]=-b[m-k]/b[m];
	for(int j=1;j<m;j++) H[m*j+(j-1)]=1;

}
}
//////////////////////////////////////////
void val_vec_propre(double *B, int n, double *wr, double *wi, double *vr){
	char balanc= 'B';
	char jobvl = 'N';
	char jobvr = 'V'; 
	char sense = 'V';
	int ldb = n;
	int ldvl = n;
	double* vl = calloc(ldvl*n,sizeof(double));
	int ldvr = n; 
	int ilo=0, ihi=0;
	double* scale = calloc(n,sizeof(double));
	double abnrm=0.;
	double* rconde = calloc(n,sizeof(double));
	double* rcondv = calloc(n,sizeof(double));
	int *iwork = calloc(2*n-2,sizeof(int));
	double wkopt=0.;
	int lwork = -1;
	int info; 	LAPACK_dgeevx(&balanc,&jobvl,&jobvr,&sense,&n,B,&ldb,wr,wi,vl,&ldvl,vr,&ldvr,&ilo,&ihi,scale,&abnrm,rconde,rcondv,&wkopt,&lwork,iwork,&info);
	lwork = (int)wkopt;
	double* work = calloc(lwork,sizeof(double));	LAPACK_dgeevx(&balanc,&jobvl,&jobvr,&sense,&n,B,&ldb,wr,wi,vl,&ldvl,vr,&ldvr,&ilo,&ihi,scale,&abnrm,rconde,rcondv,work,&lwork,iwork,&info);
	if( info > 0 ) {
		printf( "Erreur: Valeurs et vecteurs propres non calculés.\n" );
		exit( 1 );
	}
	free(vl);free(scale);free(rconde);free(rcondv);free(iwork);free(work);
}
/////////////////////////////////////////////////////////::::




void racine_polynome(double *b, int m, double **racines ){
double *H=calloc(m*m,sizeof(double));
matrice_companion(b, m,H);
double *wr=calloc(m,sizeof(double));
 double *wi=calloc(m,sizeof(double));
double *vr=calloc(m*m,sizeof(double));
val_vec_propre(H,m,wr,wi,vr);
for(int i=0; i<m;i++){
racines[i][0]=wr[i];
racines[i][1]=wi[i];
}
for(int i=0; i<m;i++) printf("racine %d: \n%f+i %f\n",i+1, racines[i][0],racines[i][1]);

free(H); free(wr); free(wi); free(vr);
} // Fin racine polynome 

int main(){
int n=3;
double **racine=malloc(n*sizeof(double*));
for(int i=0; i<n;i++) racine[i]=malloc(n*sizeof(double));
double *b =malloc((n+1)*sizeof(double));
for(int i=0; i<=n;i++) scanf("%lf", &b[i]);
racine_polynome(b,n,racine);
}
*/

