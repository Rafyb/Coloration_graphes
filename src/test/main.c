#include "../graphe/Coloration_h.h"
#include "../graphe/Graphe_h.h"
#include "../liste/utils_h.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  srand(time(NULL));
  int nbSommets = 0;
  int isSaved = 0;
  T_Graphe graphe;

  // Lecture fichier
  if (argc > 1) {
    char *file = argv[1];
    nbSommets = lecture_ligne_colonne(file);
    init_graphe(&graphe, nbSommets);
    lecture_fichier_graphe(file, &graphe);
  }
  // Generation aléatoire
  else {
    printf("Veuillez entrer un nombre de sommets : ");
    scanf("%d", &nbSommets);
    init_graphe(&graphe, nbSommets);
    generate_random_graphe(&graphe);

    printf("Voulez-vous sauvegarder le graphe (1:Oui / 0:Non) : ");
    scanf("%d", &isSaved);
    if (isSaved == 1) {
      ecriture_fichier_graphe("test/graphe_write.txt", graphe);
    }
  }
  mettre_a_jour_degres(&graphe);
  afficher_matrice(graphe);

  if (est_non_oriente(graphe))
    printf("Le graphe est bien non orienté\n");

  welsh_powell(&graphe);

  printf("Les colorations : \n");
  for (int i = 0; i < graphe.nbSommets; i++) {
    printf("Sommet %d -> couleur %d\n", i + 1, graphe.coloration[i]);
  }
  printf("\n");
  if (coloration_est_valide(graphe))
    printf("Coloration valide !\n");
  ecriture_fichier_coloration("test/coloration_write.txt", graphe);
  lecture_fichier_coloration("test/coloration_write.txt", &graphe);
  if (coloration_est_valide(graphe))
    printf("Coloration valide !\n");

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

  fusion_liste(&maListe, maListe2);
  for (int i = 0; i < maListe.nbElement; i++)
    printf("%d ", maListe.tab[i]);
  printf("\n");

  if (est_inclus(6, maListe))
    printf("6 est inclus dans la liste\n");
}
