#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"
void sortInsert(double* t, double* tt, double* v, int n){
	int i, j;
	double *h = calloc(n, sizeof(double));
	//module(t,tt,n,h);
	
	double* x=calloc(n,sizeof(double));
	double en_cours, tmr, tmp;
	for (i = 1; i < n; i++) {
		en_cours = h[i]; tmr= t[i]; tmp = tt[i];
		for(int k=0;k<n;k++){
			x[k] = v[i+n*k];
		}
		for (j = i; j > 0 && t[j - 1] < tmr; j--) {
			h[j] = h[j - 1];
			t[j] = t[j - 1];
			tt[j] = tt[j - 1];
			for(int k=0;k<n;k++){
				v[j+n*k] = v[(j-1)+n*k];
			}
		}
		h[j] = en_cours;
		t[j] = tmr;
		tt[j] = tmp;
		for(int k=0;k<n;k++){
			v[j+n*k] = x[k];
		}
	}
	//print_vec("module des valeurs propres trié",h,n);
	free(h);free(x);
}

