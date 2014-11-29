#include "src/jeu.h"
#include "src/color.h"
#include <stdio.h>

#define TAILLE_GRILLE 4
#define SCORE_MAX 2048

int main()
{
    jeu j;
    
    initialiseJeu(&j, TAILLE_GRILLE, SCORE_MAX);
    
    setVal(&j, 0, 2, 2);
    setVal(&j, 0, 3, 4);
    setVal(&j, 1, 2, 4);
    setVal(&j, 1, 3, 8);
    setVal(&j, 2, 1, 2);
    setVal(&j, 2, 2, 16);
    setVal(&j, 2, 3, 32);
    setVal(&j, 3, 1, 2);
    setVal(&j, 3, 2, 2);
    setVal(&j, 3, 3, 16);
    
    affichage(&j);
    
    libereMemoire(&j);
    
    return 0;
}