#include "Graphe_h.h"

int ajouter_arc(T_Graphe *graphe, int origine, int extremite) {
  if (origine < 0 || origine > graphe->nbSommets || extremite < 0 ||
      origine > graphe->nbSommets) {
    perror("Un des sommets n'existe pas");
    return -1;
  }
  graphe->matrice[origine][extremite] = 1;
  graphe->matrice[extremite][origine] = 1;
  return 0;
}

int supprimer_arc(T_Graphe *graphe, int origine, int extremite) {
  if (origine < 0 || origine > graphe->nbSommets || extremite < 0 ||
      origine > graphe->nbSommets) {
    perror("Un des sommets n'existe pas");
    return -1;
  }
  graphe->matrice[origine][extremite] = 0;
  graphe->matrice[extremite][origine] = 0;
  return 0;
}

/**
 * Done
 *
 */
int ouvrir(char *filename, char *mode) {
  fichier = fopen(filename, mode);
  if (fichier == NULL)
    return 0;
  return 1;
}

/**
 * Done
 *
 */
int lecture_ligne_colonne(char *filename) {
  // Fichier
  if (!ouvrir(filename, "r")) {
    perror("Impossible d'ouvrir le fichier");
    return -1;
  }

  int nbL = 0;
  int nbC = 0;
  int lu;

  do {
    lu = fgetc(fichier);
    if (lu == '\n') {
      nbL++;
    } else if (lu != EOF) {
      nbC++;
    }
  } while (lu != EOF);
  nbC = nbC / nbL;

  fclose(fichier);

  if (nbL != nbC) {
    perror("Ligne et Colonne de la matrice différente");
    return -1;
  }
  return nbL;
}

/**
 * Done
 *
 */
int lecture_fichier_graphe(char *filename, T_Graphe *graphe) {
  if (!ouvrir(filename, "r")) {
    perror("Impossible d'ouvrir le fichier");
    return -1;
  }

  for (int ligne = 0; ligne < graphe->nbSommets; ligne++) {
    for (int colonne = 0; colonne < graphe->nbSommets; colonne++) {
      (graphe->matrice[ligne][colonne]) = ((int)fgetc(fichier)) - 48;
    }
    if (fgetc(fichier) != '\n') {
      perror("Decalage dans la lecture du fichier");
      return -1;
    }
  }

  fclose(fichier);
  return 0;
}

/**
 * Done
 *
 */
int init_graphe(T_Graphe *graphe, int nbS) {
  if (nbS < 1)
    return -1;
  graphe->nbSommets = nbS;
  graphe->matrice = (int **)malloc(sizeof(int *) * nbS);

  for (int ligne = 0; ligne < nbS; ligne++) {
    graphe->matrice[ligne] = (int *)malloc(sizeof(int) * nbS);
    for (int colonne = 0; colonne < nbS; colonne++) {
      graphe->matrice[ligne][colonne] = 0;
    }
  }

  return 0;
}

/**
 * Done
 *
 */
int generate_random_graphe(T_Graphe *graphe) {
  srand(time(NULL));
  for (int ligne = 0; ligne < graphe->nbSommets; ligne++) {
    for (int colonne = 0; colonne < graphe->nbSommets; colonne++) {
      if ((rand() % 2) == 1) {
        ajouter_arc(graphe, ligne, colonne);
      } else {
        supprimer_arc(graphe, ligne, colonne);
      }
    }
  }
  return 0;
}

/**
 * Done
 *
 */
void afficher_matrice(T_Graphe graphe) {
  for (int ligne = 0; ligne < graphe.nbSommets; ligne++) {
    for (int colonne = 0; colonne < graphe.nbSommets; colonne++) {
      printf("%d ", graphe.matrice[ligne][colonne]);
    }
    printf("\n");
  }
}
