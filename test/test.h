#ifndef TEST_H
#define TEST_H

void describe(char *category);

void assertEql(char *desc, int test, int expect);
void assertDiff(char *desc, int test, int notExpect);
void assertTrue(char *desc, int test);
void assertFalse(char *desc, int test);

void endDescribe();
void recap();

#endif