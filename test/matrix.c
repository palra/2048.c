#include "matrix.h"

#include "../src/matrix.h"
#include "test.h"

void matrix_alloc_asserts()
{
    matrix m;
    
    describe("Allocation");
    
        initMatrix(&m, 4*3, 4*7);
    
        assertDiff("m.p devrait etre different de NULL", (int) m.p, NULL);
        assertFalse("m.p[0..w*h].c devrait etre \\0", m.p[5].c);
        assertFalse("m.p[0..w*h].fg devrait etre BLACK", m.p[5].fg);
        assertFalse("m.p[0..w*h].bg devrait etre BLACK", m.p[5].bg);
        assertEql("m.w devrait etre 12", m.w, 12);
        assertEql("m.h devrait etre 28", m.h, 28);
        
    endDescribe();
    describe("Liberation");
    
        freeMatrix(&m);
    
        assertEql("m.p devrait etre NULL", (int) m.p, NULL);
        assertFalse("m.w devrait etre nul", m.w);
        assertFalse("m.h devrait etre nul", m.h);
    
    endDescribe();
}

void matrix_pixel_test()
{
    matrix m;
    initMatrix(&m, 4*3, 4*7);
    
    describe("Pixel");
    
        describe("getPixelMatrix");
            
            pixel *p = getPixelMatrix(&m, 4, 7);
            assertDiff("getPixelMatrix doit renvoyer un pointeur pour une position correcte", p, NULL);
            
            p = getPixelMatrix(&m, 4564, 7946);
            assertEql(".. et NULL pour une position incorrecte", p, NULL);
            
        endDescribe();
        
    endDescribe();
    
    freeMatrix(&m);
}

void test_matrix()
{
    describe("Matrice d'affichage");
        matrix_alloc_asserts();
        matrix_pixel_test();
    endDescribe();
}