#include <unity.h>
#include "simon_says.h"

#define TEST_TAG "test_simon_says"

void setUp(){

}

void tearDown(){

}

void test_solution_generated_is_not_null(){
    SimonSaysSeries simonSaysSeries;
    TEST_ASSERT(simonSaysSeries.generate_series(1) != NULL);
}

void test_solution_generated_is_valid(){
}

void test_current_solution_matching_generated_solution(){

}

void test_continue_series(){

}

void test_solve_module(){

}

void test_restart_series(){
}

extern "C" int app_main(int argc, char** argv){
    UNITY_BEGIN();

    RUN_TEST(test_solution_generated_is_not_null);

    UNITY_END();

    return 0;
}