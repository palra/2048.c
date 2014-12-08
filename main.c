#include "src/jeu.h"
#include "src/color.h"
#include "src/affichage.h"

#include <stdio.h>

#define TAILLE_GRILLE 10
#define SCORE_MAX 2048

#define PAUSE() printf("Appuyez sur une touche pour continuer...\n");getchar()

int main()
{
    srand(time(NULL));
    
    jeu j;
    int nbLigne;
    int nbColonne;
    int val;
    char repQuit;
    
    
    /*
        Petit programme de test pour montrer au prof 
        que la premiere partie marche comme il faut.
    */
    
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
    
    return 0;
}