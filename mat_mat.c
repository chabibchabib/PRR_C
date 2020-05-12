#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"
// mult mat (nxm) et mat (mxr)
void mat_mat(double **A, double **B, double **C, int n,int m, int r ){ 
double *col=malloc(n*sizeof(double));
double *res=malloc(n*sizeof(double));
for (int cpt=0; cpt<r;cpt++){
	for (int i =0;i<m;i++)  col[i]=B[i][cpt];

	res=mat_vec( A, col,  n,m);

	for (int i=0; i<n;i++) C[i][cpt]=res[i];

				}

free(col); free(res);
}

/*int main(){
double **A, **B,  **C; int n=3;
A=malloc(n*sizeof(double*));
for (int i=0; i<n;i++){
	A[i]=malloc(n*sizeof(double));
		}
B=malloc(n*sizeof(double*));
for (int i=0; i<n;i++){
	B[i]=malloc(n*sizeof(double));
		}
C=malloc(n*sizeof(double*));
for (int i=0; i<n;i++){
	C[i]=malloc(n*sizeof(double));
		}
for (int i=0; i<n;i++){
	for (int j=0; j<n;j++){
		scanf("%lf",&A[i][j]);

			}
		}
for (int i=0; i<n;i++){
	for (int j=0; j<n;j++){
		scanf("%lf",&B[i][j]);

			}
		}
mat_mat(A,B,C,n);
for (int i=0; i<n;i++){ printf("\n");
	for (int j=0; j<n;j++){
		printf("%f\t",C[i][j]);
}}
}*/
