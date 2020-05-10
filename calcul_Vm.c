#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

void calcul_Vm(double **A, double **Vm, double *x, int n, int m ){
double *tmp=malloc(n*sizeof(double));
double *Ax=malloc(n*sizeof(double));
// initialisation 
for (int i =0; i<n;i++){
Vm[i][0]=x[i];
}
// V1....Vm-1
for (int j =1; j<m;j++){
for (int i =0; i<n;i++){Ax[i]=Vm[i][j-1];}

tmp=mat_vec(A,Ax,n);
for (int i =0; i<n;i++){Vm[i][j]=tmp[i];}   

}
free (tmp); free(Ax);

}
/*int main(){
double **A, **Vm,  *x; int n=3; int m=4;
A=malloc(n*sizeof(double*));
for (int i=0; i<n;i++){
	A[i]=malloc(n*sizeof(double));
		}
Vm=malloc(n*sizeof(double*));
for (int i=0; i<n;i++){
	Vm[i]=malloc(m*sizeof(double));
		}
x=malloc(n*sizeof(double));
for (int i=0; i<n;i++){
	for (int j=0; j<n;j++){
		scanf("%lf",&A[i][j]);

			}
		}

	for (int j=0; j<n;j++){
		scanf("%lf",&x[j]);

			}
calcul_Vm(A,Vm,x,  n, m );
for (int i=0; i<n;i++){ printf("\n");
	for (int j=0; j<m;j++){
		printf("%f\t",Vm[i][j]);
}}

free(x);
for(int i=0;i<n;i++) free(A[i]);
free(A);
for(int i=0;i<n;i++) free(Vm[i]);
free(Vm);
}*/
