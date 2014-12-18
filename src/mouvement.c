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
            while (pos > 0 && getVal(j, indice, pos - 1) == 0 && getVal(j, indice, pos) != 0)
            {
                setVal(j, indice, pos - 1, getVal(j, indice, pos));
                setVal(j, indice, pos, 0);
                --pos;

                returnVal = 1;
            }
        }

        // Sommer les cases qui comportent la même valeur
        for (i = 0; i < j->n - 1; ++i) // Pour chaque cases sauf la derniere
        {
            pos = i;
            // Si la case à droite a la même valeur
            if (getVal(j, indice, pos + 1) == getVal(j, indice, pos) && getVal(j, indice, pos) != 0)
            {
                // Multiplier la case par 2
                setVal(j, indice, pos, getVal(j, indice, pos) * 2);
                // Mettre à 0 la case à sa droite
                setVal(j, indice, pos + 1, 0);

                returnVal = 1;
            }
        }

        // Tout deplacer vers la gauche
        for (i = 1; i < j->n; ++i) // Pour chaque case
        {
            pos = i;
            // On deplace tout ce qu'il y à sa droite vers la gauche
            while (pos > 0 && getVal(j, indice, pos - 1) == 0 && getVal(j, indice, pos) != 0)
            {
                setVal(j, indice, pos - 1, getVal(j, indice, pos));
                setVal(j, indice, pos, 0);
                --pos;

                returnVal = 1;
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
            while (pos < j->n - 1 && getVal(j, indice, pos + 1) == 0 && getVal(j, indice, pos) != 0)
            {
                setVal(j, indice, pos + 1, getVal(j, indice, pos));
                setVal(j, indice, pos, 0);
                ++pos;

                returnVal = 1;
            }
        }

        // Sommer les cases qui comportent la même valeur
        for (i = j->n - 1; i > 0; --i) // Pour chaque cases sauf la premiere
        {
            pos = i;
            // Si la case à gauche a la même valeur
            if (getVal(j, indice, pos - 1) == getVal(j, indice, pos) && getVal(j, indice, pos) != 0)
            {
                // Multiplier la case par 2
                setVal(j, indice, pos, getVal(j, indice, pos) * 2);
                // Mettre à 0 la case à sa gauche
                setVal(j, indice, pos - 1, 0);

                returnVal = 1;
            }
        }

        // Tout deplacer vers la droite
        for (i = j->n - 2; i >= 0; --i) // Pour chaque case
        {
            pos = i;
            // On deplace tout ce qu'il y à sa gauche vers la droite
            while (pos < j->n - 1 && getVal(j, indice, pos + 1) == 0 && getVal(j, indice, pos) != 0)
            {
                setVal(j, indice, pos + 1, getVal(j, indice, pos));
                setVal(j, indice, pos, 0);
                ++pos;

                returnVal = 1;
            }
        }
    }

    return returnVal;
}

/*! mouvementColonne
 *  
 *  Effectue les mouvements (en haut ou en bas) d'une colonne.
 *  Renvoi 1 si l'on a déplacé au moins une case, 0 si non.
 *  
 *  \param p : pointeur sur un jeu
 *  \param indice : indice de colonne
 *  \param direction : 1 pour le haut et -1 pour le bas
 *  
*/
int mouvementColonne(jeu *j, int indice, int direction)
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
            while (pos > 0 && getVal(j, pos - 1, indice) == 0 && getVal(j, pos, indice) != 0)
            {
                setVal(j, pos - 1, indice, getVal(j, pos, indice));
                setVal(j, pos, indice, 0);
                --pos;

                returnVal = 1;
            }
        }

        // Sommer les cases qui comportent la même valeur
        for (i = 0; i < j->n - 1; ++i) // Pour chaque cases sauf la derniere
        {
            pos = i;
            // Si la case à droite a la même valeur
            if (getVal(j, pos + 1, indice) == getVal(j, pos, indice) && getVal(j, pos, indice) != 0)
            {
                // Multiplier la case par 2
                setVal(j, pos, indice, getVal(j, pos, indice) * 2);
                // Mettre à 0 la case à sa droite
                setVal(j, pos + 1, indice, 0);

                returnVal = 1;
            }
        }

        // Tout deplacer vers la gauche
        for (i = 1; i < j->n; ++i) // Pour chaque case
        {
            pos = i;
            // On deplace tout ce qu'il y à sa droite vers la gauche
            while (pos > 0 && getVal(j, pos - 1, indice) == 0 && getVal(j, pos, indice) != 0)
            {
                setVal(j, pos - 1, indice, getVal(j, pos, indice));
                setVal(j, pos, indice, 0);
                --pos;

                returnVal = 1;
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
            while (pos < j->n - 1 && getVal(j, pos + 1, indice) == 0 && getVal(j, pos, indice) != 0)
            {
                setVal(j, pos + 1, indice, getVal(j, pos, indice));
                setVal(j, pos, indice, 0);
                ++pos;

                returnVal = 1;
            }
        }

        // Sommer les cases qui comportent la même valeur
        for (i = j->n - 1; i > 0; --i) // Pour chaque cases sauf la premiere
        {
            pos = i;
            // Si la case à gauche a la même valeur
            if (getVal(j, pos - 1, indice) == getVal(j, pos, indice) && getVal(j, pos, indice) != 0)
            {
                // Multiplier la case par 2
                setVal(j, pos, indice, getVal(j, pos, indice) * 2);
                // Mettre à 0 la case à sa gauche
                setVal(j, pos - 1, indice, 0);

                returnVal = 1;
            }
        }

        // Tout deplacer vers la droite
        for (i = j->n - 2; i >= 0; --i) // Pour chaque case
        {
            pos = i;
            // On deplace tout ce qu'il y à sa gauche vers la droite
            while (pos < j->n - 1 && getVal(j, pos + 1, indice) == 0 && getVal(j, pos, indice) != 0)
            {
                setVal(j, pos + 1, indice, getVal(j, pos, indice));
                setVal(j, pos, indice, 0);
                ++pos;

                returnVal = 1;
            }
        }
    }

    return returnVal;
}