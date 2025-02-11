#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>

Combinaison* creerCombinaison(int taille) {
	Combinaison* nouvelle_combinaison = malloc(taille * sizeof(Combinaison));
	nouvelle_combinaison = NULL;

	return nouvelle_combinaison;
}

void definirCouleurs(Combinaison* combinaison) {
	combinaison->couleur[0] = "rouge";
	combinaison->couleur[1] = "vert";
	combinaison->couleur[2] = "bleu";
	combinaison->couleur[3] = "jaune";
	combinaison->couleur[4] = "orange";
	combinaison->couleur[5] = "violet";
	combinaison->couleur[6] = "rose";
	combinaison->couleur[7] = "blanc";
}

void assignerCouleur(Combinaison* combinaison, int index, char couleur[50]) {
	combinaison->couleur[index] = couleur;
}

