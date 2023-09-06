#include <unity.h>
#include "simon_says.h"

#define TEST_TAG "test_simon_says"

void setUp(){

}

void tearDown(){

}

void test_solution_generated_is_valids(){
    SimonSaysSeries simonSaysSeries;
    uint8_t* generatedSeries[7];
    for (uint8_t i = 0; i < UINT8_MAX; i++){
        simonSaysSeries.generate_series(i, generatedSeries);
        TEST_ASSERT(generatedSeries[6] == 0);
        TEST_ASSERT(generatedSeries[0] != 0);
        TEST_ASSERT(generatedSeries[1] != 0);
        TEST_ASSERT(generatedSeries[2] != 0);
    }
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

    RUN_TEST(test_solution_generated_is_valid);

    UNITY_END();

    return 0;
}