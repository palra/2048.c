#include "affichage.h"

#include <math.h>

/*! \fn choisirCouleur
 *    
 *  Choisit et renvoi une couleur dans un tableau de couleurs en fonction de la puissance de 2 d'un nombre
 *    
 *  \param nombre : nombre en fonction duquel on choisit la couleur
 *  \param listeCouleurs : liste des couleurs dans laquelle on va en choisir une
 *  \param nbCouleurs : nombre de couleurs dans listeCouleurs
 *    
*/
COULEUR_TERMINAL choisirCouleur(int nombre, COULEUR_TERMINAL listeCouleurs[], int nbCouleurs)
{
    // Trouver la puissance de 2 qui correspondant au nombre
    int puissance = 0;
    while (pow(2, puissance) != nombre)
    {
        puissance++;
    }

    /*
        On choisit une couleur dans listeCouleurs
        en fonction de la puissance du chiffre dans
        la case actuelle, si la puissance est plus 
        grande que le tableau on recommence au 
        début du tableau (grace au modulo).
    */
    return listeCouleurs[puissance%nbCouleurs];
}

/*! \fn dessinerLigne
 *    
 *  Dessine une ligne d'une ligne de cases
 *    
 *  \param largeur : largeur (espaces)
 *  \param p : pointeur sur la partie que l’on souhaite afficher
 *  \param numLigne : numéro de la ligne de cases (dans le tableau du jeu)
 *  \param listeCouleurs : liste des couleurs dans laquelle on va en choisir une
 *  \param nbCouleurs : nombre de couleurs dans listeCouleurs
 *    
*/
void dessinerLigne(int largeur, jeu *p, int numLigne, COULEUR_TERMINAL listeCouleurs[], int nbCouleurs)
{
    int i, j;
    COULEUR_TERMINAL couleurCase;
    int nombre;

    for (i = 0; i < p->n; ++i)
    {
        nombre = p->grille[numLigne*p->n + i];

        if (nombre != 0)
            couleurCase = choisirCouleur(nombre, listeCouleurs, nbCouleurs);
        else
            couleurCase = BLACK;

        for (j = 0; j < largeur; ++j)
        {
            color_printf(WHITE, couleurCase, " ");
        }
    }

    printf("\n");
}

/*! \fn affichageCouleur
 *  
 *  Affiche la grille à l'écran
 *  
 *  \param p : pointeur sur la partie que l’on souhaite afficher
 *  
*/
void affichageCouleur(jeu *p)
{
    int i, j, k;

    int nombre; // Nom que contient la case
    int nbChiffres; // Nombre de chiffres dans nombre

    COULEUR_TERMINAL listeCouleurs[6] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN}; // Liste des couleurs utilisées
    int nbCouleurs = 6; // Nombre de couleurs utilisées
    COULEUR_TERMINAL couleurCase; // Couleur utilisée pour la case

    int largeurCase = 7; // Doit être impaire
    int hauteurCase = 3; // Doit être impaire

    // On s'assure que la heuteur et la largeur sont impaires
    if (largeurCase%2 == 0)
        largeurCase++;
    if (hauteurCase%2 == 0)
        hauteurCase++;

    for (i = 0; i < p->n; ++i)
    {

/* ****************************** */
    // Premieres lignes de la case

        for (j = 0; j < hauteurCase / 2; ++j)
        {
            dessinerLigne(largeurCase, p, i, listeCouleurs, nbCouleurs);
        }

/* ****************************** */
        // Ligne qui contient le numero

        for (j = 0; j < p->n; ++j)
        {
            nombre = p->grille[i*p->n + j];

            if (nombre != 0)
            {
                couleurCase = choisirCouleur(nombre, listeCouleurs, nbCouleurs);

                // Trouver le nombre de chiffres dans nombre
                nbChiffres = 0;
                while (nombre > pow(10, nbChiffres))
                {
                    nbChiffres++;
                }

                /*
                    Si le nombre de chiffres est impaire, on pourra le centrer
                    il y aura donc autant d'espaces à sa droite qu'à sa gauche.
                */
                if (nbChiffres%2 == 1)
                {
                    for (k = 0; k < largeurCase / 2 - nbChiffres / 2; k++)
                        color_printf(WHITE, couleurCase, " ");

                    color_printf(WHITE, couleurCase, "%d", nombre);

                    for (k = 0; k < largeurCase / 2 - nbChiffres / 2; k++)
                        color_printf(WHITE, couleurCase, " ");
                }

                /*
                    Si le nombre de chiffres est paire, on ne pourra pas le centrer
                    il y aura donc un espace de plus à sa droite qu'à sa gauche
                */
                else
                {
                    for (k = 0; k < largeurCase / 2 - nbChiffres / 2; k++)
                        color_printf(WHITE, couleurCase, " ");

                    color_printf(WHITE, couleurCase, "%d", nombre);

                    for (k = 0; k < largeurCase / 2 - nbChiffres / 2 + 1; k++)
                        color_printf(WHITE, couleurCase, " ");
                }
            }

            else
            {
                couleurCase = BLACK;

                for (k = 0; k < largeurCase / 2; k++)
                        color_printf(WHITE, couleurCase, " ");
                color_printf(WHITE, couleurCase, ".");
                for (k = 0; k < largeurCase / 2; k++)
                        color_printf(WHITE, couleurCase, " ");
            }
        }

        printf("\n");

/* ****************************** */
        // Dernieres lignes de la case

        for (j = 0; j < hauteurCase / 2; ++j)
        {
            dessinerLigne(largeurCase, p, i, listeCouleurs, nbCouleurs);
        }
    }

    printf("\n\n");
}