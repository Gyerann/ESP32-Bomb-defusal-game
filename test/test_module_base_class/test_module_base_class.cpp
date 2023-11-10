#include <unity.h>
#include "module.h"

void setUp(){

}

void tearDown(){

}

void test_module_created(){
    Module testModule;
    TEST_ASSERT_TRUE_MESSAGE(testModule.check_is_active(), "check_is_active returned 0.");
}

void test_state_is_null(){
    Module testModule;
    TEST_ASSERT_NULL_MESSAGE(testModule.check_state(), "check_state didnt return NULL.");
}

extern "C" int app_main(int argc, char** argv){
    UNITY_BEGIN();
        RUN_TEST(test_module_created);
        RUN_TEST(test_state_is_null);
    UNITY_END();

    return 0;
}