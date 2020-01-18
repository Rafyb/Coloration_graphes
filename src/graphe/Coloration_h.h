#include "../liste/utils_h.h"
#include "Graphe_h.h"

#ifndef COLORATION_H
#define COLORATION_H

int coloration_est_valide(T_Graphe graphe);

int ecriture_fichier_coloration(char *filename, T_Graphe graphe);

int lecture_fichier_coloration(char *filename, T_Graphe *graphe);

T_Liste *liste_sommets_adjacent(int sommet, T_Graphe graphe);

T_Liste *liste_sommets_degres_decroissant(int *tab, int nbSommets);

int welsh_powell(T_Graphe *graphe);

#endif
