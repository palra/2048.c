#ifndef TEST_H
#define TEST_H

void describe(char *category);

void assert(char *desc, int test, int expect);
void assertTrue(char *desc, int test);
void assertFalse(char *desc, int test);

void endDescribe();

#endif