#include "minunit.h"

char *test_gut_init()
{
    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_gut_init);

    return NULL;
}

RUN_TESTS(all_tests);
