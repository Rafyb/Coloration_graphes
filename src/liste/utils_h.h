/**
 * @file      utils_h.h
 * @author    Raphael Bauvin, Johann De Almeida
 * @version   22012020
 * @date      22 Janvier 2020
 * @brief     Définit le type liste et la librairie permettant de manipuler des
 *            listes
 *
 */
#ifndef UTILS_H
#define UTILS_H

typedef struct S_Liste {
  int *tab;
  int nbElement;
} T_Liste;

/**
 * @brief Permet d'initialiser une liste avec un nombre d'élément passé en
 *paramètre
 *
 * @param liste : T_Liste*  l'adresse mémoire de la liste
 * @param nbElement : int  le nombre d'éléments
 *
 **/
void init_liste(T_Liste *liste, int nbElement);

/**
 * @brief Permet d'ajouter le contenu de la seconde liste dans la première
 *
 * @param dans : T_Liste*  l'adresse mémoire de la liste
 * @param quoi : T_Liste  la liste à fusionner
 *
 * @return newSize : int la taille de la nouvelle liste
 **/
int fusion_liste(T_Liste *dans, T_Liste quoi);

/**
 * @brief Permet de récupérer un element de la liste à partir de son index
 *
 * @param quoi : T_Liste  la liste
 * @param idx : int  l'index
 *
 * @return int l'Element
 **/
int get_Element(T_Liste liste, int idx);

/**
 * @brief Permet d'ajouter un élément à une liste
 *
 * @param liste : T_Liste*  l'adresse mémoire de la liste
 * @param element : int  l'élément à ajouter
 *
 * @return newSize : int la taille de la nouvelle liste
 **/
int ajouter_Element(T_Liste *liste, int element);

/**
 * @brief Permet de retirer un élément d'une liste
 *
 * @param liste : T_Liste*  l'adresse mémoire de la liste
 * @param element : int  l'élément à ajouter
 *
 * @return la taille de la nouvelle liste
 **/
int retire_de_la_liste(int idx, T_Liste *liste);

/**
 * @brief Permet de savoir si un element existe dans une liste
 *
 * @param liste : T_Liste  la liste
 * @param x : int  l'élément recherché
 *
 * @return bool (°/1) si l'élément est inclus
 **/
int est_inclus(int x, T_Liste liste);

/**
 * @brief Fonction permettant de tier de manière croissante une liste d'entiers
 *(select sort)
 *
 * @param liste : T_Liste*  l'adresse mémoire de la liste d'entiers
 *
 **/
void selectionSort(T_Liste *liste);

#endif
