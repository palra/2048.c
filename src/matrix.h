#pragma once

#include "../lib/color.h"

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
int pushIntMatrix(matrix *m, int ligne, int colonne, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, int entier);
int pushRectMatrix(matrix *m, int ligne, int colonne, int w, int h, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char c);
void clearMatrix(matrix *m);