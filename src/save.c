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

	if (fSave == NULL)
		return 0;

	fprintf(fSave, "Hey !\n");

	return 1;
}