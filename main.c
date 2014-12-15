#include "src/jeu.h"
#include "src/color.h"
#include "src/affichage.h"
#include "src/matrix.h"

#include <stdio.h>

#define TAILLE_GRILLE 10
#define SCORE_MAX 2048

int c;
#define PAUSE() while ( (c = getchar()) != '\n' && c != EOF ) { } printf("Appuyez sur une touche pour continuer...\n"); getchar()

void testPartie1();
void testPartie2();

#define DIM_JEU 4
#define FIN_JEU 2048

int main()
{
    srand(time(NULL));
    
    jeu j;
    matrix m;

    initialiseJeu(&j, DIM_JEU, FIN_JEU);
    initMatrix(&m, DIM_JEU*7, DIM_JEU*3);
    
    setVal(&j, 0, 0, 4);
    setVal(&j, 0, 1, 2);
    setVal(&j, 2, 1, 512);
    affichageMatrice(&j, &m);
    
    freeMatrix(&m);
    libereMemoire(&j);
    
    return 0;
}