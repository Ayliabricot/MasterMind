#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#include <windows.h>

int main() {
	Couleur** combinaison = creerCombinaison(9);
	char couleurs[9][9] = { "rouge","jaune","bleu","violet","rose","orange","vert","blanc" };
	char ansi[9][5] = { "0;31","0;33","0;34","0;35","1;35","0;91","0;32","0;37" };
	for (int i = 0; i < 8; i++) {
		combinaison[i] = definirCouleur(couleurs[i]);
	}
	for (int i = 0; i < 8; i++) {
		printf("%s / ", combinaison[i]->couleur);

	}

	afficherCombinaison(combinaison, 8,couleurs,ansi);
	
	printf("\n");
	return 0;
}