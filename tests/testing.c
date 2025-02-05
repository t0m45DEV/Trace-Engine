#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>

#include "trigonometry_tests.c"

int main(void)
{
    CU_initialize_registry();
    CU_basic_set_mode(CU_BRM_SILENT);
    init_trigonometry_suites();

    CU_basic_run_tests();

    int fail_count = CU_get_number_of_failures();

    CU_basic_show_failures(CU_get_failure_list());
    CU_cleanup_registry();
    printf("\n\n");

    if (fail_count > 0)
    {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
