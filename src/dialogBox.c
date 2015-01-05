#include "dialogBox.h"

#define CAR_PER_LINE 60
#define BUTTON_WIDTH 9
#define MAX_BUTTONS 2

/* \fn dialogBox
 *	
 *	Ouvre un message, retourne :
 *	
 *	0: OK
 *	1: ANNULER
 *	2: OUI
 *	3: NON
 *	
 *	\param mode : type de dialogBox
 					0: OK
 					1: OK/ANNULER
 					2: OUI/NON
 *	\param m : matrice dans laquelle va être affiché le message
 *	\param text : texte à afficher
 *	
*/
int dialogBox(int mode, matrix *m, char *text)
{
	int lenght = 0;
	int run = 1;
	int i, j;
	int posX = 0, posY = 0;
	char line[CAR_PER_LINE];
	COULEUR_TERMINAL fg, bg;
	int buttonSelect = 0;
	char *buttonText[MAX_BUTTONS];
	int returns[MAX_BUTTONS];

	lenght = strlen(text);

	int nbLines = 0;
	nbLines = lenght / CAR_PER_LINE + 1;

	int nbButtons = 0;

	switch (mode)
	{
		case 0:
			nbButtons = 1;
			buttonText[0] = "Ok";
			returns[0] = 0;
			break;
		case 1:
			nbButtons = 2;
			buttonText[0] = "Ok";
			returns[0] = 0;
			buttonText[1] = "Annuler";
			returns[1] = 1;
			break;
		case 2:
			nbButtons = 2;
			buttonText[0] = "Oui";
			returns[0] = 2;
			buttonText[1] = "Non";
			returns[1] = 3;
			break;
	}

	posX = m->w / 2 - CAR_PER_LINE / 2 - 1;
	posY = m->h / 2 - (nbLines + 6) / 2;

	debutTerminalSansR();
	while (run)
	{
		pushRectMatrix(m, posY - 1, posX - 1, CAR_PER_LINE + 4, nbLines + 7, BLACK, WHITE, ' ');
		pushRectMatrix(m, posY, posX, CAR_PER_LINE + 2, nbLines + 5, WHITE, BLACK, ' ');

		for (i = 0; i < nbLines; ++i)
		{
			for (j = 0; j < CAR_PER_LINE; ++j)
			{
				line[j] = text[j + i * CAR_PER_LINE];
			}

			pushTextMatrix(m, posY + i + 1, posX + 1, WHITE, BLACK, line);
		}

		for (i = 0; i < nbButtons; ++i)
		{
			if (buttonSelect == i)
			{
				fg = BLACK;
				bg = WHITE;
			}
			else
			{
				fg = WHITE;
				bg = RED;
			}

			pushRectMatrix(m, posY + nbLines + 1, posX + (CAR_PER_LINE + 2) - (BUTTON_WIDTH + 1) * i - BUTTON_WIDTH - 1, BUTTON_WIDTH, 3, fg, bg, ' ');
			pushTextMatrix(m, posY + nbLines + 2, posX + (CAR_PER_LINE + 2) - (BUTTON_WIDTH + 1) * i - BUTTON_WIDTH - 1 + BUTTON_WIDTH / 2 - strlen(buttonText[nbButtons - i - 1]) / 2, fg, bg, buttonText[nbButtons - i - 1]);
		}

		flushMatrix(m);

		int pressedKey = lectureFleche();
        switch (pressedKey)
        {
            case NO_KEY:
            	run = 0;
                break;
            case KEY_LEFT:
            	buttonSelect--;
            	if (buttonSelect < 0)
            		buttonSelect = nbButtons - 1;
                break;
            case KEY_RIGHT:
        		buttonSelect++;
        		if (buttonSelect >= nbButtons)
        			buttonSelect = 0;
                break;
            default:
                break;
        }
	}
	finTerminalSansR();

	return returns[buttonSelect];
}