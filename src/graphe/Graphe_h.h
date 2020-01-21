#include <stdio.h>

#ifndef GRAPHE_H
#define GRAPHE_H

typedef struct S_Graphe {
  int **matrice;   // La matrice d'adjacences
  int nbSommets;   // Le nombre de sommet du graphe
  int *degres;     // Les degres de chaque sommet
  int *coloration; // Les couleurs des sommets
} T_Graphe;

#define INCOLORE -1

FILE *fichier;

/**
 * @brief Permet de récupérer le dégré d'un sommet passé en paramètre
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 * @param sommet : int contenant le sommet
 *
 * @return degres : int contenant le degré du sommet
 *
 **/
int get_degres(T_Graphe *graphe, int sommet);

/**
 * @brief Permet de mettre à jour les dégrés des sommets du graphe
 *        Multiples appels de la fonction get_degres()
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return 0
 *
 **/
int mettre_a_jour_degres(T_Graphe *graphe);

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
int ajouter_arc(T_Graphe *graphe, int origine, int extremite);

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
int supprimer_arc(T_Graphe *graphe, int origine, int extremite);

/**
 * @brief Permet d'ouvrir un fichier dans le mode donné en paramètre
 *
 * @param filename : char* contenant le nom du fichier
 * @param mode : char* contenant le mode d'ouverture du fichier (lecture/ecriture...)
 *
 * @return 0 ou 1 si valide
 *
 **/
int ouvrir(char *filename, char *mode);

/**
 * @brief Permet de lire le nombre de sommet d'une matrice de graphe non orienté dans un fichier
 *
 * @param filename : char* contenant le nom du fichier
 *
 * @return -1 ou nbL : int nombre de ligne si valide
 *
 **/
int lecture_ligne_colonne(char *filename);

/**
 * @brief Permet d'écrire un graphe dans un fichier
 *
 * @param filename : char* contenant le nom du fichier
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
int ecriture_fichier_graphe(char *filename, T_Graphe graphe);

/**
 * @brief Permet de lire un graphe non orienté à partir d'une matrice dans un fichier
 *
 * @param filename : char* contenant le nom du fichier
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
int lecture_fichier_graphe(char *filename, T_Graphe *graphe);

/**
 * @brief Permet de controler si un graphe est bien orienté ou non
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return : bool (0/1) si valide
 *
 **/
int est_non_oriente(T_Graphe graphe);

/**
 * @brief Permet d'initialiser un graphe à partir d'une taille donnée en paramètre
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 * @param nbS : int nombre de sommets du graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
int init_graphe(T_Graphe *graphe, int nbS);

/**
 * @brief Permet de libérer les espaces mémoire du graphe
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 **/
void detruire_graphe(T_Graphe *graphe);

/**
 * @brief Permet de générer aléatoirement un graphe orienté
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return 0
 *
 **/
int generate_random_graphe(T_Graphe *graphe);

/**
 * @brief Permet d'afficher la matrice dans le terminal
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 **/
void afficher_matrice(T_Graphe graphe);

#endif
