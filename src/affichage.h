#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdlib.h>

#include "jeu.h"
#include "color.h"

int nbDigits(int x);
COULEUR_TERMINAL choisirCouleur(int nombre, COULEUR_TERMINAL liste_couleurs[], int nb_couleurs);
void dessinerLigne(int largeur, jeu *p, int numLigne, COULEUR_TERMINAL listeCouleurs[], int nbCouleurs);
void affichageCouleur(jeu *p);

#endif