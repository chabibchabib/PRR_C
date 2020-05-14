
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

void computeInitPRR(double *q, int n, double **VA, int m,int r ){
	int j=0,k=0;
        for (int i =0 ; i<n;i++) q[i]=0.0;   
	for(j=0;j<n;j++){
		for(k=0;k<m;k++){
			q[j]+=(k+1)*VA[k][j];
		}
	}
}
