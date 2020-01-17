#include "Graphe_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fichier;

/*int welsh_powell(T_Graphe *graphe) {
  int color = 0;
  return 0;
}
*/

int *sommets_par_degres_decroissant(int *tab, int nbSommets) {
  int *sommet = malloc(sizeof(int) * nbSommets);
  int degres[nbSommets];
  memcpy(degres, tab, sizeof(int) * nbSommets);

  for (int idx = 0; idx < nbSommets; idx++) {
    int grand = idx;
    for (int test = 0; test < nbSommets; test++) {
      if (degres[grand] < degres[test]) {
        grand = test;
      }
    }

    sommet[idx] = grand;
    printf("le plus grand est : %d\n", degres[grand]);
    printf("son index est %d\n", sommet[idx]);
    degres[grand] = -1;
  }
  return sommet;
}

int get_degres(T_Graphe *graphe, int sommet) {
  int degres = 0;
  for (int ligne = 0; ligne < graphe->nbSommets; ligne++) {
    if (ligne == sommet) {
      degres += 2 * graphe->matrice[ligne][sommet];
    } else {
      degres += graphe->matrice[ligne][sommet];
    }
  }
  graphe->degres[sommet] = degres;
  return degres;
}

int mettre_a_jour_degres(T_Graphe *graphe) {
  for (int sommet = 0; sommet < graphe->nbSommets; sommet++) {
    get_degres(graphe, sommet);
  }
  return 0;
}

int ajouter_arc(T_Graphe *graphe, int origine, int extremite) {
  if (origine < 0 || origine > graphe->nbSommets || extremite < 0 ||
      origine > graphe->nbSommets) {
    perror("Un des sommets n'existe pas");
    return -1;
  }
  graphe->matrice[origine][extremite] = 1;
  graphe->matrice[extremite][origine] = 1;
  graphe->degres[origine] += 1;
  graphe->degres[extremite] += 1;
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
  graphe->degres[origine] -= 1;
  graphe->degres[extremite] -= 1;
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
int ecriture_fichier_graphe(char *filename, T_Graphe graphe) {
  if (!ouvrir(filename, "w+")) {
    perror("Impossible d'ouvrir le fichier");
    return -1;
  }
  for (int ligne = 0; ligne < graphe.nbSommets; ligne++) {
    for (int colonne = 0; colonne < graphe.nbSommets; colonne++) {
      fputc(graphe.matrice[ligne][colonne] + 48, fichier);
    }
    fputc('\n', fichier);
  }
  fclose(fichier);
  return 0;
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
      if (((int)fgetc(fichier) - 48) == 1)
        ajouter_arc(graphe, ligne, colonne);
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
  int sommet = 0;
  graphe->nbSommets = nbS;
  graphe->idxSommets = malloc(sizeof(int) * nbS);
  graphe->matrice = (int **)malloc(sizeof(int *) * nbS);
  graphe->coloration = (int *)malloc(sizeof(int) * nbS);
  graphe->degres = (int *)malloc(sizeof(int) * nbS);
  for (int ligne = 0; ligne < nbS; ligne++) {
    graphe->matrice[ligne] = (int *)malloc(sizeof(int) * nbS);
    graphe->coloration[ligne] = INCOLORE;
    graphe->degres[ligne] = 0;
    graphe->idxSommets[ligne] = sommet++;
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
