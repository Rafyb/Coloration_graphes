#include "../liste/utils_h.h"
#include "Coloration_h.h"
#include "Graphe_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

T_Liste *liste_sommets_adjacent(int sommet, T_Graphe graphe) {
  T_Liste *sAdjacent = malloc(sizeof(T_Liste));
  init_liste(sAdjacent, graphe.degres[sommet]);
  int idx = 0;
  for (int ligne = 0; ligne < sAdjacent->nbElement; ligne++) {
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
  // int color = 0;

  for (int i = 0; i < graphe->nbSommets; i++) {
    printf("%d ", graphe->degres[sommets->tab[i]]);
  }
  /*
  // Tant qu'il existe des elements dans la liste des sommets
  while (nbElement > 0) {
    int sommet = sommets[0];
    printf("Le sommet : %d\n", sommet);
    nbElement = retire_de_la_liste(sommet, sommets, nbElement);
    if (graphe->coloration[sommet] == INCOLORE) {
      // On colore le sommet courant et on le retire de la liste
      graphe->coloration[sommet] = color;
      printf("Sa couleur : %d\n", graphe->coloration[sommet]);

      // On parcourt les sommets et on colore les sommets non adjacent
      int *sAdjacent = get_sommets_adjacent(sommet, *graphe);
      int nbAdjacent = graphe->degres[sommet];
      // pour tout sommet s dans la liste des sommets
      for (int s = 0; s < nbElement; s++) {
        // si s n'est pas inclus dans Tsommet
        if (!est_inclus(sommets[s], sAdjacent, nbAdjacent) &&
            graphe->coloration[sommet] == INCOLORE) {
          graphe->coloration[s] = color;
          // Tsommet = Tsommet U Ts
          printf("De la même couleur : %d\n", s);
          nbAdjacent =
              fusion_tab(sAdjacent, nbAdjacent,
                         get_sommets_adjacent(s, *graphe), graphe->degres[s]);
        }
      }
      color++;
    }
  }*/
  return 0;
}
