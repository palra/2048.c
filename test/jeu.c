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
        assertEql("Le compteur de cases vide doit être mis à jour", p.nbCasesLibres, p.n*p.n - 1);
        
        setVal(&p, 0, 0, 0);
        assertEql("(0,0) <- 0", getVal(&p, 0, 0), 0);
        assertEql("Le compteur de cases vide doit être mis à jour", p.nbCasesLibres, p.n*p.n);
        
        setVal(&p, 0, 0, 4);
        assertEql("(0,0) <- 4", getVal(&p, 0, 0), 4);
        
        assertEql("(5,3) n'existe pas : -1", getVal(&p, 5, 3), -1);
        
    endDescribe();
    
    libereMemoire(&p);
}

void jeu_case_vide_asserts()
{
    jeu p;
    
    initialiseJeu(&p, 4, 2048);
    
    describe("Case vide");
        
        assertTrue("(0,0) est vide", caseVide(&p, 0, 0));
        
        setVal(&p, 0, 3, 4);
        assertFalse("(0,3) n'est pas vide", caseVide(&p, 0, 3));
        assertFalse("(42,1337) n'existe pas", caseVide(&p, 42, 1337));
        
    endDescribe();
    
    libereMemoire(&p);
}

void jeu_val_alea_asserts()
{
    jeu p;
    
    initialiseJeu(&p, 2, 2048);
    
    describe("Valeurs aleatoires");
        
        ajouteValAlea(&p);
        assertEql("p.nbCasesLibres doit etre decremente", p.nbCasesLibres, (p.n * p.n )- 1);
        
        ajouteValAlea(&p);
        ajouteValAlea(&p);
        ajouteValAlea(&p);
        ajouteValAlea(&p);
        assertEql("Une fois la grille remplie ...", p.nbCasesLibres, 0);
        assertTrue(".. ajouter une valeur en trop ne doit pas bloquer le programme", 1);
        
        
    endDescribe();
        
    libereMemoire(&p);
}

void jeu_gagne_asserts()
{
    jeu p;
    
    initialiseJeu(&p, 2, 2048);
    
    describe("Gagne");
        
        assertFalse("Au départ, le jeu n'est pas gagne (trop facile sinon)", gagne(&p));
        
        setVal(&p, 0, 0, 16);
        assertFalse("Il ne l'est toujours pas si il a une quelquonque valeur dans la grille ...", gagne(&p));
        
        
        setVal(&p, 0, 1, 32);
        setVal(&p, 1, 0, 64);
        setVal(&p, 1, 1, 2047); // Oui cette valeur ne sera jamais dans un jeu
        assertFalse("... ou si la grille est remplie", gagne(&p));
        
        setVal(&p, 1, 1, p.valMax);
        assertTrue("... mais l'est si la valeur maximale est atteinte", gagne(&p));
        
        
        setVal(&p, 1, 1, p.valMax + 1);
        assertTrue("... ou depassee", gagne(&p));
        
    endDescribe();
        
    libereMemoire(&p);
}

void jeu_perdu_asserts()
{
    jeu p;
    
    initialiseJeu(&p, 2, 2048);
    
    describe("Perdu");
        
        assertFalse("Au depart, le jeu n'est pas perdu (trop dur sinon)", perdu(&p));
        
        setVal(&p, 0, 0, 16);
        assertFalse("Il ne l'est toujours pas si il a une quelquonque valeur dans la grille ...", perdu(&p));
        
        setVal(&p, 0, 1, 32);
        setVal(&p, 1, 0, 64);
        setVal(&p, 1, 1, 2048); // Oui cette valeur ne sera jamais dans un jeu
        assertTrue("... mais l'est si la grille est remplie et que les valeurs adjacentes ne sont pas egales", perdu(&p));
        
        setVal(&p, 0, 0, 0);
        assertFalse("... mais le n'est plus si il reste une case (ou plus) vide", perdu(&p));
        
        setVal(&p, 0, 0, 32);
        assertFalse("... ou si deux valeurs adjacentes sont egales, hoizontalement ...", perdu(&p));
        
        setVal(&p, 0, 0, 64);
        assertFalse("... ou verticalement", perdu(&p));
        
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
    describe("Jeu (utilitaires)");
        jeu_case_vide_asserts();
        jeu_val_alea_asserts();
        jeu_gagne_asserts();
        jeu_perdu_asserts();
    endDescribe();
}