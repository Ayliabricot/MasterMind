#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <windows.h>

int main() {
	srand(time(NULL));

	int jouer=1;
	Couleur** combinaison = creerCombinaison(9);
	int taille;

	int tentatives = 0;
	int maxTentatives;
	int victoire = 0;

	int index = 0;
	int eviterDoublon[10] = { 0 };
	int doublon = 1;

	char couleurs[9][9] = { "rouge","jaune","bleu","violet","rose","orange","vert","blanc" };
	char ansi[9][9] = { "0;31","0;33","0;34","0;35","38;5;198","38;5;166","0;32","0;37" };
	
	for (int i = 0; i < 8; i++) {
		combinaison[i] = definirCouleur(couleurs[i]);
	}

	while (1) {
		system("cls");
		printf("---MasterMind---\n\n1 - Mode Normal\n2 - Super MasterMind\n0 - Quitter\n\nVotre choix : ");
		scanf_s("%d", &jouer);
		if (jouer == 1) {
			taille = 4;
			maxTentatives = 10;
		}
		else if (jouer == 2) {
			taille = 5;
			maxTentatives = 12;
		}
		system("cls");
		if (jouer == 1 || jouer == 2) {

			Couleur** reponse = creerCombinaison(taille + 1);

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

			tentatives = 0;
			victoire = 0;

			Couleur*** tableau_combinaisons = creerTableauCombinaisons();
			Couleur*** tableau_corrections = creerTableauCombinaisons();

			while (tentatives < maxTentatives && victoire == 0) {
				if (tentatives > 0) {
					system("cls");
					afficherTout(tableau_combinaisons, tableau_corrections, tentatives, taille, couleurs, ansi);
				}

				Couleur** proposition = creerCombinaison(taille + 1);
				Couleur** correction = creerCombinaison(taille + 1);

				remplirCombinaison(proposition, taille, couleurs);
				tableau_combinaisons[tentatives] = proposition;

				victoire = verifier(proposition, taille, reponse, correction, couleurs);
				if (victoire == 1) {
					tentatives++;
					break;
				}

				tableau_corrections[tentatives] = correction;

				tentatives = tentatives + 1;
			}
			system("cls");
			if (victoire == 1) {
				printf("Bravo vous avez gagne en %d coups!\nLa combinaison etait : ", tentatives);
				afficherCombinaison(reponse, taille, couleurs, ansi);
			}
			else {
				printf("Vous avez perdu...\nLa combinaison etait : ");
				afficherCombinaison(reponse, taille, couleurs, ansi);
			}

			printf("\n1 - Retourner au menu\n2 - Quitter\n\nVotre choix : ");
			scanf_s("%d", &jouer);
			if (jouer == 1) {
				system("cls");
			}
			else if (jouer == 2) {
				jouer = 0;
				libererMemoire(tableau_combinaisons, tableau_corrections, reponse);
				break;
			}
		}
		if (jouer == 0) {
			break;
		}
	}

	system("cls");
	printf("Vous avez quitte.\n");
	return 0;
}