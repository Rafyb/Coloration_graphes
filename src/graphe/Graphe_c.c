#include "Graphe_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Permet de récupérer le dégré d'un sommet passé en paramètre
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 * @param sommet : int contenant le sommet
 *
 * @return degres : int contenant le degré du sommet
 *
 **/
int get_degres(T_Graphe *graphe, int sommet) {
  int degres = 0;
  for (int ligne = 0; ligne < graphe->nbSommets; ligne++) {
    // if (ligne == sommet) {
    //  degres += 2 * graphe->matrice[ligne][sommet];
    //} else {
    degres += graphe->matrice[ligne][sommet];
    //}
  }
  graphe->degres[sommet] = degres;
  return degres;
}

/**
 * @brief Permet de mettre à jour les dégrés des sommets du graphe
 *        Multiples appels de la fonction get_degres()
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return 0
 *
 **/
int mettre_a_jour_degres(T_Graphe *graphe) {
  for (int sommet = 0; sommet < graphe->nbSommets; sommet++) {
    get_degres(graphe, sommet);
  }
  return 0;
}

/**
 * @brief Permet de créer un arc entre deux sommets d'une graphe
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 * @param origine : int contenant un sommet
 * @param extremite : int contenant un second sommet
 *
 * @return 0
 *
 **/
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

/**
 * @brief Permet de supprimer un arc entre deux sommets d'une graphe
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 * @param origine : int contenant un sommet
 * @param extremite : int contenant un second sommet
 *
 * @return 0
 *
 **/
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
 * @brief Permet d'ouvrir un fichier dans le mode donné en paramètre
 *
 * @param filename : char* contenant le nom du fichier
 * @param mode : char* contenant le mode d'ouverture du fichier (lecture/ecriture...)
 *
 * @return 0 ou 1 si valide
 *
 **/
int ouvrir(char *filename, char *mode) {
  fichier = fopen(filename, mode);
  if (fichier == NULL)
    return 0;
  return 1;
}

/**
 * @brief Permet de lire le nombre de sommet d'une matrice de graphe non orienté dans un fichier
 *
 * @param filename : char* contenant le nom du fichier
 *
 * @return -1 ou nbL : int nombre de ligne si valide
 *
 **/
int lecture_ligne_colonne(char *filename) {
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
 * @brief Permet d'écrire un graphe dans un fichier
 *
 * @param filename : char* contenant le nom du fichier
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
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
 * @brief Permet de lire un graphe non orienté à partir d'une matrice dans un fichier
 *
 * @param filename : char* contenant le nom du fichier
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
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
 * @brief Permet de controler si un graphe est bien orienté ou non
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return : bool (0/1) si valide
 *
 **/
int est_non_oriente(T_Graphe graphe) {
  for (int colonne = 0; colonne < graphe.nbSommets; colonne++) {
    for (int ligne = 0; ligne < graphe.nbSommets; ligne++) {
      if (graphe.matrice[colonne][ligne] != graphe.matrice[ligne][colonne])
        return 0;
    }
  }
  return 1;
}

/**
 * @brief Permet d'initialiser un graphe à partir d'une taille donnée en paramètre
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 * @param nbS : int nombre de sommets du graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
int init_graphe(T_Graphe *graphe, int nbS) {
  if (nbS < 1)
    return -1;
  graphe->nbSommets = nbS;
  graphe->matrice = (int **)malloc(sizeof(int *) * nbS);
  graphe->coloration = (int *)malloc(sizeof(int) * nbS);
  graphe->degres = (int *)malloc(sizeof(int) * nbS);
  for (int ligne = 0; ligne < nbS; ligne++) {
    graphe->matrice[ligne] = (int *)malloc(sizeof(int) * nbS);
    graphe->coloration[ligne] = INCOLORE;
    graphe->degres[ligne] = 0;
    for (int colonne = 0; colonne < nbS; colonne++) {
      graphe->matrice[ligne][colonne] = 0;
    }
  }

  return 0;
}

/**
 * @brief Permet de libérer les espaces mémoire du graphe
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 **/
void detruire_graphe(T_Graphe *graphe) {
  free(graphe->matrice);
  free(graphe->coloration);
  free(graphe->degres);
}

/**
 * @brief Permet de générer aléatoirement un graphe orienté
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return 0
 *
 **/
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
 * @brief Permet d'afficher la matrice dans le terminal
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 **/
void afficher_matrice(T_Graphe graphe) {
  for (int ligne = 0; ligne < graphe.nbSommets; ligne++) {
    for (int colonne = 0; colonne < graphe.nbSommets; colonne++) {
      printf("%d ", graphe.matrice[ligne][colonne]);
    }
    printf("\n");
  }
}

