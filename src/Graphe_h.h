#define INCOLORE -1

typedef struct S_Graphe {
  int **matrice;   // La matrice d'adjacences
  int nbSommets;   // Le nombre de sommet du graphe
  int *idxSommets; // Indices des sommets
  int *degres;     // Les degres de chaque sommet
  int *coloration; // Les couleurs des sommets
} T_Graphe;

int *sommets_par_degres_decroissant(int *tab, int nbSommets);

int get_degres(T_Graphe *graphe, int sommet);

int mettre_a_jour_degres(T_Graphe *graphe);

int ajouter_arc(T_Graphe *graphe, int origine, int extremite);

int supprimer_arc(T_Graphe *graphe, int origine, int extremite);

int ouvrir(char *filename, char *mode);

int lecture_ligne_colonne(char *filename);

int ecriture_fichier_graphe(char *filename, T_Graphe graphe);

int lecture_fichier_graphe(char *filename, T_Graphe *graphe);

int init_graphe(T_Graphe *graphe, int nbS);

int generate_random_graphe(T_Graphe *graphe);

void afficher_matrice(T_Graphe graphe);
