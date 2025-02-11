#ifndef MASTERMIND
#define MASTERIND

typedef struct {
	char couleur[9];
}Couleur;

Couleur*** creerTableauCombinaisons();
Couleur** creerCombinaison(int taille);
Couleur* definirCouleur(char couleur[9]);

void afficherCombinaison(Couleur** combinaison, int taille, char couleurs[9][9], char ansi[9][9]);
void remplirCombinaison(Couleur** combinaison, int taille, char couleurs[9][9]);
int verifier(Couleur** proposition, int taille, Couleur** reponse, Couleur** correction, char couleurs[9][9]);
void afficherTout(Couleur*** tableau_propositions, Couleur*** tableau_corrections, int tentatives, int taille, char couleurs[9][9], char ansi[9][9]);

#endif