#pragma once

#include "matrix.h"
#include "../lib/color.h"
#include "../lib/saisieM.h"

typedef enum
{
	PLAY,
	LOAD,
	EXIT
} menuChoice;

typedef struct
{
	menuChoice choice;
	char *text;
} menuButton;

int menu(matrix *m);