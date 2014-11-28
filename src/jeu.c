#include "jeu.h"
#include <stdlib.h>
#include <stdio.h>

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
    p->n = n;
    p->valMax = valMax;
    p->nbCasesLibres = n * n;
    p->grille = malloc(sizeof(int)*n*n);
    
    if(p->grille == NULL)
    {
        fprintf(stderr, "Impossible d'allouer la memoire\n");
        exit(EXIT_FAILURE);
    }
}

/*!
 * Libère la mémoire allouée pour la grille du jeu passé par adresse.
 *
 * \param p : pointeur sur une partie de 2048
 */
void libereMemoire(jeu *p)
{
    free(p->grille);
    p->grille = NULL;
}

/*!
 * Fonction retournant 1 si la case (i,j) existe, 0 sinon.
 *
 */
int indiceValide (jeu *p, int i, int j)
{
    return (i < p->n) && (j < p->n) && (i >= 0) && (j >= 0);
}