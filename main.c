// Je suis un commentaire (:

#include "src/jeu.h"
#include "src/color.h"
#include "src/affichage.h"
#include "src/matrix.h"

#include <stdio.h>

#define TAILLE_GRILLE 10
#define SCORE_MAX 2048

int c;
#define PAUSE() while ( (c = getchar()) != '\n' && c != EOF ) { } printf("Appuyez sur une touche pour continuer...\n"); getchar()

void testPartie1();
void testPartie2();

int main()
{
    srand(time(NULL));
    
    //testPartie2();
    
    matrix m;
    initMatrix(&m, 4*7, 4*3);
    
    pushTextMatrix(&m, 0, 10, RED, BLACK, "Kikou");
    
    int i, j;
    
    for(j = 0; j < 4*3; j++)
    {
        for(i = 0; i < 4*7; i++)
        {
            pushPixelMatrix(&m, i, j, GREEN, BLACK, (i%10)+48);
            flushMatrix(&m);
        }
    }
    
    
    freeMatrix(&m);
    
    return 0;
}

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
