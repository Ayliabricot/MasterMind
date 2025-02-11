#ifndef MASTERMIND
#define MASTERIND

typedef struct {
	char couleur[9];
}Couleur;

Couleur** creerCombinaison(int taille);
Couleur* definirCouleur(char couleur[9]);
void afficherCombinaison(Couleur** combinaison, int taille, char couleurs[9][9], char ansi[9][5]);

#endif