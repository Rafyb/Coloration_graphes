#include "Graphe_h.h"

/**
 * To Do
 *
 */
int ecriture_fichier_graphe(char *filename, T_Graphe graphe) {
  if (!ouvrir(filename, "w+")) {
    perror("Impossible d'ouvrir le fichier");
    return -1;
  }
  for (int ligne = 0; ligne < graphe.nbSommets; ligne++) {
    for (int colonne = 0; colonne < graphe.nbSommets; colonne++) {
    }
  }
  fclose(fichier);
  return 0;
}

int main(int argc, char **argv) {
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
      char *file = "";
      printf("Nom du fichier : ");
      scanf("%s", file);
      ecriture_fichier_graphe(file, graphe);
    }
  }

  afficher_matrice(graphe);
  return 0;
}
