#include <unity.h>
#include "defusable_module.h"

void setUp(){

}

void tearDown(){

}

void test_module_is_not_solved_on_init(){
    DefusableModule testModule;
    TEST_ASSERT_FALSE_MESSAGE(testModule.check_module_is_solved(), "check_module_is_solved returned true on init.");
}

void test_solution_is_null(){
    DefusableModule testModule;
    TEST_ASSERT_NULL_MESSAGE(testModule.get_solution(), "get_solution didnt return NULL on init.");
}

extern "C" int app_main(int argc, char** argv){
    UNITY_BEGIN();
        RUN_TEST(test_module_is_not_solved_on_init);
        RUN_TEST(test_solution_is_null);
    UNITY_END();

    return 0;
}