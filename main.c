#include "src/jeu.h"
#include "src/color.h"
#include "src/affichage.h"

#include <stdio.h>

#define TAILLE_GRILLE 5
#define SCORE_MAX 2048

int main()
{
    jeu j;
    
    initialiseJeu(&j, TAILLE_GRILLE, SCORE_MAX);
    
    setVal(&j, 0, 2, 2);
    setVal(&j, 0, 3, 4);
    setVal(&j, 1, 2, 8);
    setVal(&j, 1, 3, 16);
    setVal(&j, 2, 1, 32);
    setVal(&j, 2, 2, 64);
    setVal(&j, 2, 4, 128);
    setVal(&j, 3, 1, 256);
    setVal(&j, 3, 2, 512);
    setVal(&j, 4, 3, 1024);
    setVal(&j, 4, 4, 2048);
    
    affichageCouleur(&j);
    
    libereMemoire(&j);
    
    return 0;
}