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

void afficherCombinaison(Couleur** combinaison, int taille) {
	for (int i = 0; i < taille; i++) {
	}
	int choix = -1;
    switch (choix) {
    case 0:
        printf("\033[0;31mOOOO \033[0m"); // Rouge
        break;
    case 1:
        printf("\033[0;33mOOOO \033[0m"); // Jaune
        break;
    case 2:
        printf("\033[0;34mOOOO \033[0m"); // Bleu
        break;
    case 3:
        printf("\033[0;35mOOOO \033[0m"); // Violet
        break;
    case 4:
        printf("\033[1;35mOOOO \033[0m"); // Rose
        break;
    case 5:
        printf("\033[0;91mOOOO \033[0m"); // Orange
        break;
    case 6:
        printf("\033[0;32mOOOO \033[0m"); // Vert
        break;
    case 7:
        printf("\033[0;37mOOOO \033[0m"); // Blanc
        break;
    default:
        printf("Erreur : couleur inconnue.\n");
        break;
    }

	
}



