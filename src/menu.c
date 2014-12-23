#include "menu.h"

#define NB_BUTTON 3

int menu(matrix *m)
{
	int run = 1, 
		mouvementChoisi = 0,
		bouttonSelect = 0,
		i = 0;

	menuButton button[NB_BUTTON];

	button[0].choice = PLAY;
	button[0].text = "Jouer";

	button[1].choice = LOAD;
	button[1].text = "Charger une partie";

	button[2].choice = EXIT;
	button[2].text = "Quitter";

	int buttonHeight = 3;
	int buttonWidth = 25;

    debutTerminalSansR();

    while (run)
    {
        clearMatrix(m);

        for (i = 0; i < NB_BUTTON; i ++)
        {
            pushRectMatrix(m, i * (buttonHeight + 1), 0, buttonWidth, buttonHeight, BLACK, WHITE, ' ');
        }

        flushMatrix(m);

        int mouvementChoisi = lectureFleche();
        if (mouvementChoisi == NO_KEY)
            run = 0;
    }

    finTerminalSansR();
}