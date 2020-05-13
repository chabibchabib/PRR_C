#include <stdio.h>
#include<stdlib.h>
#include "header.h"
#include <math.h>
#include<lapacke.h>

// resolution du système linéaire en utilisant la bibliothéque lapack
void resolution_systeme(double *A, int m, double *b,int NRHS){
	int lda=m;  int info=0;
int *tab=calloc(m,sizeof(int));
	LAPACK_dgetrf(&m,&m,A,&lda,tab,&info);
	char trans='N'; int ldb=m;
	LAPACK_dgetrs(&trans,&m,&NRHS,A,&lda,tab,b,&ldb,&info);
 printf("info resolution= %d\n",info);
//afficher_tableau(b,m);
	free(tab);
}
/*int main(){

double *A=malloc(4*sizeof (double));
double *c=malloc(2*sizeof (double));
int NRHS=2;
A[0]=1; A[1]=9; A[2]= 9; A[3]=87;
c[0]=-87;c[1]=-891;  
resolution_systeme(A,2,c,NRHS);
}*/
