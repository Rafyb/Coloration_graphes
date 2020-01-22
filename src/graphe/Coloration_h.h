/**
 * @file      Coloration_h.h
 * @author    Raphael Bauvin, Johann De Almeida
 * @version   22012020
 * @date      22 Janvier 2020
 * @brief     Définit les fonctions qui se repporte à la coloration de graphe
 *
 */

#include "../liste/utils_h.h"
#include "Graphe_h.h"

#ifndef COLORATION_H
#define COLORATION_H

/**
 * @brief Permet de supprimer une coloration existente d'une graphe
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 *
 **/
void supprimer_coloration(T_Graphe *graphe);

/**
 * @brief Controle si la coloration est valide en reparcourant les sommets
 *adjacents
 *
 * @param graphe : T_Graphe  le graphe
 *
 * @return bool (0/1) si valide
 *
 **/
int coloration_est_valide(T_Graphe graphe);

/**
 * @brief Ecrit la coloration des sommets dans un fichier donné en paramètre
 *
 * @param filename : Char*  le nom du fichier
 * @param graphe : T_Graphe  le graphe
 *
 * @return  0 ou -1 si non valide
 *
 **/
int ecriture_fichier_coloration(char *filename, T_Graphe graphe);

/**
 * @brief Lis une coloration de sommets dans un fichier donné en paramètre
 *
 * @param filename : Char*  le nom du fichier
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 *
 * @return  0 ou -1 si non valide
 *
 **/
int lecture_fichier_coloration(char *filename, T_Graphe *graphe);

/**
 * @brief Fonction permettant de connaitre les sommets adjacents à un sommet
 *donné en paramètre
 *
 * @param sommet : int  le sommet
 * @param graphe : T_Graphe  le graphe
 *
 * @return sAdjacent : T_Liste*  la liste des sommets adjacents
 *
 **/
T_Liste *liste_sommets_adjacent(int sommet, T_Graphe graphe);

/**
 * @brief Permet d'afficher les sommets et leurs adjacents
 *
 * @param graphe : T_Graphe  le graphe
 *
 * @return 0
 *
 **/
int ecriture_sommets_adjacents(T_Graphe graphe);

/**
 * @brief Permet de récupérer la liste des sommets trié par degrés décroissants
 *
 * @param tab : int* un tableau de sommets
 * @param nbSommets : int  le nombre de sommets
 *
 * @return  T_Liste* la liste des sommets trié
 *
 **/
T_Liste *liste_sommets_degres_decroissant(int *tab, int nbSommets);

/**
 * @brief Fonction de l'algorithme de coloration de Welsh Powell
 *
 * @param graphe : T_Graphe*  le graphe à colorer
 *
 * @return 0 si la coloration à fonctionner, -1 sinon
 *
 **/
int welsh_powell(T_Graphe *graphe);

/**
 * @brief Fonction de l'algorithme de coloration Glouton
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe à colorer
 *
 * @return 0 si la coloration à fonctionner, -1 sinon
 *
 **/
int glouton(T_Graphe *graphe);

/**
 * @brief Permet de retourner le nombre de couleurs d'une graphe
 *
 * @param graphe : T_Graphe  le graphe coloré
 *
 * @return int : nombre de couleur utiliser pour le graphe
 *
 **/
int nombre_de_couleurs(T_Graphe graphe);

/**
 * @brief Variante de l'Algorithme Glouton sur base d'une liste ordonnée de
 *        sommet/degrés ( test de recherche et d'expérimentation )
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 *
 * @return 0 si la coloration à fonctionner, -1 sinon
 *
 **/
int glouton_ordonne(T_Graphe *graphe);

#endif
