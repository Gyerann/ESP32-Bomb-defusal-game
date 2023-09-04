#include <unity.h>
#include "simon_says.h"

#define TEST_TAG "test_simon_says"

void setUp(){

}

void tearDown(){

}

void test_solution_generated_is_not_null(){
    SimonSaysSeries simonSaysSeries;
    UNITY_TEST_ASSERT(simonSaysSeries.generate_series() != NULL);
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
    SimonSaysModule simonSaysModule;
    int seriesBefore = simonSaysModule.currentSeries;
    simonSaysModule.restart_series();
    UNITY_TEST_ASSERT(seriesBefore == simonSaysModule.currentSeries);
}

extern "C" int app_main(int argc, char** argv){
    UNITY_BEGIN();

    RUN_TEST(test_restart_series);
    RUN_TEST(test_solution_generated_is_not_null);

    UNITY_END();

    return 0;
}