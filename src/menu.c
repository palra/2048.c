#include "menu.h"

#define NB_BUTTON 3

int menu(matrix *m)
{
	int run = 1, 
		pressedKey = 0,
		buttonSelect = 0,
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

    COULEUR_TERMINAL fg;
    COULEUR_TERMINAL bg;

    debutTerminalSansR();

    while (run)
    {
        clearMatrix(m);

        for (i = 0; i < NB_BUTTON; i ++)
        {
            if (i == buttonSelect)
            {
                fg = WHITE;
                bg = RED;
            }

            else
            {
                fg = BLACK;
                bg = WHITE;
            }

            pushRectMatrix(m, i * (buttonHeight + 1), 0, buttonWidth, buttonHeight, fg, bg, ' ');
            pushTextMatrix(m, i * (buttonHeight + 1) + (buttonHeight / 2), buttonWidth / 2 - strlen(button[i].text) / 2, fg, bg, button[i].text);
        }

        flushMatrix(m);

        int pressedKey = lectureFleche();

        switch (pressedKey)
        {
            case NO_KEY:
                run = 0;
                break;
            case KEY_UP:
                if (buttonSelect > 0)
                    buttonSelect--;
                else
                    buttonSelect = NB_BUTTON - 1;
                break;
            case KEY_DOWN:
                if (buttonSelect < NB_BUTTON - 1)
                    buttonSelect++;
                else
                    buttonSelect = 0;
                break;
            default:
                break;
        }
    }

    finTerminalSansR();
}