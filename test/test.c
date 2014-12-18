#include "test.h"
#include "../src/color.h"
#include <stdio.h>

#define OFFSET_STR "    "
#define INT_TO_STR(x) (x) ? "true" : "false"

#define PASSED_STR  "V"
#define FAILED_STR   "X"

static unsigned int _offset = 0;
static unsigned int _nbAsserts = 0;
static unsigned int _nbFailedAsserts = 0;

static void _printOffset()
{
    int i;
    for(i = _offset; i != 0; i--)
        printf("%s", OFFSET_STR);
}

/**
 * Starts a new set of tests.
 * 
 * \param category The name of the category
 */
void describe(char *category)
{
    _printOffset();
    printf("%s :\n", category);
    _offset++;
}

/**
 * Asserts the test value and check if equal to expect.
 * 
 * \param desc A string describing the test value
 * \param test The value to test
 * \param expect The comparative value
 */
void assertEql(char *desc, int test, int expect)
{
    _printOffset();
    printf("%s : ", desc);
    
    _nbAsserts++;
    
    if(test == expect)
        color_printf(GREEN, BLACK, PASSED_STR);
    else
    {
        color_printf(RED, BLACK, "%s\n", FAILED_STR);
        _printOffset();
        color_printf(RED, BLACK, "Expected %d to be %d.", test, expect);
        _nbFailedAsserts++;
    }
    
    printf("\n");
}

/**
 * Asserts the test value and check if equal to expect.
 * 
 * \param desc A string describing the test value
 * \param test The value to test
 * \param notExpect The comparative value
 */
void assertDiff(char *desc, int test, int notExpect)
{
    _printOffset();
    printf("%s : ", desc);
    
    _nbAsserts++;
    
    if(test != notExpect)
        color_printf(GREEN, BLACK, PASSED_STR);
    else
    {
        color_printf(RED, BLACK, "%s\n", FAILED_STR);
        _printOffset();
        color_printf(RED, BLACK, "Expected %d not to be %d.", test, notExpect);
        _nbFailedAsserts++;
    }
    
    printf("\n");
}


/**
 * Asserts the test value and check if true.
 * 
 * \param desc A string describing the test value
 * \param test The value to test
 */
void assertTrue(char *desc, int test)
{
    _printOffset();
    printf("%s : ", desc);
    
    _nbAsserts++;
    
    if(test)
        color_printf(GREEN, BLACK, PASSED_STR);
    else
    {
        color_printf(RED, BLACK, "%s\n", FAILED_STR);
        _printOffset();
        color_printf(RED, BLACK, "Expected %s to be true.", INT_TO_STR(test));
        _nbFailedAsserts++;
    }
    
    printf("\n");
}

/**
 * Asserts the test value and check if false.
 * 
 * \param desc A string describing the test value
 * \param test The value to test
 */
void assertFalse(char *desc, int test)
{
    _printOffset();
    printf("%s : ", desc);
    
    _nbAsserts++;
    
    if(!test)
        color_printf(GREEN, BLACK, PASSED_STR);
    else
    {
        color_printf(RED, BLACK, "%s\n", FAILED_STR);
        _printOffset();
        color_printf(RED, BLACK, "Expected %s to be false.", INT_TO_STR(test));
        _nbFailedAsserts++;
    }
    
    printf("\n");
}

/**
 * Closes the last set of assets.
 */
void endDescribe()
{
    _offset--;
}

/**
 * Displays a recapitulative of the tests
 */
void recap()
{
    _printOffset();
    color_printf(
        (_nbFailedAsserts == 0) ? GREEN : RED,
        BLACK,
        
        "\n%d of %d assert(s) passed.\n%s.\n",
        _nbAsserts - _nbFailedAsserts,
        _nbAsserts,
        (_nbFailedAsserts == 0) ? "Success": "Failure"
    );
}