#include "mouvement.h"
#include "test.h"

#include "../src/jeu.h"
#include "../src/mouvement.h"

void mouvements_ligne_asserts()
{
  jeu j;
  initialiseJeu(&j, 4, 2048);

  setVal(&j, 0, 0, 2);
  setVal(&j, 0, 1, 2);
  setVal(&j, 0, 2, 8);

  describe("Ligne");
    int aBougeUneCase = mouvement(&j, MVT_GAUCHE);
    assertEql("mouvement(&j, ...) doit incrémenter le score selon les valeurs de la grille ...", j.score, 4);
    assertTrue("... et retourner 1 si une case a été déplacée", aBougeUneCase);

    aBougeUneCase = mouvement(&j, MVT_DROITE);
    assertEql("mouvement(&j, ...) ne doit pas incrémenter le score si aucun point n'a été marqué ...", j.score, 4);

    aBougeUneCase = mouvement(&j, MVT_DROITE);
    assertFalse("... et retourner 0 si aucune case n'a été déplacée", aBougeUneCase);

  endDescribe();
}

void mouvements_colonne_asserts()
{
  jeu j;
  initialiseJeu(&j, 4, 2048);

  setVal(&j, 0, 0, 2);
  setVal(&j, 1, 0, 2);
  setVal(&j, 2, 0, 8);

  describe("Colonne");
    int aBougeUneCase = mouvement(&j, MVT_HAUT);
    assertEql("mouvement(&j, ...) doit incrémenter le score selon les valeurs de la grille ...", j.score, 4);
    assertTrue("... et retourner 1 si une case a été déplacée", aBougeUneCase);

    aBougeUneCase = mouvement(&j, MVT_BAS);
    assertEql("mouvement(&j, ...) ne doit pas incrémenter le score si aucun point n'a été marqué ...", j.score, 4);

    aBougeUneCase = mouvement(&j, MVT_BAS);
    assertFalse("... et retourner 0 si aucune case n'a été déplacée", aBougeUneCase);

  endDescribe();
}

void test_mouvement()
{
  describe("Mouvements");
    mouvements_ligne_asserts();
  endDescribe();
}