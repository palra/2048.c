#include <stdio.h>
#include "test.h"

int main()
{
    
    describe("Jeu");
        describe("Grid");
            assertTrue("setVal - is true", 1 == 1);
            assertTrue("setVal - is true", 1 == 2);
        endDescribe();
    endDescribe();
    
    recap();
    
    return 0;
}