#include "jeu.h"

#define TAILLE_GRILLE 4
#define SCORE_MAX 2048

int main()
{
    jeu j;
    
    initialiseJeu(&j, TAILLE_GRILLE, SCORE_MAX);
    
    libereMemoire(&j);
    
    return 0;
}