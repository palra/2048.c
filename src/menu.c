#include "menu.h"

#define NB_BUTTON 3

/* \fn mennu
 *    
 *    Affiche un menu et attend que l'utilisateur choisisse un boutton
 *    
 *    \param *m : matrice dans laquelle va être affiché le menu 
 *    
*/
int menu(matrix *m)
{
	int run = 1, // Si à 0, on sort du menu
		pressedKey = 0,
		buttonSelect = 0, // Numero du boutton selectionné
		i = 0;

	menuButton button[NB_BUTTON]; // Liste des bouttons a afficher

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

        /* Affichage des bouttons */
        for (i = 0; i < NB_BUTTON; i ++)
        {
            // On regle la couleur du boutton en fonction de s'il est selectionné ou pas
            if (i == buttonSelect) {
                fg = WHITE;
                bg = RED;
            } else {
                fg = BLACK;
                bg = WHITE;
            }

            // Affichage du rectangle et du texte
            pushRectMatrix(m, i * (buttonHeight + 1) + m->h / 2 - NB_BUTTON * (buttonHeight + 1) / 2, m->w / 2 - buttonWidth / 2, buttonWidth, buttonHeight, fg, bg, ' ');
            pushTextMatrix(m, i * (buttonHeight + 1) + (buttonHeight / 2) + m->h / 2 - NB_BUTTON * (buttonHeight + 1) / 2, buttonWidth / 2 - strlen(button[i].text) / 2 + m->w / 2 - buttonWidth / 2, fg, bg, button[i].text);
        }

        flushMatrix(m);

        // Lecture du clavier
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

    return button[buttonSelect].choice;
}