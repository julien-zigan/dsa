#ifndef __JZ_UNIT_H__
#define __JZ_UNIT_H__

#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define WHT "\e[0;37m"

extern void init_testsuite();
extern void print_test_stat();
extern void init_test(const char *fname);
extern void assert_output_equals(char *expected, char *actual);

#endif
