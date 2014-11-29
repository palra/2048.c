#ifndef JEU_H
#define JEU_H

#include <stdlib.h>

typedef struct {
    int n;
    int valMax;
    int nbCasesLibres;
    int *grille;
} jeu;

void initialiseJeu (jeu *p, int n, int valMax);
int indiceValide (jeu *p, int i, int j);
int getVal(jeu *p, int ligne, int colonne);
void setVal(jeu * p, int ligne, int colonne, int val);
void affichage(jeu *p);

#endif