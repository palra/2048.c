#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdlib.h>

#include "jeu.h"
#include "color.h"
#include "matrix.h"

COULEUR_TERMINAL choisirCouleur(int nombre);
void afficherCaseMatrice(jeu *p, matrix *m, int ligne, int colonne);
void affichageMatrice(jeu *p, matrix *m);

#endif