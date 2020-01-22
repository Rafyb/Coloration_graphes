#include "../liste/utils_h.h"
#include "Coloration_h.h"
#include "Graphe_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief Controle si la coloration est valide en reparcourant les sommets adjacents
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return bool (0/1) si valide
 *
 **/
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

/**
 * @brief Ecrit la coloration des sommets dans un fichier donné en paramètre
 *
 * @param filename : Char* contenant le nom du fichier
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return  0 ou -1 si non valide
 *
 **/
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

/**
 * @brief Lis une coloration de sommets dans un fichier donné en paramètre
 *
 * @param filename : Char* contenant le nom du fichier
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return  0 ou -1 si non valide
 *
 **/
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

/**
 * @brief Fonction permettant de connaitre les sommets adjacents à un sommet donné en paramètre
 *
 * @param sommet : int contenant le sommet (son index dans le graphe)
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return sAdjacent : T_Liste* contenant la liste des sommets adjacents
 *
 **/
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

/**
 * @brief Permet de tier de manière décroissante les sommets par leur degré
 *
 * @param tab : int* un tableau de sommets
 * @param nbSommets : int contenant le nombre de sommets
 *
 * @return 0
 *
 **/
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

/**
 * @brief Fonction de l'algorithme de Welsh Powell
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return 0
 *
 **/
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

/**
 * @brief Fonction permettant de tier de manière croissante une liste d'entiers (select sort)
 *
 * @param liste : T_Liste* contenant l'adresse mémoire de la liste d'entiers
 *
 **/
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

/**
 * @brief Fonction de l'algorithme Glouton
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return 0
 *
 **/
int glouton(T_Graphe *graphe) {
  int sommet = 0;
  // Tant qu'il existe des un sommet INCOLORE
  while (sommet < graphe->nbSommets) {
    // La couleur est initialisée à la plus petite valeur, soit 0
    int color = 0;
    // Si le sommet est INCOLORE
    if (graphe->coloration[sommet] == INCOLORE) {
      // Je déclare et initalise ma liste de sommets adjacents
      T_Liste *sAdjacent = liste_sommets_adjacent(sommet, *graphe);
      // Je déclare la liste cAdjacentes (couleurs adjacentes)
      T_Liste cAdjacentes;
      init_liste(&cAdjacentes, 0);
      // Pour chaque sommet adjacent je récupère la couleur
      for (int i = 0; i < sAdjacent->nbElement; i++) {
        // La couleur est ajoutée dans la liste cAdjacentes
        ajouter_Element(&cAdjacentes,
                        graphe->coloration[get_Element(*sAdjacent, i)]);
      }
      // Je trie ma liste de façon croissante afin de réduire le temps de
      // traitement
      selectionSort(&cAdjacentes);
      // Tant que la couleur existe déjà sur les sommets adjacents, je
      // l'incrémente
      while (est_inclus(color, cAdjacentes)) {
        color++;
      }
      // Je set la couleur à mon sommet INCOLORE
      graphe->coloration[sommet] = color;
      free(sAdjacent);
      // free(&cAdjacentes);
    }
    // Je passe au sommet suivant
    sommet++;
  }
  return 0;
}

/**
 * @brief Permet de supprimer une coloration existente d'une graphe
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 **/
void supprimer_coloration(T_Graphe *graphe) {
  free(graphe->coloration);
  graphe->coloration = (int *)malloc(sizeof(int) * graphe->nbSommets);
  for (int idx = 0; idx < graphe->nbSommets; idx++) {
    graphe->coloration[idx] = INCOLORE;
  }
}

int nombre_de_couleurs(T_Graphe graphe) {
  int couleur_max = INCOLORE;

  for (int i=0; i < graphe.nbSommets; i++) {
	if(graphe.coloration[i] > couleur_max){
		couleur_max = graphe.coloration[i];
	}
	else{
		continue;
	}
  }
  return couleur_max+1;
}

int ecriture_sommets_adjacents(T_Graphe graphe) {
  printf("Adjacences : \n\n");
  for (int i=0; i < graphe.nbSommets; i++) {
	printf("Sommet %d (%d):", i, graphe.degres[i]);
	T_Liste *adjacents = liste_sommets_adjacent(i, graphe);
	for(int j=0; j < adjacents->nbElement; j++){
		printf(" %d", get_Element(*adjacents, j));
	}
	printf("\n");
  }
  printf("\n");
  return 0;
}
