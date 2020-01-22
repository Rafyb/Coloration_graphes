/**
 * @file      utils_c.c
 * @author    Raphael Bauvin, Johann De Almeida
 * @version   22012020
 * @date      22 Janvier 2020
 * @brief     Définit le type liste et la librairie permettant de manipuler des
 *            listes
 *
 */
#include "utils_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Permet d'initialiser une liste avec un nombre d'élément passé en
 *        paramètre
 *
 * @param liste : T_Liste*  l'adresse mémoire de la liste
 * @param nbElement : int  le nombre d'éléments
 *
 **/
void init_liste(T_Liste *liste, int nbElement) {
  liste->tab = malloc(sizeof(int) * nbElement);
  liste->nbElement = nbElement;
  for (int i = 0; i < nbElement; i++) {
    liste->tab[i] = 0;
  }
}

/**
 * @brief Permet d'ajouter le contenu de la seconde liste dans la première
 *
 * @param dans : T_Liste*  l'adresse mémoire de la liste
 * @param quoi : T_Liste  la liste à fusionner
 *
 * @return newSize : int la taille de la nouvelle liste
 **/
int fusion_liste(T_Liste *dans, T_Liste quoi) {
  int newSize = dans->nbElement + quoi.nbElement;
  for (int idx = 0; idx < quoi.nbElement; idx++) {
    ajouter_Element(dans, quoi.tab[idx]);
  }
  return newSize;
}

/**
 * @brief Permet de récupérer un element de la liste à partir de son index
 *
 * @param quoi : T_Liste  la liste
 * @param idx : int  l'index
 *
 * @return int l'Element
 **/
int get_Element(T_Liste liste, int idx) { return liste.tab[idx]; }

/**
 * @brief Permet d'ajouter un élément à une liste
 *
 * @param liste : T_Liste*  l'adresse mémoire de la liste
 * @param element : int  l'élément à ajouter
 *
 * @return newSize : int la taille de la nouvelle liste
 **/
int ajouter_Element(T_Liste *liste, int element) {
  int newSize = liste->nbElement + 1;
  int *newTab = malloc(sizeof(int) * (newSize));
  int i = 0;
  for (int idx = 0; idx < newSize; idx++) {
    if (i < liste->nbElement) {
      newTab[idx] = liste->tab[i++];
    } else {
      newTab[idx] = element;
    }
  }
  liste->nbElement = newSize;
  free(liste->tab);
  liste->tab = newTab;
  return newSize;
}

/**
 * @brief Permet de retirer un élément d'une liste
 *
 * @param liste : T_Liste*  l'adresse mémoire de la liste
 * @param element : int  l'élément à ajouter
 *
 * @return la taille de la nouvelle liste
 **/
int retire_de_la_liste(int sommet, T_Liste *liste) {
  int oldTab[liste->nbElement];
  memcpy(oldTab, liste->tab, sizeof(int) * liste->nbElement);
  liste->tab = realloc(liste->tab, sizeof(int) * liste->nbElement - 1);
  int j = 0;
  for (int i = 0; i <= liste->nbElement; i++) {
    if (oldTab[i] != sommet) {
      liste->tab[j++] = oldTab[i];
    }
  }
  liste->nbElement = liste->nbElement - 1;
  return liste->nbElement;
}

/**
 * @brief Permet de savoir si un element existe dans une liste
 *
 * @param liste : T_Liste  la liste
 * @param x : int  l'élément recherché
 *
 * @return bool (°/1) si l'élément est inclus
 **/
int est_inclus(int x, T_Liste liste) {
  for (int i = 0; i < liste.nbElement; i++) {
    if (liste.tab[i] == x) {
      return 1;
    }
  }
  return 0;
}

/**
 * @brief Fonction permettant de tier de manière croissante une liste d'entiers
 *(select sort)
 *
 * @param liste : T_Liste* l'adresse mémoire de la liste d'entiers
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

// Cette partie n'est plus utilisé, cependant on la laissé si jamais il faut
// test une fonction des listes
/*
int main(void){
  T_Liste maListe;
  init_liste(&maListe, 5);
  maListe.tab[0] = 1;
  maListe.tab[1] = 2;
  maListe.tab[2] = 3;
  maListe.tab[3] = 4;
  maListe.tab[4] = 5;

  retire_de_la_liste(2, &maListe);
  for (int i = 0; i < maListe.nbElement; i++)
    printf("%d ", maListe.tab[i]);
  printf("\n");
  T_Liste maListe2;
  init_liste(&maListe2, 0);
  ajouter_Element(&maListe2,6);
  ajouter_Element(&maListe2,7);
  ajouter_Element(&maListe2,8);
  ajouter_Element(&maListe2,9);
  ajouter_Element(&maListe2,10);

  fusion_liste(&maListe, maListe2);
  for (int i = 0; i < maListe.nbElement; i++)
    printf("%d ", maListe.tab[i]);
  printf("\n");

  if (est_inclus(6, maListe))
    printf("6 est inclus dans la liste\n");
}
*/
