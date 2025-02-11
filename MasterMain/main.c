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
	int victoire = 0;
	int index = 0;
	int eviterDoublon[10] = { 0 };
	int doublon = 1;

	char couleurs[9][9] = { "rouge","jaune","bleu","violet","rose","orange","vert","blanc" };
	char ansi[9][9] = { "0;31","0;33","0;34","0;35","38;5;198","38;5;166","0;32","0;37" };
	
	Couleur*** tableau_combinaisons = creerTableauCombinaisons();
	Couleur*** tableau_corrections = creerTableauCombinaisons();

	for (int i = 0; i < 8; i++) {
		combinaison[i] = definirCouleur(couleurs[i]);
	}

	taille = 4;
	Couleur** reponse = creerCombinaison(taille+1);
	for (int i = 0; i < taille; i++) {
		while (doublon == 1) {
			doublon = 0;
			index = rand() % 8;
			if (i > 0) {
				for (int j = 0; j < taille; j++) {
					if (eviterDoublon[j] == index) {
						doublon = 1;
					}
				}
			}
		}
		reponse[i] = definirCouleur(couleurs[index]);
		eviterDoublon[i] = index;
		doublon = 1;
	}
	
	while (tentatives < 10 && victoire==0) {
		if (tentatives > 0) {
			system("cls");
			afficherTout(tableau_combinaisons, tableau_corrections, tentatives, taille, couleurs, ansi);
		}
		
		Couleur** proposition = creerCombinaison(taille + 1);
		Couleur** correction = creerCombinaison(taille + 1);

		remplirCombinaison(proposition, taille, couleurs);
		tableau_combinaisons[tentatives] = proposition;

		victoire = verifier(proposition, taille, reponse,correction,couleurs);
		
		tableau_corrections[tentatives] = correction;
	
		tentatives = tentatives + 1;
	}
	
	printf("\n");
	return 0;
}