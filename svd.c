#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
double * svd_svd(double *A, int n, int m){
double *S=malloc(n*m*sizeof(double));
double *U=malloc(n*n*sizeof(double));
double *Vt=calloc(m*m,sizeof(double));
char JOBU='N'; char JOBVT= 'A';
int LDA=n; int LDU=n; int LDVT=m; int INFO; 
int LWORK= 5*fmin(n,m);
double *WORK=malloc(n*sizeof(LWORK));
LAPACK_dgesvd(&JOBU, &JOBVT, &n, &m, A,&LDA, S, U, &LDU, Vt, &LDVT,WORK,&LWORK,&INFO);
if (INFO !=0 ) printf("info svd = %d\n",INFO);
//printf("S:\n");
//for(int i=0;i<n*m;i++) printf("%f\t ",S[i]);
printf("\n Vt:\n");
//for(int i=0;i<n*n;i++) printf("%f\t ",U[i]);
//for(int i=0;i<m;i++){printf("\n");
for (int j=0;j<m*m;j++) printf("%f\t ",Vt[j]);
//}
printf("\n Vt2:\n");

printf("\n Vt3:\n");
free(U);
printf("\n Vt4:\n"); free(S);
printf("\n Vt5:\n"); free(WORK);
printf("\n Vt6:\n"); 
return Vt;
printf("\n Vt7:\n"); 
free(Vt);

}

/*int main(){
int n=3, m=3;
double *A= malloc(n*m*sizeof(double));
for (int i=0;i<n*m;i++){
scanf("%lf",&A[i]);
}
svd(A,n,m);
free(A);
}*/
