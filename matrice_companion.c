#include <stdio.h>
#include<stdlib.h>
#include "header.h"
#include <math.h>
#include<lapacke.h>


 void matrice_companion(double *b,int m, double *H){
if(b[m]!=0) { double coef=b[m];
for (int i=0; i<m;i++) H[i]=0;
	for(int k=1;k<=m;k++) H[k-1]=-b[m-k]/b[m];
	for(int j=1;j<m;j++) H[m*j+(j-1)]=1;

}
}

/*int main(){
int m=3; 
double *H=malloc(m*m*sizeof(double));
double *b=malloc((m+1)*sizeof(double));
for (int i=0; i<=m;i++) scanf("%lf",&b[i]);
matrice_companion(b,m, H);
for (int i=0; i<m*m;i++) printf("%f \t",H[i]);
printf("\n");
free(H);
free(b);
}*/
