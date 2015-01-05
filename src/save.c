#include "save.h"
#include "jeu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* \fn sauvegarde
 *	
 *	Sauvegarde la partie en cours dans un fichier
 *	Retourne 0 en cas d'erreur, 1 si non
 *	
 *	\param j : Jeu à sauvegarder 
 *	
*/
int sauvegarde(jeu *j)
{
	FILE *fSave = NULL;
	fSave = fopen("save.txt", "w+");
	int i;

	if (fSave == NULL)
		return 0;

	/*

		Le fichier est de la forme :

		x
		m
		s
		y:y:y:y:y:y:y:y:y:y:y:y:y:y:...

		Avec :
			x : largeur de la grille
			m : la valeur maximale du jeu
			y : la valeur des cases du tableau de la grille

	*/

	fprintf(fSave, "%d\n", j->n);
	fprintf(fSave, "%d\n", j->valMax);
	fprintf(fSave, "%d\n", j->score);

	for (i = 0; i < j->n*j->n; ++i)
		fprintf(fSave, "%d:", *(j->grille + i));

	fclose(fSave);

	return 1;
}

/**
 * Charge une partie depuis le fichier de sauvegarde
 * Retourne -1 en cas d'erreur, 0 si aucune partie n'a été chargée,
 * 1 si elle a été chargée
 * 
 *	\param j : Jeu à sauvegarder 
 */
int charger(jeu *j)
{

	FILE *fSave = NULL;
	fSave = fopen("save.txt", "r");
	int i, val;

	if (fSave == NULL)
		return -1;

	int dimension, valMax, score;
	
	/* char buffer[20];						|| 			*/
	/* *buffer = fgets(buffer, 20, fSave);	||=======> 	*/	fscanf(fSave, "%d\n", &dimension);
	/* dimension = atoi(buffer);			|| 			*/

	fscanf(fSave, "%d\n", &valMax);
	fscanf(fSave, "%d\n", &score);

  initialiseJeu(&j, dimension, 2048); // TODO : mettre la valeur de fin de jeu dans la sauvegarde
  j->score = score;

  char buf = 1;
	for (i = 0; i < dimension * dimension; ++i)
	{
		fscanf("%d:", &(j->grille[i]));
	}
}