#include <stdio.h>
#include<stdlib.h>
#include "header.h"
#include <math.h>
#include<lapacke.h>

// resolution du système linéaire en utilisant la bibliothéque lapack
void resolution_systeme(double *A, int m, double *b,int NRHS){
	int lda=m;  int info;
int *tab=calloc(m,sizeof(int));
	LAPACK_dgetrf(&m,&m,A,&lda,tab,&info);
	char trans='N'; int ldb=m;
	LAPACK_dgetrs(&trans,&m,&NRHS,A,&lda,tab,b,&ldb,&info);

	free(tab);
}

