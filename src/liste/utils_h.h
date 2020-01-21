#ifndef UTILS_H
#define UTILS_H

typedef struct S_Liste {
  int *tab;
  int nbElement;
} T_Liste;

void init_liste(T_Liste *liste, int nbElement);

int fusion_liste(T_Liste *dans, T_Liste quoi);

int get_Element(T_Liste liste, int idx);

int ajouter_Element(T_Liste *liste, int element);

int retire_de_la_liste(int idx, T_Liste *liste);

int est_inclus(int x, T_Liste liste);

#endif
