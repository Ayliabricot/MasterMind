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

Couleur*** creerTableauCombinaisons() {
	Couleur*** nouveau_tableau = malloc(10 * sizeof(Couleur));
	for (int i = 0; i < 10; i++) {
		nouveau_tableau[i] = NULL;
	}
	return nouveau_tableau;
}

Couleur* definirCouleur(char couleur[9]) {
	Couleur* nouvelle_couleur = malloc(sizeof(Couleur));
	strcpy_s(nouvelle_couleur->couleur, sizeof(couleur), couleur);
	return nouvelle_couleur;
}

void afficherCombinaison(Couleur** combinaison, int taille, char couleurs[9][9], char ansi[9][9]) {
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < 8; j++) {
			if (strcmp(combinaison[i]->couleur, couleurs[j]) == 0) {
				printf("\033[%smO \033[0m", ansi[j]);
			}
			else if (strcmp(combinaison[i]->couleur, "noir") == 0) {
				printf("\033[0;30mO \033[0m");
			}
		}
	}
	printf("\n");
}

void remplirCombinaison(Couleur** combinaison, int taille, char couleurs[9][9]) {
	int choix;
	for (int i = 0; i < 8; i++) {
		printf("%d - %s\n", i + 1, couleurs[i]);
	}
	printf("\n");
	for (int i = 0; i < taille; i++) {
		printf("Couleur en position %d : ", i + 1);
		scanf_s("%1d", &choix);
		combinaison[i] = definirCouleur(couleurs[choix - 1]);
	}
}

int verifier(Couleur** proposition, int taille, Couleur** reponse, Couleur** correction, char couleurs[9][9]) {
	int victoire = 1;
	int vert = 0;
	int orange = 0;
	int noir = 0;
	int pionPresent = 0;
	Couleur* comparer = NULL;
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			if (strcmp(proposition[i]->couleur, reponse[j]->couleur) == 0 && i == j) {
				vert++;
				pionPresent = 1;
			}
			else if (strcmp(proposition[i]->couleur, reponse[j]->couleur) == 0 && i != j) {
				orange++;
				victoire = 0;
				pionPresent = 1;
			}
		}
		if (pionPresent == 0) {
			noir++;
			victoire = 0;
		}
		pionPresent = 0;
	}
	for (int i = 0; i < vert; i++) {
		correction[i] = definirCouleur("vert");
	}
	for (int i = 0; i < orange; i++) {
		correction[i+vert] = definirCouleur("orange");
	}
	for (int i = 0; i < noir; i++) {
		correction[i + vert + orange] = definirCouleur("noir");
	}
	return victoire;
}

void afficherTout(Couleur*** tableau_propositions, Couleur*** tableau_corrections, int tentatives, int taille, char couleurs[9][9], char ansi[9][9]) {
	for (int i = 0; i < tentatives; i++) {
		printf("Essai %d : ", i + 1);
		afficherCombinaison(tableau_propositions[i], taille, couleurs, ansi);
		printf("       -> ");
		afficherCombinaison(tableau_corrections[i], taille, couleurs, ansi);
		printf("\n");
	}
}

void libererMemoire(Couleur*** tableau_propositions, Couleur*** tableau_corrections, Couleur** reponse) {
	free(tableau_propositions);
	tableau_propositions = NULL;

	free(tableau_corrections);
	tableau_corrections = NULL;

	free(reponse);
	reponse = NULL;
}



