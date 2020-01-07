#include <stdio.h>
#include <stdlib.h>

typedef struct S_Graphe {
  int **matrice;
  char *labels;
  char *colors;
} T_Graphe;

FILE *fichier;

int ouvrir(char *filename, char *mode) {
  fichier = fopen(filename, mode);
  if (fichier == NULL)
    return 0;
  return 1;
}

int nbColonne() {
  int nbC = 0;
  while (fgetc(fichier) != '\n') {
    nbC++;
  }
  printf("%d", nbC);
  return nbC;
}

int nbLigne() {
  int nbL = 0;
  int lu;
  do {
    lu = fgetc(fichier);
    if (lu == '\n')
      nbL++;
  } while (lu != EOF);
  printf("%d", nbL);
  return nbL;
}

T_Graphe *lecture_matrice(char *filename) {
  // Fichier
  if (!ouvrir(filename, "r")) {
    perror("Impossible d'ouvrir le fichier");
    return NULL;
  }
  // Création de la matrice
  int nbC = nbColonne();
  int nbL = nbLigne();
  if (nbL != nbC) {
    perror("Ligne et Colonne de la matrice différente");
    return NULL;
  }
  int **laMatrice = (int **)malloc(sizeof(int[nbL][nbC]));
  nbL = 0;
  nbC = 0;
  int lu;
  do {
    lu = fgetc(fichier);
    if (lu == '\n') {
      nbL++;
    } else {
      laMatrice[nbL][nbC] = (lu - 48);
      nbC++;
    }
  } while (lu != EOF);
  // Création du graphe
  T_Graphe *leGraphe = (T_Graphe *)malloc(sizeof(T_Graphe));
  leGraphe->matrice = laMatrice;
  // Fin de traitement
  fclose(fichier);
  return leGraphe;
}

void afficher_matrice(T_Graphe *graphe) {
  printf("%d\n", graphe->matrice[0][0]);
}

int main() {
  T_Graphe *graphe = lecture_matrice("graphe_read.txt");
  /*if (graphe == NULL) {
    perror("Erreur lecture graphe");
    return 1;
  }*/
  afficher_matrice(graphe);
  return 0;
}
