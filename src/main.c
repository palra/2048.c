#include "jeu.h"
#include <stdio.h>

#define TAILLE_GRILLE 4
#define SCORE_MAX 2048

int main()
{
    jeu j;
    
    initialiseJeu(&j, TAILLE_GRILLE, SCORE_MAX);
    
    j.grille[0*TAILLE_GRILLE+3] = 2;
    j.grille[1*TAILLE_GRILLE+1] = 4;
    
    printf("%d\n", getVal(&j, 0, 3));
    
    setVal(&j, 0, 3, 8);
    
    printf("%d\n", getVal(&j, 0, 3));
    printf("%d\n", getVal(&j, 1, 1));
    
    
    libereMemoire(&j);
    
    return 0;
}