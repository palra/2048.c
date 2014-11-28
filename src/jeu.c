#include "jeu.h"
#include <stdlib.h>

/*!
 * Alloue la grille de la variable jeu passée par adresse.
 * Initialise les cases de la grille avec des cases vides (valeurs nulles)
 * Initialise les champs n et valMax avec les valeurs passées en paramètre
 *
 * \param p : pointeur sur une partie de 2048
 * \param n : taille de la grille
 * \param valMax : valeur à atteindre pour gagner
 */
void initialiseJeu (jeu *p, int n, int valMax)
{
    jeu->n = n;
    jeu->valMax = valMax;
    jeu->nbCasesLibres = n*n;
    jeu->
}
