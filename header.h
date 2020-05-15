#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<lapacke.h>

double produit_scalaire (double *x, double *y, int m);   // Fonction produit scalaire 
//double * mat_vec(double **A, double *x, int n);   // Produit Matrice vecteur 
double * mat_vec(double ** A, double *x, int n, int m);
double *C_computation (int m, int n, double * x, double **A );  // Calcul des coefficient C (voir la documentation)
void afficher_tableau( double *tab, int n ); // Affichage d'un tableau 
void afficher_matrice( double **A, int n, int m ); // Affichage d'un tableau
double* lineariser_matrice( double **A, int N, int M); // Lineariser une matrice 
void fact_matrice (double *tab, int m, double **A); // Passer d'un tableau à matrice
void construction_matrice(double *c, int m, double **M);   // Construction de la matrice H 
double * construction_vecteur(double *c, int m); // Construction de la matrice b
void resolution_systeme(double *A, int m, double *b,int NRHS); // Fonction pour résoudre le SYSTEME
void matrice_companion(double *b,int m, double *H);      // Matrice companion d'un polynome 
void val_vec_propre(double *B, int n, double *wr, double *wi, double *vr);  // vecteurs propres 
void racine_polynome(double *b, int m, double *racines );  // Polynomes 
void transpose(double **A, int m, int n, double **At); // transpose matrice
void mat_mat(double **A, double **B, double **C, int n, int m,int r); // produit matrice matrice 
void mat_scal(double **A, double lambda, double ** C, int n ); // Produit matrice scalaire 
void add_matrice(double **A, double **B , double** C, int n);
void iidentite_generateur(double **A, int n); // generer l'identité
void inverse_matrice(double *A, int n); // inverser une matrice
void calcul_Vm(double **A, double **Vm, double *x, int n, int m );
void calcul_matrice_BmCm(double **bmcm, double **Vm, double **A, int n, int m );
double norme_matricielle(double **A, int n);
//double * svd_svd(double *A, int n, int m);
double ** vecteur_yi_ritz(double ** bmcm, int m);
double **vecteur_ritz(double ** bmcm, double **Vm, int n,int m );
double norme_vec(double *tab, int n);
void sort(double *t, int n );
//double erreur_check(double **A, double ** res, int n, int m);
double erreur_check(double **A, double ** res,double *lambda, int n, int r, int *ind);
double ** copier( double **A, int n, int m);
void PRR(int n, int m , int r, double **A,double **vec, double *val, double *x );
int *tri(double *tab, int m,int r);
void sortInsert(double* t, double* tt, double* v, int n);
void normaliser_matrice_colonne(double **vec, int n, int r);




