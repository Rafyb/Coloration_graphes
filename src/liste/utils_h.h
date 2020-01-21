#ifndef UTILS_H
#define UTILS_H

typedef struct S_Liste {
  int *tab;
  int nbElement;
} T_Liste;

/**
 * @brief Permet d'initialiser une liste avec un nombre d'élément passé en paramètre
 *
 * @param liste : T_Liste* contenant l'adresse mémoire de la liste
 * @param nbElement : int contenant le nombre d'éléments
 *
 **/
void init_liste(T_Liste *liste, int nbElement);

/**
 * @brief Permet de fusionner une liste dans une autre
 *
 * @param dans : T_Liste* contenant l'adresse mémoire de la liste
 * @param quoi : T_Liste contenant la liste à fusionner
 *
 * @return newSize : int la taille de la nouvelle liste
 **/
int fusion_liste(T_Liste *dans, T_Liste quoi);

/**
 * @brief Permet de récupérer l'index du sommet du graphe à partir de son index dans une liste
 *
 * @param quoi : T_Liste contenant la liste
 * @param idx : int contenant l'index
 *
 **/
int get_Element(T_Liste liste, int idx);

/**
 * @brief Permet d'ajouter un élément à une liste
 *
 * @param liste : T_Liste* contenant l'adresse mémoire de la liste
 * @param element : int contenant l'élément à ajouter
 *
 * @return newSize : int la taille de la nouvelle liste
 **/
int ajouter_Element(T_Liste *liste, int element);

/**
 * @brief Permet de retirer un élément d'une liste
 *
 * @param liste : T_Liste* contenant l'adresse mémoire de la liste
 * @param element : int contenant l'élément à ajouter
 *
 * @return la taille de la nouvelle liste
 **/
int retire_de_la_liste(int idx, T_Liste *liste);

/**
 * @brief Permet de savoir si un entier existe dans une liste
 *
 * @param liste : T_Liste contenant la liste
 * @param x : int contenant l'élément recherché
 *
 * @return 0
 **/
int est_inclus(int x, T_Liste liste);

#endif
