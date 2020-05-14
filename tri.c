#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "header.h"
// fonction tri pour trier un tableau de double de taille m;
int *tri( double *tab, int m, int r){
int *ind=malloc(m*sizeof(int));
int *res=malloc(r*sizeof(int));
 double aide,max =0.0;
  int PMAX,p;
for( int i=0;i<m;i++) ind[i]=i;
for (int i=0; i<m-1;i++){
    // Recherche du max à droite de module[i]
    PMAX=i;
    for (int j=i+1;j<m;j++)
      if (fabs(tab[j])>fabs(tab[PMAX])) PMAX=j;
    // Echange de module[i] avec le max
    aide=tab[i];
    tab[i]=tab[PMAX];
    tab[PMAX]=aide;
    p = ind[i];
    ind[i]=ind[PMAX];
    ind[PMAX]=p;
  }
for (int i=0; i<r; i++) res[i]=ind[i];
return res;
free(res);
free(ind);
}

/*int main(){ int m=5; int r=5;
double *tab=malloc(m*sizeof(double));
int *ind=malloc(r*sizeof(int));
for (int i=0; i<m;i++){ scanf("%lf",&tab[i]);}

ind =tri(tab,m,r);
for(int i=0; i<r;i++) printf("%d \t",ind[i]);
free(tab);
free(ind);
}*/
