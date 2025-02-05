#include <CUnit/CUnit.h>
#include "trigonometry.h"


void test_are_equals_trully_equal_numbers(void)
{
    CU_ASSERT(are_equals(3.0, 6 / 2.0));
    CU_ASSERT(are_equals(PI * 2, 6.2831853));
}

void test_are_equals_different_numbers(void)
{
    CU_ASSERT(!are_equals(3.0, 4.0));
    CU_ASSERT(!are_equals(1.5, 1.7));
    CU_ASSERT(!are_equals(PI * 2, 6.2));
}


void test_adjust_angle_same_angle(void)
{
    CU_ASSERT(are_equals(adjust_angle(0), (float) 0));
    CU_ASSERT(are_equals(adjust_angle(PI), (float) PI));
    CU_ASSERT(are_equals(adjust_angle(PI / 2.0), (float) (PI / 2.0)));
    CU_ASSERT(are_equals(adjust_angle(3 * PI / 2.0), (float) (3 * PI / 2.0)));
}

void test_distance_between_same_point(void)
{
    position_2D_t origin = {0, 0};
    position_2D_t point_1 = {1, 1};
    position_2D_t point_2 = {247, -128};

    CU_ASSERT(are_equals(distance_between(origin, origin), 0));
    CU_ASSERT(are_equals(distance_between(point_1, point_1), 0));
    CU_ASSERT(are_equals(distance_between(point_2, point_2), 0));
}

void test_distance_between_origin_unit_circle(void)
{
    position_2D_t origin = {0,  0};

    position_2D_t east   = { 1,  0};
    position_2D_t north  = { 0,  1};
    position_2D_t west   = {-1,  0};
    position_2D_t south  = { 0, -1};

    float diagonal_component = sqrt(2) / 2.0;
    position_2D_t NE = { diagonal_component,  diagonal_component};
    position_2D_t NW = {-diagonal_component, diagonal_component};
    position_2D_t SW = {-diagonal_component, -diagonal_component};
    position_2D_t SE = { diagonal_component, -diagonal_component};

    CU_ASSERT(are_equals(distance_between(origin, east),  (float) 1.0));
    CU_ASSERT(are_equals(distance_between(origin, north), (float) 1.0));
    CU_ASSERT(are_equals(distance_between(origin, west),  (float) 1.0));
    CU_ASSERT(are_equals(distance_between(origin, south), (float) 1.0));

    CU_ASSERT(are_equals(distance_between(origin, NE), (float) 1.0));
    CU_ASSERT(are_equals(distance_between(origin, NW), (float) 1.0));
    CU_ASSERT(are_equals(distance_between(origin, SW), (float) 1.0));
    CU_ASSERT(are_equals(distance_between(origin, SE), (float) 1.0));
}

void test_distance_between_pythagorean_triple(void)
{
    position_2D_t point_1 = {0, 0};
    position_2D_t point_2 = {0, 3};
    position_2D_t point_3 = {4, 0};

    CU_ASSERT(are_equals(distance_between(point_1, point_2), (float) 3));
    CU_ASSERT(are_equals(distance_between(point_1, point_3), (float) 4));
    CU_ASSERT(are_equals(distance_between(point_2, point_3), (float) 5));
}

void test_distance_between_ugly_numbers(void)
{
    position_2D_t point_1 = {-2, 1 / 3.0};
    position_2D_t point_2 = {3.5, 2};
    position_2D_t point_3 = {2.2, -2.8};

    CU_ASSERT(are_equals(distance_between(point_1, point_2), (float) 5.7469798));
    CU_ASSERT(are_equals(distance_between(point_2, point_3), (float) 4.9729267));
    CU_ASSERT(are_equals(distance_between(point_3, point_1), (float) 5.2400169));
}


void init_trigonometry_suites(void)
{
    CU_pSuite are_equals_suite = CU_add_suite("Test Suite for are_equals()", 0, 0);
    CU_add_test(are_equals_suite, "Equals numbers", test_are_equals_trully_equal_numbers);
    CU_add_test(are_equals_suite, "Different numbers", test_are_equals_different_numbers);

    CU_pSuite adjust_angle_suite = CU_add_suite("Test Suite for adjust_angle()", 0, 0);
    CU_add_test(adjust_angle_suite, "Same angle", test_adjust_angle_same_angle);

    CU_pSuite distance_between_suite = CU_add_suite("Test Suite for distance_between()", 0, 0);
    CU_add_test(distance_between_suite, "Same point", test_distance_between_same_point);
    CU_add_test(distance_between_suite, "Unit Circle", test_distance_between_origin_unit_circle);
    CU_add_test(distance_between_suite, "Pythagorean triple (3, 4, 5)", test_distance_between_pythagorean_triple);
    CU_add_test(distance_between_suite, "Ugly numbers", test_distance_between_ugly_numbers);
}
