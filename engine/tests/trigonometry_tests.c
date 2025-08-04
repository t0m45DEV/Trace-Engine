#include "tester.h"
#include "trigonometry.h"

#include <math.h>

void test_are_equals_trully_equal_numbers(void)
{
    ASSERT(are_equals(3.0, 6 / 2.0));
    ASSERT(are_equals(PI * 2, 6.2831853));
}

void test_are_equals_different_numbers(void)
{
    ASSERT(!are_equals(3.0, 4.0));
    ASSERT(!are_equals(1.5, 1.7));
    ASSERT(!are_equals(PI * 2, 6.2));    
}


void test_normalize_vector(void)
{
    position_2D_t east = (position_2D_t) {1, 0};
    position_2D_t north_east = (position_2D_t) {1, 1};
    position_2D_t random_point = (position_2D_t) {2, 7};

    ASSERT(vector_length(normalize_vector(east)) == 1);
    ASSERT(vector_length(normalize_vector(north_east)) == 1);
    ASSERT(vector_length(normalize_vector(random_point)) == 1);
}


void test_adjust_angle_same_angle(void)
{
    ASSERT(are_equals(adjust_angle(0), (float) 0));
    ASSERT(are_equals(adjust_angle(PI), (float) PI));
    ASSERT(are_equals(adjust_angle(PI / 2.0), (float) (PI / 2.0)));
    ASSERT(are_equals(adjust_angle(3 * PI / 2.0), (float) (3 * PI / 2.0)));
}

void test_adjust_angle_less_than_0(void)
{
    ASSERT(are_equals(adjust_angle(-PI), (float) PI));
    ASSERT(are_equals(adjust_angle(-PI / 2.0), (float) (3 * PI / 2.0)));
    ASSERT(are_equals(adjust_angle(-3 * PI / 2.0), (float) PI / 2.0));
}

void test_adjust_angle_more_than_2pi(void)
{
    ASSERT(are_equals(adjust_angle(2 * PI), (float) 0));
    ASSERT(are_equals(adjust_angle(5 * PI / 2.0), (float) PI / 2.0));
    ASSERT(are_equals(adjust_angle(3 * PI), (float) PI));
    ASSERT(are_equals(adjust_angle(7 * PI / 2.0), (float) (3 * PI / 2.0)));
}


void test_deg_to_rad_unit_circle(void)
{
    ASSERT(are_equals(DEG_TO_RAD(0), 0));
    ASSERT(are_equals(DEG_TO_RAD(90.0), (float) PI / 2.0));
    ASSERT(are_equals(DEG_TO_RAD(180.0), (float) PI));
    ASSERT(are_equals(DEG_TO_RAD(270.0), (float) 3 * PI / 2.0));
    ASSERT(are_equals(DEG_TO_RAD(360.0), 0));
}

void test_deg_to_rad_more_than_360(void)
{
    ASSERT(are_equals(DEG_TO_RAD(450.0), (float) PI / 2.0));
    ASSERT(are_equals(DEG_TO_RAD(540.0), (float) PI));
}

void test_deg_to_rad_less_than_0(void)
{
    ASSERT(are_equals(DEG_TO_RAD(-90.0), (float) 3 * PI / 2.0));
    ASSERT(are_equals(DEG_TO_RAD(-180.0), (float) PI));
}


void test_rad_to_deg_unit_circle(void)
{
    ASSERT(are_equals(RAD_TO_DEG(0), 0));
    ASSERT(are_equals(RAD_TO_DEG((float) PI / 2.0), 90.0));
    ASSERT(are_equals(RAD_TO_DEG((float) PI), 180.0));
    ASSERT(are_equals(RAD_TO_DEG((float) 3 * PI / 2.0), 270.0));
    ASSERT(are_equals(RAD_TO_DEG(2 * PI), 0));
}

void test_rad_to_deg_more_than_2pi(void)
{
    ASSERT(are_equals(RAD_TO_DEG((float) 5 * PI / 2), 90.0));
    ASSERT(are_equals(RAD_TO_DEG((float) 3 * PI), 180.0));
}

void test_rad_to_deg_less_than_0(void)
{
    ASSERT(are_equals(RAD_TO_DEG(-PI / 2), 270.0));
    ASSERT(are_equals(RAD_TO_DEG(-PI), 180.0));
}


void test_distance_between_same_point(void)
{
    position_2D_t origin = {0, 0};
    position_2D_t point_1 = {1, 1};
    position_2D_t point_2 = {247, -128};

    ASSERT(are_equals(distance_between(origin, origin), 0));
    ASSERT(are_equals(distance_between(point_1, point_1), 0));
    ASSERT(are_equals(distance_between(point_2, point_2), 0));
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

    ASSERT(are_equals(distance_between(origin, east),  (float) 1.0));
    ASSERT(are_equals(distance_between(origin, north), (float) 1.0));
    ASSERT(are_equals(distance_between(origin, west),  (float) 1.0));
    ASSERT(are_equals(distance_between(origin, south), (float) 1.0));

    ASSERT(are_equals(distance_between(origin, NE), (float) 1.0));
    ASSERT(are_equals(distance_between(origin, NW), (float) 1.0));
    ASSERT(are_equals(distance_between(origin, SW), (float) 1.0));
    ASSERT(are_equals(distance_between(origin, SE), (float) 1.0));
}

void test_distance_between_pythagorean_triple(void)
{
    position_2D_t point_1 = {0, 0};
    position_2D_t point_2 = {0, 3};
    position_2D_t point_3 = {4, 0};

    ASSERT(are_equals(distance_between(point_1, point_2), (float) 3));
    ASSERT(are_equals(distance_between(point_1, point_3), (float) 4));
    ASSERT(are_equals(distance_between(point_2, point_3), (float) 5));
}

void test_distance_between_ugly_numbers(void)
{
    position_2D_t point_1 = {-2, 1 / 3.0};
    position_2D_t point_2 = {3.5, 2};
    position_2D_t point_3 = {2.2, -2.8};

    ASSERT(are_equals(distance_between(point_1, point_2), (float) 5.7469798));
    ASSERT(are_equals(distance_between(point_2, point_3), (float) 4.9729267));
    ASSERT(are_equals(distance_between(point_3, point_1), (float) 5.2400169));
}


void init_trigonometry_suites(void)
{
    test_are_equals_trully_equal_numbers();
    test_are_equals_different_numbers();

    test_adjust_angle_same_angle();
    test_adjust_angle_more_than_2pi();
    test_adjust_angle_less_than_0();

    test_deg_to_rad_unit_circle();
    test_deg_to_rad_more_than_360();
    test_deg_to_rad_less_than_0();

    test_rad_to_deg_unit_circle();
    test_rad_to_deg_more_than_2pi();
    test_rad_to_deg_less_than_0();

    test_distance_between_same_point();
    test_distance_between_origin_unit_circle();
    test_distance_between_pythagorean_triple();
    test_distance_between_ugly_numbers();
}
