#include "affichage.h"
#include "matrix.h"
#include "jeu.h"
#include "mouvement.h"
#include "menu.h"

#include "../lib/saisieM.h"
#include "../lib/color.h"

#include <stdio.h>

#define DIM_JEU 4
#define FIN_JEU 2048

int main()
{
    srand(time(NULL));

    jeu j;
    matrix m;

    int winW, winH;
    getWinSize(&winW, &winH);

    initialiseJeu(&j, DIM_JEU, FIN_JEU);
    initMatrix(&m, winW, winH - 1);

    menuChoice choice = menu(&m);

    if (choice == PLAY)
        jouer(&j, &m);

    freeMatrix(&m);
    libereMemoire(&j);

    return 0;
}