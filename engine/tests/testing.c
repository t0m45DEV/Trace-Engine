#include <stdlib.h>

#include "trigonometry_tests.c"

#include <time.h>

int main(void)
{
    clock_t start, end;

    start = clock();
    init_trigonometry_suites();
    end = clock();

    double time = ((double) (end - start)) / CLOCKS_PER_SEC;

    TESTS_PASSED(time);
    exit(EXIT_SUCCESS);
}
