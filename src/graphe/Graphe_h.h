/**
 * @file      Graphe_h.h
 * @author    Raphael Bauvin, Johann De Almeida
 * @version   22012020
 * @date      22 Janvier 2020
 * @brief     Définit le type graphe et la librairie permettant de manipuler des
 *            graphes
 *
 */
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
 * @brief Permet de mettre à jour le dégré d'un sommet passé en paramètre
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 * @param sommet : int  le sommet
 *
 * @return degres : int le degré du sommet, -1 sinon
 *
 **/
int get_degres(T_Graphe *graphe, int sommet);

/**
 * @brief Permet de mettre à jour les dégrés des sommets du graphe
 *        Multiples appels de la fonction get_degres()
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 *
 * @return 1 si tout les sommets ont été mis à jour, 0 sinon
 *
 **/
int mettre_a_jour_degres(T_Graphe *graphe);

/**
 * @brief Permet de créer un arc entre deux sommets d'une graphe
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 * @param origine : int  un sommet
 * @param extremite : int  un second sommet
 *
 * @return 0 si l'ajout à fonctionner, -1 sinon
 *
 **/
int ajouter_arc(T_Graphe *graphe, int origine, int extremite);

/**
 * @brief Permet de supprimer un arc entre deux sommets d'une graphe
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 * @param origine : int  un sommet
 * @param extremite : int  un second sommet
 *
 * @return 0 si le retrait à fonctionner, -1 sinon
 *
 **/
int supprimer_arc(T_Graphe *graphe, int origine, int extremite);

/**
 * @brief Permet d'ouvrir un fichier dans le mode donné en paramètre
 *
 * @param filename : char*  le nom du fichier
 * @param mode : char*  le mode d'ouverture du fichier (lecture/ecriture...)
 *
 * @return 0 ou 1 si valide
 *
 **/
int ouvrir(char *filename, char *mode);

/**
 * @brief Permet de lire le nombre de sommet d'une matrice de graphe non orienté
 * dans un fichier et vérifie que le nombre de colonne soit égale au nombre de
 * ligne
 *
 * @param filename : char*  le nom du fichier
 *
 * @return nbL : int nombre de ligne si valide, -1 sinon
 *
 **/
int lecture_ligne_colonne(char *filename);

/**
 * @brief Permet d'écrire un graphe dans un fichier
 *
 * @param filename : char*  le nom du fichier
 * @param graphe : T_Graphe  le graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
int ecriture_fichier_graphe(char *filename, T_Graphe graphe);

/**
 * @brief Permet de lire un graphe non orienté à partir d'une matrice dans un
 *fichier
 *
 * @param filename : char*  le nom du fichier
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
int lecture_fichier_graphe(char *filename, T_Graphe *graphe);

/**
 * @brief Permet de controler si un graphe est bien non orienté
 *
 * @param graphe : T_Graphe  le graphe
 *
 * @return : bool (0/1) si valide
 *
 **/
int est_non_oriente(T_Graphe graphe);

/**
 * @brief Permet d'initialiser un graphe à partir d'une taille donnée en
 *paramètre
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 * @param nbS : int nombre de sommets du graphe
 *
 * @return -1 ou 0 si valide
 *
 **/
int init_graphe(T_Graphe *graphe, int nbS);

/**
 * @brief Permet de libérer les espaces mémoire du graphe
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 *
 **/
void detruire_graphe(T_Graphe *graphe);

/**
 * @brief Permet de générer aléatoirement un graphe non orienté
 *
 * @param graphe : T_Graphe*  l'adresse mémoire du graphe
 *
 * @return 0 si la création a fonctionné
 *
 **/
int generate_random_graphe(T_Graphe *graphe);

/**
 * @brief Permet d'afficher la matrice dans le terminal
 *
 * @param graphe : T_Graphe  le graphe
 *
 **/
void afficher_matrice(T_Graphe graphe);

#endif
