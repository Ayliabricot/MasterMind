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

	return 0;
}