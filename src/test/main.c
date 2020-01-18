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

  welsh_powell(&graphe);

  printf("Les colorations : \n");
  for (int i = 0; i < graphe.nbSommets; i++) {
    printf("Sommet %d -> couleur %d\n", i + 1, graphe.coloration[i]);
  }
  printf("\n");
  if (coloration_est_valide(graphe))
    printf("Coloration valide !\n");
  return 0;
}
