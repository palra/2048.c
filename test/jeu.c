#include "test.h"
#include "../src/jeu.h"

void jeu_alloc_asserts()
{
    jeu p;
    
    describe("Allocation");
    
        initialiseJeu(&p, 4, 2048);
    
        assertDiff("p.grille devrait etre different de NULL", p.grille, NULL);
        assertEql("p.grille[0..n*n] devrait etre 0", p.grille[5], 0);
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

void jeu_index_asserts()
{
    jeu p;
    
    initialiseJeu(&p, 4, 2048);
    
    describe("Indices");
        
        assertTrue("(3,3) est dans la grille de dimension 4", indiceValide(&p, 3, 3));
        assertTrue("(0,0) est dans la grille de dimension 4", indiceValide(&p, 0, 0));
        assertFalse("(5,2) n'est pas dans la grille de dimension 4", indiceValide(&p, 5, 2));
        assertFalse("(1,8) n'est pas dans la grille de dimension 4", indiceValide(&p, 1, 8));
        assertFalse("(42,9) n'est pas dans la grille de dimension 4", indiceValide(&p, 42, 9));
        assertFalse("(-3,8) n'est pas dans la grille de dimension 4", indiceValide(&p, -3, 8));
        assertFalse("(42,-9) n'est pas dans la grille de dimension 4", indiceValide(&p, 42, -9));
        assertFalse("(-3,-9) n'est pas dans la grille de dimension 4", indiceValide(&p, -3, -9));
        
    endDescribe();
    
    libereMemoire(&p);
}

void jeu_get_set_asserts()
{
    jeu p;
    
    initialiseJeu(&p, 4, 2048);
    
    describe("Getters/Setters");
        
        setVal(&p, 0, 0, 2);
        assertEql("(0,0) <- 2", getVal(&p, 0, 0), 2);
        
        setVal(&p, 0, 0, 4);
        assertEql("(0,0) <- 4", getVal(&p, 0, 0), 4);
        
        assertEql("(5,3) n'existe pas : -1", getVal(&p, 5, 3), -1);
        
    endDescribe();
    
    libereMemoire(&p);
}

void test_jeu()
{
    describe("Jeu (structure)");
        jeu_alloc_asserts();
        jeu_index_asserts();
        jeu_get_set_asserts();
    endDescribe();
}