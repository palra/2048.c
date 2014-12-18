#include "jeu.h"
#include "affichage.h"
#include "matrix.h"

#include "../lib/saisieM.h"
#include "../lib/color.h"

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

    int winW, winH;

    getWinSize(&winW, &winH);

    initialiseJeu(&j, DIM_JEU, FIN_JEU);
    initMatrix(&m, winW, winH - 1);

    int run = 1;

    ajouteValAlea(&j);
    ajouteValAlea(&j);

    affichageMatrice(&j, &m);
    debutTerminalSansR();
    while (run)
    {
        switch (lectureFleche())
        {
            case KEY_UP:
                mouvementColonne(&j, 0, 1);
                mouvementColonne(&j, 1, 1);
                mouvementColonne(&j, 2, 1);
                mouvementColonne(&j, 3, 1);
                ajouteValAlea(&j);
                affichageMatrice(&j, &m);
                break;
            case KEY_DOWN:
                mouvementColonne(&j, 0, -1);
                mouvementColonne(&j, 1, -1);
                mouvementColonne(&j, 2, -1);
                mouvementColonne(&j, 3, -1);
                ajouteValAlea(&j);
                affichageMatrice(&j, &m);
                break;
            case KEY_RIGHT:
                mouvementLigne(&j, 0, -1);
                mouvementLigne(&j, 1, -1);
                mouvementLigne(&j, 2, -1);
                mouvementLigne(&j, 3, -1);
                ajouteValAlea(&j);
                affichageMatrice(&j, &m);
                break;
            case KEY_LEFT:
                mouvementLigne(&j, 0, 1);
                mouvementLigne(&j, 1, 1);
                mouvementLigne(&j, 2, 1);
                mouvementLigne(&j, 3, 1);
                ajouteValAlea(&j);
                affichageMatrice(&j, &m);
                break;
            case KEY_ESCAPE:
                run = 0;
                break;
            default:
                break;
        }
    }
    finTerminalSansR();

    freeMatrix(&m);
    libereMemoire(&j);

    return 0;
}

#ifdef OLD_VERSION

/*! testPartie1
 *  
 *  Petit programme de test pour montrer au prof que la partie 1 marche comme il faut.
 *  
*/
void testPartie1()
{
    jeu j;
    int nbLigne;
    int nbColonne;
    int val;
    char repQuit;

    printf("Créer un plateau de taille 4x4 vide et l'afficher : \n\n");
    initialiseJeu(&j, 4, 2048);
    affichageCouleur(&j);

    PAUSE();

    printf("\n\nTest de la fonction indiceValide() : \n");
    do
    {
        repQuit = 'o';
    
        printf("Entrez les coordonnées à tester.\n");
        printf("Ligne = ");
        scanf("%d", &nbLigne);
        printf("Colonne = ");
        scanf("%d", &nbColonne);
    
        if (indiceValide(&j, nbLigne, nbColonne))
            printf("L'indice (%d;%d) est valide.\n\n", nbLigne, nbColonne);
        else
            printf("L'indice (%d;%d) n'est pas valide.\n\n", nbLigne, nbColonne);
        
        printf("Voulez vous refaire un test ? (o/n) ");
        scanf(" %c", &repQuit);
    } while (repQuit != 'n');

    PAUSE();

    printf("\n\nTest de la fonction setVal() : \n");
    do
    {
        repQuit = 'o';
    
        printf("Entrez les coordonnées de la case à modifier.\n");
        printf("Ligne = ");
        scanf("%d", &nbLigne);
        printf("Colonne = ");
        scanf("%d", &nbColonne);
        printf("Entrez la nouvelle valeur de la case (%d;%d) : ", nbLigne, nbColonne);
        scanf("%d", &val);
    
        setVal(&j, nbLigne, nbColonne, val);

    
        printf("Etat actuel de la grille :\n");
        affichageCouleur(&j);

        printf("Voulez vous refaire un test ? (o/n) ");
        scanf(" %c", &repQuit);
    } while (repQuit != 'n');

    PAUSE();

    printf("\n\nTest de la fonction getVal() : \n");
    do
    {
        repQuit = 'o';
    
        printf("Entrez les coordonnées de la case à lire.\n");
        printf("Ligne = ");
        scanf("%d", &nbLigne);
        printf("Colonne = ");
        scanf("%d", &nbColonne);
    
        if (getVal(&j, nbLigne, nbColonne) != -1)
            printf("La case (%d; %d) contient %d.\n\n", nbLigne, nbColonne, getVal(&j, nbLigne, nbColonne));
        else
            printf("L'indice (%d; %d) n'est pas valide.\n\n", nbLigne, nbColonne);
        
        printf("Voulez vous refaire un test ? (o/n) ");
        scanf(" %c", &repQuit);
    } while (repQuit != 'n');

    libereMemoire(&j);
}

void testPartie2()
{
    jeu j;
    int nbLigne;
    int nbColonne;
    int val;
    char repQuit;
    int i;

    clearScreen();

    printf("Créer un plateau de taille 4x4 vide et l'afficher : \n\n");
    initialiseJeu(&j, 4, 2048);
    affichageCouleur(&j);

    PAUSE();

    clearScreen();

    printf("Test de la fonction ajouteValAlea() : \n\n");

    printf("Combien de cases aléatoires voulez-vous ajouter ? \n");
    int nbCases = 0;
    scanf("%d",&nbCases);

    for (i = 0; i < nbCases; i++)
        ajouteValAlea(&j);
    affichageCouleur(&j);

    PAUSE();

    clearScreen();

    printf("Test de la fonction caseVide() : \n\n");
    affichageCouleur(&j);

    do
    {
        repQuit = 'o';
    
        printf("Entrez les coordonnées à tester.\n");
        printf("Ligne = ");
        scanf("%d", &nbLigne);
        printf("Colonne = ");
        scanf("%d", &nbColonne);
    
        if (caseVide(&j, nbLigne, nbColonne))
            printf("La case (%d;%d) est vide.\n\n", nbLigne, nbColonne);
        else
            printf("La case (%d;%d) n'est pas vide.\n\n", nbLigne, nbColonne);
        
        printf("Voulez vous refaire un test ? (o/n) ");
        scanf(" %c", &repQuit);
    } while (repQuit != 'n');

    clearScreen();

    printf("\n\nTest de la fonction gagne()\n\n");

    affichageCouleur(&j);
    PAUSE();

    printf("La fonction gagne() renvoie %d\n\n", gagne(&j));

    PAUSE();

    printf("Maintenant on met une case à la valeur 2048 : \n\n");
    PAUSE();
    setVal(&j, rand() % j.n, rand() % j.n, 2048);
    affichageCouleur(&j);
    PAUSE();

    printf("La fonction gagne() renvoie %d\n\n", gagne(&j));

    PAUSE();

    libereMemoire(&j);
}

#endif
