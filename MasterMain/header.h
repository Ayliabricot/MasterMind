#ifndef MASTERMIND
#define MASTERIND

typedef struct {
	char couleur[9];
}Couleur;

Couleur** creerCombinaison(int taille);
Couleur* definirCouleur(char couleur[9]);

#endif