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
    p->grille = calloc(n*n, sizeof(int));
    
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
    p->n = p->nbCasesLibres = p->valMax = -1;
}

/*!
 * Fonction retournant 1 si la case (i,j) existe, 0 sinon.
 *
 */
int indiceValide (jeu *p, int i, int j)
{
    // Si i < taille max ET j < taille max ET i >= 0 ET j >= 0
    return (i < p->n) && (j < p->n) && (i >= 0) && (j >= 0);
}

/*!
 * Fonction retournant la valeur de la case (ligne,colonne) de la partie p,
 * ou -1 si la case n’existe pas.
 *
 * \param p : pointeur sur la partie en cours
 * \param ligne : entier correspondant au numéro de ligne
 * \param colonne : entier correspondant au numéro de colonne
 */
int getVal(jeu *p, int ligne, int colonne)
{
    if(indiceValide(p, ligne, colonne))
    {
        // Retourne la valeur de la case (ligne, colonne)
        
        /**
         * Explications :
         * Une ligne a une longueur `p->n`, donc accéder à la ligne i c'est
         * accéder aux cases mémoires de décalage i*p->n par rapport au 
         * début du tableau.
         */
        return *(p->grille + (p->n * ligne + colonne));
    }
    else
    {
        return -1;
    }
}

/*!
 * Fonction modifiant la valeur de la case (ligne,colonne) de la partie p, avec la valeur val
 *
 * \param p : pointeur sur la partie en cours
 * \param ligne : entier orrespondant au numéro de ligne
 * \param colonne : entier orrespondant au numéro de colonne
 * \param val : entier à mettre dans la case (i,j) (si elle existe)
 */
void setVal(jeu * p, int ligne, int colonne, int val)
{
    if(indiceValide(p, ligne, colonne))
    {
        *(p->grille + (p->n * ligne + colonne)) = val;
    }
}
/*!
 * Fonction affichant la grille à l’écran.
 *
 * \param p : pointeur sur la partie que l’on souhaite afficher
 */
void affichage(jeu *p)
{
    int i = 0;
    
    printf("*****************************\n");
    for(i = 0; i < p->n * p->n; i++)
    {
        printf("%s* %4d %s", (i % p->n == 0 && i != 0) ? "\n" : "", p->grille[i], ((i+1) % p->n == 0) ? "*" : "");
    }
    printf("\n*****************************\n");
}