#include "../liste/utils_h.h"
#include "Graphe_h.h"

#ifndef COLORATION_H
#define COLORATION_H

/**
 * @brief Permet de supprimer une coloration existente d'une graphe
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 **/
void supprimer_coloration(T_Graphe *graphe);

/**
 * @brief Controle si la coloration est valide en reparcourant les sommets adjacents
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return bool (0/1) si valide
 *
 **/
int coloration_est_valide(T_Graphe graphe);

/**
 * @brief Ecrit la coloration des sommets dans un fichier donné en paramètre
 *
 * @param filename : Char* contenant le nom du fichier
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return  0 ou -1 si non valide
 *
 **/
int ecriture_fichier_coloration(char *filename, T_Graphe graphe);

/**
 * @brief Lis une coloration de sommets dans un fichier donné en paramètre
 *
 * @param filename : Char* contenant le nom du fichier
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return  0 ou -1 si non valide
 *
 **/
int lecture_fichier_coloration(char *filename, T_Graphe *graphe);

/**
 * @brief Fonction permettant de connaitre les sommets adjacents à un sommet donné en paramètre
 *
 * @param sommet : int contenant le sommet (son index dans le graphe)
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return sAdjacent : T_Liste* contenant la liste des sommets adjacents
 *
 **/
T_Liste *liste_sommets_adjacent(int sommet, T_Graphe graphe);

/**
 * @brief Permet de tier de manière décroissante les sommets par leur degré
 *
 * @param tab : int* un tableau de sommets
 * @param nbSommets : int contenant le nombre de sommets
 *
 * @return 0
 *
 **/
T_Liste *liste_sommets_degres_decroissant(int *tab, int nbSommets);

/**
 * @brief Fonction de l'algorithme de Welsh Powell
 *
 * @param graphe : T_Graphe contenant le graphe
 *
 * @return 0
 *
 **/
int welsh_powell(T_Graphe *graphe);

/**
 * @brief Fonction permettant de tier de manière croissante une liste d'entiers (select sort)
 *
 * @param liste : T_Liste* contenant l'adresse mémoire de la liste d'entiers
 *
 **/
void selectionSort(T_Liste *liste);

/**
 * @brief Fonction de l'algorithme Glouton
 *
 * @param graphe : T_Graphe* contenant l'adresse mémoire du graphe
 *
 * @return 0
 *
 **/
int glouton(T_Graphe *graphe);

int nombre_de_couleurs(T_Graphe graphe);

int ecriture_sommets_adjacents(T_Graphe graphe);

#endif
