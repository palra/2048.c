#include "matrix.h"
#include <string.h>

/**
 * Initialise une matrice d'affichage.
 * 
 * \param m : Pointeur vers la matrice à initialiser
 * \param w : La largeur de la matrice, en caractères
 * \param h : La hauteur de la matrice, en caractères
 */
void initMatrix(matrix *m, int w, int h)
{
    m->w = w;
    m->h = h;
    
    m->p = calloc(w*h, sizeof(pixel));
    if(m->p == NULL)
    {
        fprintf(stderr, "Impossible d'allouer la memoire\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Libère la mémoire allouée pour la matrice.
 * 
 * \param m : Pointeur vers la matrice à libérer
 */
void freeMatrix(matrix *m)
{
    free(m->p);
    m->p = NULL;
    m->w = m->h = 0;
}

/**
 * Affiche une matrice à l'écran
 * 
 * \param m : Pointeur vers la matrice à afficher
 */
void flushMatrix(matrix *m)
{
    CLEAR();
    
    int ligne, col;
    for(col = 0; col < m->h; col++)
    {
        for(ligne = 0; ligne < m->w; ligne++)
        {
            pixel *p = getPixelMatrix(m, ligne, col);
            if(p != NULL)
            {
                color_printf(p->fg, p->bg, "%c", (p->c < 32) ? ' ' : p->c);
            } else {
                exit(EXIT_FAILURE);
            }
            
        }
        printf("\n");
    }
}

/**
 * Retourne 1 si l'indice passé est dans le système de coordonées de la matrice,
 * 0 sinon.
 * 
 * \param m : Pointeur vers la matrice courante
 * \param ligne : Ligne de la case de la matrice à tester
 * \param colonne : Colonne de la case de la matrice à tester
 */
int coordInMatrix(matrix *m, int ligne, int colonne)
{
    return (ligne >= 0) && (ligne < m->w) && (colonne >= 0) && (colonne < m->h);
}

/**
 * Retourne un pointeur vers le pixel demandé.
 * 
 * \param m : Pointeur vers la matrice courante
 * \param ligne : Ligne sur la matrice du pixel demandé
 * \param colonne : Colonne sur la matrice du pixel demandé
 */
pixel* getPixelMatrix(matrix *m, int ligne, int colonne)
{
    if(coordInMatrix(m, ligne, colonne))
        return &m->p[m->w * colonne + ligne];
    else
        return NULL;
}

/**
 * Modifie la valeur d'un pixel de la matrice.
 * 
 * \param m : Pointeur vers la matrice à modifier
 * \param ligne : Ligne de la case de la matrice à modifier
 * \param colonne : Colonne de la case de la matrice à modifier
 * \param fg : Couleur du texte de la case
 * \param bg : Couleur de l'arrière plan de la case
 * \param c : Caractère affiché pour cette case
 * 
 * Retourne 1 si la modification a réussie, 0 sinon.
 */
int pushPixelMatrix(matrix *m, int ligne, int colonne, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char c)
{
    pixel *p = getPixelMatrix(m, ligne, colonne);
    if (p != NULL) 
    {
        p->fg = fg;
        p->bg = bg;
        p->c = c;
        
        return 1;
    }  
    
    return 0;
}

/**
 * Ajoute un texte dans la matrice
 * 
 * \param m : Pointeur vers la matrice à modifier
 * \param ligne : Ligne de la 1ère case de la matrice où afficher le texte
 * \param colonne : Colonne de la 1ère case de la matrice où afficher le texte
 * \param fg : Couleur du texte
 * \param bg : Couleur de l'arrière plan du texte
 * \param s : Chaîne à affichier
 * 
 * Retourne 1 si la modification a réussie, -1 si le texte a dépassé, 0 sinon.
 */
int pushTextMatrix(matrix *m, int ligne, int colonne, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char* s)
{
    if(coordInMatrix(m, ligne, colonne))
    {
        int length = strlen(s), i;
        for(i = 0; i < length; i++)
        {
            pixel *p = getPixelMatrix(m, ligne+i, colonne);
            if(p != NULL) {
                p->fg = fg;
                p->bg = bg;
                p->c = s[i];
            } else
                return -1;
        }
    
        return 1;
    }
    
    return 0;
}

/**
 * Efface le contenu de la matrice
 * 
 * \param m : Pointeur vers la matrice à modifier
 */
void clearMatrix(matrix *m)
{
    int i, j;
    for(i = 0; i < m->h; i++)
    {
        for(j = 0; j < m->w; j++)
        {
            pushPixelMatrix(m, i, j, BLACK, BLACK, '\0');
        }
    }
}


/**
 * Ajoute un texte dans la matrice
 * 
 * \param m : Pointeur vers la matrice à modifier
 * \param ligne : Ligne de la 1ère case de la matrice où afficher le rectangle
 * \param colonne : Colonne de la 1ère case de la matrice où afficher le rectangle
 * \param w : Largeur du rectangle
 * \param h : Hauteur du rectangle
 * \param fg : Couleur du rectangle
 * \param bg : Couleur de l'arrière plan du rectangle
 * \param s : Chaîne à affichier
 * 
 * Retourne 1 si la modification a réussie, -1 si le rectangle a dépassé, 0 sinon.
 */
int pushRectMatrix(matrix *m, int ligne, int colonne, int w, int h, COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, char c)
{
    if(coordInMatrix(m, ligne, colonne))
    {
        int i, j, retVal = 1;
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
            {
                if(pushPixelMatrix(m, ligne+j, colonne+i, fg, bg, c))
                {
                    retVal = -1;
                }
            }
        }

        return retVal;
    }
    
    return 0;
}
