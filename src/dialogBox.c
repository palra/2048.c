#include "dialogBox.h"

#define CAR_PER_LINE 60

int dialogBox(int mode, matrix *m, char *text)
{
	int lenght = 0;
	int run = 1;
	int i, j;
	int posX = 0, posY = 0;
	char line[CAR_PER_LINE];

	// Calcul de la longueur du texte
	while (*(text + lenght) != '\0')
		lenght++;

	int nbLines = 0;
	nbLines = lenght / CAR_PER_LINE + 1;

	int nbButtons = 0;

	switch (mode)
	{
		case 1:
			nbButtons = 1;
			break
	}

	debutTerminalSansR();
	while (run)
	{
		pushRectMatrix(m, posY, posX, CAR_PER_LINE + 2, nbLines + 5, BLACK, WHITE, ' ');

		for (i = 0; i < nbLines; ++i)
		{
			for (j = 0; j < CAR_PER_LINE; ++j)
			{
				line[j] = text[j + i * CAR_PER_LINE];
			}

			pushTextMatrix(m, 1 + i, 1, BLACK, WHITE, line);
		}

		flushMatrix(m);

		int pressedKey = lectureFleche();
        switch (pressedKey)
        {
            case NO_KEY:
            	run = 0;
                break;
            case KEY_LEFT:
                break;
            case KEY_RIGHT:
                break;
            default:
                break;
        }
	}
	finTerminalSansR();
}