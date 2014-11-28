#include "jeu.h"
#include <stdio.h>

#define TAILLE_GRILLE 4
#define SCORE_MAX 2048

int main()
{
    jeu j;
    
    initialiseJeu(&j, TAILLE_GRILLE, SCORE_MAX);
    
    printf("%d\n", indiceValide(&j, 5, 2));
    printf("%d\n", indiceValide(&j, 0, 4));
    printf("%d\n", indiceValide(&j, 1, 2));
    printf("%d\n", indiceValide(&j, -1, 3));
    printf("%d\n", indiceValide(&j, 3, -2));
    
    libereMemoire(&j);
    
    return 0;
}