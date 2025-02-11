#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>

int main() {
	Combinaison* couleurs = creerCombinaison(10);
	definirCouleurs(couleurs);
	for (int i = 0; i < 10; i++) {
		printf("%s / ", couleurs->couleur[i]);
	}

	return 0;
}