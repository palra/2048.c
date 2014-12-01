#include "src/jeu.h"
#include "src/color.h"
#include "src/affichage.h"

#include <stdio.h>

#define TAILLE_GRILLE 10
#define SCORE_MAX 2048

int main()
{
    srand(time(NULL));
    
    jeu j;
    
    initialiseJeu(&j, TAILLE_GRILLE, SCORE_MAX);
    
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    ajouteValAlea(&j);
    
    affichageCouleur(&j);
    
    libereMemoire(&j);
    
    return 0;
}