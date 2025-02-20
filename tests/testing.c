#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <stdlib.h>

#include "trigonometry_tests.c"

void print_failed_tests(const CU_pFailureRecord failed_tests)
{
    CU_pFailureRecord actual = failed_tests;
    int count = 1;

    while (actual != NULL)
    {
        printf(" == Fail #%i ==\n", count);
        printf("  SUITE:      %s\n", actual->pSuite->pName);
        printf("  TEST:       %s\n", actual->pTest->pName);
        printf("  CONDITION:  %s\n", actual->strCondition);
        printf("\n");

        actual = actual->pNext;
        count++;
    }
}

void print_tests_result(void)
{
    CU_pRunSummary summary = CU_get_run_summary();

    printf("\n");
    printf(" |--------------------------|  |--------------|\n");
    printf(" | TOTAL | SUCCEED | FAILED |  | ELAPSED TIME |\n");
    printf(" |-------|---------|--------|  |--------------|\n");
    printf(" | %5i | %7i | %6i |  | %12f |\n",
        summary->nAsserts,
        summary->nAsserts - summary->nAssertsFailed,
        summary->nAssertsFailed,
        summary->ElapsedTime
    );
    printf(" |--------------------------|  |--------------|\n");
    printf("\n");

    print_failed_tests(CU_get_failure_list());
}

int main(void)
{
    CU_initialize_registry();
    CU_set_output_filename(NULL);

    init_trigonometry_suites();
    CU_automated_run_tests();

    int fail_count = CU_get_number_of_failures();

    print_tests_result();
    CU_cleanup_registry();

    if (fail_count > 0)
    {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
