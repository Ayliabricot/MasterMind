#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <windows.h>

int main() {
	Couleur** combinaison = creerCombinaison(9);
	char couleurs[9][9] = { "rouge","jaune","bleu","violet","rose","orange","vert","blanc" };

	for (int i = 0; i < 8; i++) {
		combinaison[i] = definirCouleur(couleurs[i]);
	}
	for (int i = 0; i < 8; i++) {
		printf("%s / ", combinaison[i]->couleur);

	}

	afficherCombinaison(combinaison);
	for (int i = 0; i < 8; i++) {
		switch (i) {
		case 0: printf("\033[0;31mOOOO \033[0m"); break; // Rouge
		case 1: printf("\033[0;33mOOOO \033[0m"); break; // Jaune
		case 2: printf("\033[0;34mOOOO \033[0m"); break; // Bleu
		case 3: printf("\033[0;35mOOOO \033[0m"); break; // Violet
		case 4: printf("\033[1;35mOOOO \033[0m"); break; // Rose
		case 5: printf("\033[0;91mOOOO \033[0m"); break; // Orange
		case 6: printf("\033[0;32mOOOO \033[0m"); break; // Vert
		case 7: printf("\033[0;37mOOOO \033[0m"); break; // Blanc
		}
		printf(" "); // Ajoute un espace entre chaque couleur
	}
	printf("\n");
	return 0;
}