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
int coordInMatrix(matrix *m, int x, int y);
pixel* getPixelMatrix(matrix *m, int x, int y);
int pushPixelMatrix(matrix *m, int x, int y, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char c);
int pushTextMatrix(matrix *m, int x, int y, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char* s);
void clearMatrix(matrix *m);