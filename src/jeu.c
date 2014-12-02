#include "jeu.h"
#include <stdlib.h>
#include <stdio.h>

/*! \fn initialiseJeu
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

/*! \fn libereMemoire
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

/*! \fn indiceValide
 * Fonction retournant 1 si la case (i,j) existe, 0 sinon.
 *
 */
int indiceValide (jeu *p, int i, int j)
{
    // Si i < taille max ET j < taille max ET i >= 0 ET j >= 0
    return (i < p->n) && (j < p->n) && (i >= 0) && (j >= 0);
}

/*! \fn getVal
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
        return p->grille[p->n * ligne + colonne];
    }
    else
    {
        return -1;
    }
}

/*! \fn setVal
 * Fonction modifiant la valeur de la case (ligne,colonne) de la partie p, avec la valeur val
 *
 * \param p : pointeur sur la partie en cours
 * \param ligne : entier correspondant au numéro de ligne
 * \param colonne : entier correspondant au numéro de colonne
 * \param val : entier à mettre dans la case (i,j) (si elle existe)
 */
void setVal(jeu * p, int ligne, int colonne, int val)
{
    if(indiceValide(p, ligne, colonne))
    {
        p->grille[p->n * ligne + colonne] = val;
        
        // Mise à jour du nombre de cases vides
        
        /**
         * Pourquoi ne pas simplement décrémente/incrémenter le compteur ?
         * - Si on faisait ainsi, et que l'on exécute ce code :
         *  setVal(&p, 0, 0, 0);
         *  setVal(&p, 0, 0, 0);
         *  setVal(&p, 0, 0, 0);
         *  ...
         * Le compteur serait incrémenté 3 fois de trop.
         */
         
        p->nbCasesLibres = 0;
        int i, j;
        for(i = 0; i < p->n; i++)
            for(j = 0; j < p->n; j++)  
                if(getVal(p, i, j) == 0)
                    p->nbCasesLibres++;
    }
}

/*! \fn caseVide
 * 
 * Retourne 1 si la case est vide, 0 sinon
 
 * \param p : pointeur sur la partie en cours
 * \param ligne : entier correspondant au numéro de ligne
 * \param colonne : entier correspondant au numéro de colonne
 */
int caseVide(jeu * p, int ligne, int colonne)
{
    return (indiceValide(p, ligne, colonne)) ? getVal(p, ligne, colonne) == 0 : 0;
}

/*! \fn ajouteValAlea
 *  
 *  Ajoute la valeur 2 ou 4 dans une case vide aléatoire
 *  
 *  \param p : pointeur sur la partie en cours
 *  
*/
void ajouteValAlea(jeu *p)
{
    int i = 0;
    int col, row, val;
    
    if(p->nbCasesLibres > 0)
    {
        do
        {
            col = rand() % p->n;
            row = rand() % p->n;
            val = rand() % 2;
            
            i++;
        } while (!indiceValide(p, col, row));
    
        setVal(p, col, row, val * 2 + 2);
    }
}

/*!
 * \fn gagne
 * Retourne 1 si la partie est gagnée, 0 sinon.
 *
 * \param p : pointeur sur la partie en cours
 */
int gagne(jeu * p)
{
    int i = 0;
    
    for(i = (p->n * p->n) - 1; i >= 0; i--)
        if(p->grille[i] >= p->valMax)
            return 1;
    
    return 0;
}

/*!
 * \fn perdu
 * Retourne 1 si la partie est perdue, 0 sinon.
 *
 * \param p : pointeur sur la partie en cours
 */
int perdu(jeu *p)
{
    int i, j;
    if(p->nbCasesLibres <= 0 && !gagne(p))
    {
        for(i = p->n - 1; i >= 0; i--)
        {
            for(j = p->n - 1; j >= 0; j--)
            {
                if(
                    (getVal(p, i, j) == getVal(p, i-1, j))
                 || (getVal(p, i, j) == getVal(p, i+1, j))
                 || (getVal(p, i, j) == getVal(p, i, j+1))
                 || (getVal(p, i, j) == getVal(p, i, j-1))
                )
                    return 0;
            }
        }
        
        return 1;
    } else {
        return 0;
    }
}

/**
 * \fn finParie
 * Retourne 1 si la partie est finie (gagnée ou perdue), 0 sinon.
 * 
 * \param p : pointeur sur la partie en cours
 */
int finPartie(jeu *p)
{
    return gagne(p) || perdu(p);
}