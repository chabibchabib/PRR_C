#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>

double produit_scalaire (double *x, double *y, int m);
double *mat_vec(double **A, double *x, int n);
double *C_computation (int m, int n, double * x, double **A );
void afficher_tableau( double *tab, int n );
void afficher_matrice( double **A, int n, int m );
