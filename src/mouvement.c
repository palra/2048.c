#include "mouvement.h"

/*! mouvementLigne
 *  
 *  Effectue les mouvements (à gauche ou à droite) d'une ligne.
 *  Renvoi 1 si l'on a déplacé au moins une case, 0 si non.
 *  
 *  \param p : pointeur sur un jeu
 *  \param indice : indice de ligne
 *  \param direction : 1 pour la gauche et -1 pour la droite
 *  
*/
int mouvementLigne(jeu *j, int indice, int direction)
{
    // Si l'indice n'est pas valide
    if (indice >= j->n || indice < 0)
        return 0;

    int returnVal = 0;
    int i, pos;

    // Gauche
    if (direction == 1)
    {
        // Tout deplacer vers la gauche
        for (i = 1; i < j->n; ++i) // Pour chaque case
        {
            pos = i;
            // On deplace tout ce qu'il y à sa droite vers la gauche
            while (pos > 0 && (*(j->grille + indice * j->n + pos - 1) == 0) && *(j->grille + indice * j->n + pos) != 0)
            {
                *(j->grille + indice * j->n + pos - 1) = *(j->grille + indice * j->n + pos);
                *(j->grille + indice * j->n + pos) = 0;
                --pos;

                returnVal = 1;
            }
        }

        // Sommer les cases qui comportent la même valeur
        for (i = 0; i < j->n - 1; ++i) // Pour chaque cases sauf la derniere
        {
            pos = i;
            // Si la case à droite a la même valeur
            if (*(j->grille + indice * j->n + pos + 1) == *(j->grille + indice * j->n + pos) && *(j->grille + indice * j->n + pos) != 0)
            {
                // Multiplier la case par 2
                *(j->grille + indice * j->n + pos) *= 2;
                // Mettre à 0 la case à sa droite
                *(j->grille + indice * j->n + pos + 1) = 0;

                returnVal = 1;

                // Decaler tout de qu'il y a à sa doite d'une case vers la gauche
                while (pos < j->n - 2)
                {
                    pos++;
                    *(j->grille + indice * j->n + pos) = *(j->grille + indice * j->n + pos + 1);
                }
                *(j->grille + indice * j->n + j->n - 1) = 0; // Mettre la derniere case à 0
            }
        }
    }

    // Droite
    else if (direction == -1)
    {
        // Tout deplacer vers la droite
        for (i = j->n - 2; i >= 0; --i) // Pour chaque case
        {
            pos = i;
            // On deplace tout ce qu'il y à sa gauche vers la droite
            while (pos < j->n - 1 && (*(j->grille + indice * j->n + pos + 1) == 0) && *(j->grille + indice * j->n + pos) != 0)
            {
                *(j->grille + indice * j->n + pos + 1) = *(j->grille + indice * j->n + pos);
                *(j->grille + indice * j->n + pos) = 0;
                ++pos;

                returnVal = 1;
            }
        }

        // Sommer les cases qui comportent la même valeur
        for (i = j->n - 1; i > 0; --i) // Pour chaque cases sauf la premiere
        {
            pos = i;
            // Si la case à gauche a la même valeur
            if (*(j->grille + indice * j->n + pos - 1) == *(j->grille + indice * j->n + pos) && *(j->grille + indice * j->n + pos) != 0)
            {
                // Multiplier la case par 2
                *(j->grille + indice * j->n + pos) *= 2;
                // Mettre à 0 la case à sa gauche
                *(j->grille + indice * j->n + pos - 1) = 0;

                returnVal = 1;

                // Decaler tout de qu'il y a à sa gauche d'une case vers la droite
                while (pos > 1)
                {
                    pos--;
                    *(j->grille + indice * j->n + pos) = *(j->grille + indice * j->n + pos - 1);
                }
                *(j->grille + indice * j->n) = 0; // Mettre la premiere case à 0
            }
        }
    }

    return returnVal;
}