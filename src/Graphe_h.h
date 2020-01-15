#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INCOLORE -1

typedef int *T_Coloration;

typedef struct S_Graphe {
  int **matrice; // La matrice d'adjacences
  int nbSommets; // Le nombre de sommet du graphe
  int *degres;   // Les degres de chaque sommet
  char *labels;  // Les noms de chaque sommet
} T_Graphe;

FILE *fichier;

int ajouter_arc(T_Graphe *graphe, int origine, int extremite);

int supprimer_arc(T_Graphe *graphe, int origine, int extremite);

/**
 * Done
 *
 */
int ouvrir(char *filename, char *mode);

/**
 * Done
 *
 */
int lecture_ligne_colonne(char *filename);

int ecriture_fichier_graphe(char *filename, T_Graphe graphe);

/**
 * Done
 *
 */
int lecture_fichier_graphe(char *filename, T_Graphe *graphe);

/**
 * Done
 *
 */
int init_graphe(T_Graphe *graphe, int nbS);

/**
 * To Do
 *
 */
int generate_random_graphe(T_Graphe *graphe);

/**
 * Done
 *
 */
void afficher_matrice(T_Graphe graphe);
