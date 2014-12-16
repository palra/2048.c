#pragma once

#include "color.h"

#define CLEAR() printf("\e[1;1H\e[2J")

typedef struct
{
    COULEUR_TERMINAL fg, bg;
    char c;
} pixel;

typedef struct
{
    int w;
    int h;
    pixel *p;
} matrix;

void initMatrix(matrix *m, int w, int h);
void flushMatrix(matrix *m);
int coordInMatrix(matrix *m, int ligne, int colonne);
pixel* getPixelMatrix(matrix *m, int ligne, int colonne);
int pushPixelMatrix(matrix *m, int ligne, int colonne, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char c);
int pushTextMatrix(matrix *m, int ligne, int colonne, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char* s);
int pushRectMatrix(matrix *m, int ligne, int colonne, int w, int h, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char c);
void clearMatrix(matrix *m);