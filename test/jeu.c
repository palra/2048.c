#include "test.h"
#include "../src/jeu.h"

void jeu_alloc_asserts()
{
    jeu p;
    
    describe("Allocation");
    
        initialiseJeu(&p, 4, 2048);
    
        assertDiff("p.grille devrait etre different de NULL", p.grille, NULL);
        assertEql("p.n devrait etre egal a 4", p.n, 4);
        assertEql("p.nbCasesLibres devrait etre egal a n*n", p.nbCasesLibres, p.n * p.n);
        assertEql("p.valMax devrait etre egal a 2048", p.valMax, 2048);
        
    endDescribe();
    describe("Liberation");
    
        libereMemoire(&p);
    
        assertEql("p.grille devrait etre NULL", p.grille, NULL);
        assertEql("p.n devrait etre egal a -1", p.n, -1);
        assertEql("p.nbCasesLibres devrait etre egal a -1", p.nbCasesLibres, -1);
        assertEql("p.valMax devrait etre egal a -1", p.valMax, -1);
    
    endDescribe();
}

void test_jeu()
{
    describe("Jeu (structure)");
        jeu_alloc_asserts();
    endDescribe();
}