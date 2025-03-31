#include <stdio.h>
#include <string.h>

#include "jz_unit.h"

static int tests_run = 0;
//TODO tests failed, tests passed...

void init_testsuite()
{
    printf("\n"YELLOW"%2s running tests..."WHT"\n\n", "");
}

void init_test(const char *fname)
{
    printf("%6i. %-20s", ++tests_run, fname);
}


void assert_output_equals(char *expected, char *actual)
{
    if (strcmp(expected, actual) == 0)
        printf(GREEN"OK"WHT"\n");
    else 
        printf(RED"FAILED: "WHT" expected: %s ===> actual: %s\n",
               expected, actual); 
}
