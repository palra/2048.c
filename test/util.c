#include "util.h"
#include "../src/util.h"

void util_nb_digits_asserts()
{
    describe("Nombre de chiffres d'un entier");
        
        assertEql("0 a 1 chiffre", nbDigits(0), 1);
        assertEql("9746512 a 7 chiffres", nbDigits(9746512), 7);
        assertEql("-746512 a 6 chiffres", nbDigits(-746512), 6);
        
    endDescribe();
}

void test_util()
{
    describe("Utilitaires");
        util_nb_digits_asserts();
    endDescribe();
}