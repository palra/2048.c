#pragma once

#include "jeu.h"

int mouvementLigne(jeu *j, int indice, int direction);
int mouvementColonne(jeu *j, int indice, int direction);
int mouvementLignes(jeu *j, int direction);
int mouvementColonnes(jeu *j, int direction);
int mouvement(jeu *j, int direction);

#define MVT_STOP -1
#define MVT_BAS 0
#define MVT_DROITE 1
#define MVT_HAUT 2
#define MVT_GAUCHE 3

int saisieD();