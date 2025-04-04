#include <stdio.h>
#include <string.h>

#include "jz_unit.h"

static int run, passed, failed;

void init_testsuite()
{
    printf("\n"YELLOW"%2s running tests..."WHT"\n\n", "");
}

void init_test(const char *fname)
{
    printf("%6i. %-20s", ++run, fname);
}

void print_test_stat()
{
    printf(YELLOW"\n%2s Tests run : %d,"GREEN" passed: %d,"
           RED" failed: %d"WHT"\n\n\n", "", run, passed, failed);
}

void assert_output_equals(char *expected, char *actual)
{
    if (strcmp(expected, actual) == 0) {
        printf(GREEN"OK"WHT"\n");
        passed++;
    }
    else {
        printf(RED"FAILED: "WHT" expected: %s <==> actual: %s\n",
               expected, actual); 
        failed++;
    }
}
