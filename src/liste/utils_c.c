#include "utils_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_liste(T_Liste *liste, int nbElement) {
  liste->tab = malloc(sizeof(int) * nbElement);
  liste->nbElement = nbElement;
  for (int i = 0; i < nbElement; i++) {
    liste->tab[i] = 0;
  }
}

int fusion_liste(T_Liste *dans, T_Liste *quoi) {
  int newSize = dans->nbElement + quoi->nbElement;
  int *newTab = malloc(sizeof(int) * (newSize));
  int i = 0;
  int j = 0;
  for (int idx = 0; idx < newSize; idx++) {
    if (i < dans->nbElement) {
      newTab[idx] = dans->tab[i++];
    } else {
      newTab[idx] = quoi->tab[j++];
    }
  }
  dans->nbElement = newSize;
  dans->tab = newTab;
  return newSize;
}

int get_Element(T_Liste liste, int idx) { return liste.tab[idx]; }

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

int est_inclus(int x, T_Liste liste) {
  for (int i = 0; i < liste.nbElement; i++) {
    if (liste.tab[i] == x) {
      return 1;
    }
  }
  return 0;
}

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
  init_liste(&maListe2, 5);
  maListe2.tab[0] = 6;
  maListe2.tab[1] = 7;
  maListe2.tab[2] = 8;
  maListe2.tab[3] = 9;
  maListe2.tab[4] = 10;

  fusion_liste(&maListe, &maListe2);
  for (int i = 0; i < maListe.nbElement; i++)
    printf("%d ", maListe.tab[i]);
  printf("\n");

  if (est_inclus(6, maListe))
    printf("6 est inclus dans la liste\n");
}
*/
