#include "save.h"

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
		y:y:y:y:y:y:y:y:y:y:y:y:y:y:...

		Avec :
			x : largeur de la grille
			y : la valeur des cases du tableau de la grille

	*/

	fprintf(fSave, "%d\n", j->n);

	for (i = 0; i < j->n*j->n; ++i)
		fprintf(fSave, "%d:", *(j->grille + i));

	fclose(fSave);

	return 1;
}