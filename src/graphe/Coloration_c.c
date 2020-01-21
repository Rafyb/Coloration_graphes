#include "../liste/utils_h.h"
#include "Coloration_h.h"
#include "Graphe_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coloration_est_valide(T_Graphe graphe) {
  for (int sommet = 0; sommet < graphe.nbSommets; sommet++) {
    T_Liste *sAdjacent = liste_sommets_adjacent(sommet, graphe);
    for (int adjacent = 0; adjacent < sAdjacent->nbElement; adjacent++) {
      if ((graphe.coloration[sommet] ==
           graphe.coloration[sAdjacent->tab[adjacent]]) &&
          (sommet != sAdjacent->tab[adjacent]))
        return 0;
    }
  }
  return 1;
}

int ecriture_fichier_coloration(char *filename, T_Graphe graphe) {
  if (!ouvrir(filename, "w+")) {
    perror("Impossible d'ouvrir le fichier");
    return -1;
  }

  for (int colonne = 0; colonne < graphe.nbSommets; colonne++) {
    fprintf(fichier, "%d", graphe.coloration[colonne]);
    if (colonne != graphe.nbSommets - 1) {
      fputc(',', fichier);
    }
  }

  fclose(fichier);
  return 0;
}

int lecture_fichier_coloration(char *filename, T_Graphe *graphe) {
  if (!ouvrir(filename, "r")) {
    perror("Impossible d'ouvrir le fichier");
    return -1;
  }
  int nb;
  char virgule;

  for (int colonne = 0; colonne < graphe->nbSommets; colonne++) {
    fscanf(fichier, "%d", &nb);
    fscanf(fichier, "%c", &virgule); // pour passer le ","
    graphe->coloration[colonne] = nb;
  }

  fclose(fichier);
  return 0;
}

T_Liste *liste_sommets_adjacent(int sommet, T_Graphe graphe) {
  T_Liste *sAdjacent = malloc(sizeof(T_Liste));
  init_liste(sAdjacent, graphe.degres[sommet]);
  int idx = 0;
  for (int ligne = 0; ligne < graphe.nbSommets; ligne++) {
    if (graphe.matrice[ligne][sommet] == 1) {
      sAdjacent->tab[idx++] = ligne;
    }
  }
  return sAdjacent;
}

T_Liste *liste_sommets_degres_decroissant(int *tab, int nbSommets) {
  T_Liste *sTrie = malloc(sizeof(T_Liste));
  init_liste(sTrie, nbSommets);

  int degres[nbSommets];
  memcpy(degres, tab, sizeof(int) * nbSommets);

  for (int idx = 0; idx < nbSommets; idx++) {
    int grand = idx;
    for (int test = 0; test < nbSommets; test++) {
      if (degres[grand] < degres[test]) {
        grand = test;
      }
    }
    sTrie->tab[idx] = grand;
    degres[grand] = -1;
  }
  return sTrie;
}

int welsh_powell(T_Graphe *graphe) {
  // La liste des sommets trié
  T_Liste *sommets =
      liste_sommets_degres_decroissant(graphe->degres, graphe->nbSommets);
  // La couleur
  int color = 0;

  // Tant qu'il existe des elements dans la liste des sommets
  while (sommets->nbElement > 0) {
    int sommet = get_Element(*sommets, 0);

    if (graphe->coloration[sommet] == INCOLORE) {
      // On colore le sommet courant et on le retire de la liste
      graphe->coloration[sommet] = color;

      // On parcourt les sommets et on colore les sommets non adjacent
      T_Liste *sAdjacent = liste_sommets_adjacent(sommet, *graphe);

      // pour tout sommet s dans la liste des sommets
      for (int i = 0; i < sommets->nbElement; i++) {
        int s = get_Element(*sommets, i);
        // si s n'est pas inclus dans Tsommet
        if ((!est_inclus(s, *sAdjacent)) && graphe->coloration[s] == INCOLORE) {
          graphe->coloration[s] = color;
          // Tsommet = Tsommet U Ts
          T_Liste *adjacents = liste_sommets_adjacent(s, *graphe);
          fusion_liste(sAdjacent, *adjacents);
          free(adjacents);
        }
      }
      color++;
    }
    // On retire le sommet coloré
    retire_de_la_liste(sommet, sommets);
  }
  return 0;
}

void selectionSort(T_Liste *liste) {
  int min_idx;

  for (int i = 0; i < liste->nbElement; i++) {
    min_idx = i;
    for (int j = i + 1; j < liste->nbElement; j++) {
      if (liste->tab[j] < liste->tab[min_idx]) {
        min_idx = j;
      }
    }
    int temp = liste->tab[min_idx];
    liste->tab[min_idx] = liste->tab[i];
    liste->tab[i] = temp;
  }
}
