#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <windows.h>

Couleur** creerCombinaison(int taille) {
	Couleur** nouvelle_combinaison = malloc(taille * sizeof(Couleur));
	for (int i = 0; i < taille; i++) {
		nouvelle_combinaison[i] = NULL;
	}
	return nouvelle_combinaison;
}

Couleur* definirCouleur(char couleur[9]) {
	Couleur* nouvelle_couleur = malloc(sizeof(Couleur));
	strcpy_s(nouvelle_couleur->couleur, sizeof(couleur), couleur);
	return nouvelle_couleur;
}

void afficherCombinaison(Couleur** combinaison, int taille, char couleurs[9][9], char ansi[9][5]) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < 9; j++) {
            if (strcmp(combinaison[i]->couleur,couleurs[j])==0) {
                printf("\033[%smO \033[0m", ansi[j]);
            }
        }
    }
}




