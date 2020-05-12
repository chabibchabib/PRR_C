#include<stdlib.h>
#include<math.h>
#include<lapacke.h>
#include "header.h"

double norme_matricielle(double **A, int n){
double res=0.0;

for (int i=0;i<n;i++){
for (int j=0;j<n;j++){res=res+A[i][j]*A[i][j];
}
}
res=sqrt(res);
return res;
}
