#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <windows.h>

int main() {
	srand(time(NULL));
	Couleur** combinaison = creerCombinaison(9);
	int tentatives = 0;
	int taille;

	char couleurs[9][9] = { "rouge","jaune","bleu","violet","rose","orange","vert","blanc" };
	char ansi[9][5] = { "0;31","0;33","0;34","0;35","1;35","0;91","0;32","0;37" };
	
	for (int i = 0; i < 8; i++) {
		combinaison[i] = definirCouleur(couleurs[i]);
	}

	taille = 4;
	Couleur** reponse = creerCombinaison(taille+1);
	for (int i = 0; i < taille; i++) {
		reponse[i] = definirCouleur(couleurs[rand()%8]);
	}

	Couleur*** tableau_combinaisons = creerTableauCombinaisons();

	while (tentatives < 10) {
		Couleur** proposition = creerCombinaison(taille + 1);
		remplirCombinaison(proposition, taille, couleurs);
		tableau_combinaisons[tentatives] = proposition;
		afficherCombinaison(tableau_combinaisons[0], taille, couleurs, ansi);
		printf("\n");
	}
	
	printf("\n");
	return 0;
}