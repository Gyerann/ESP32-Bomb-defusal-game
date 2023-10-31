#include <unity.h>
#include "module.h"

#define TEST_TAG "test_module_base_classs"

void setUp(){

}

void tearDown(){

}

void test_activeModules_increase_on_init(){
    Module testModule1();
    TEST_ASSERT(testModule1->_s_activeModules == 1);
    Module testModule2();
    TEST_ASSERT(testModule1->_s_activeModules == 2);
    TEST_ASSERT(testModule2->_s_activeModules == 2);
}

/*
void test_solution_generated_is_uint8_t(){
    CutTheWireModule testModule(0xff);
    TEST_ASSERT((testModule.currentSolution >= 0) and (testModule.currentSolution < 255));

    CutTheWireModule testModule2(0x7f);
    TEST_ASSERT((testModule.currentSolution >= 0) and (testModule.currentSolution < 255));

    CutTheWireModule testModule3(0x00);
    TEST_ASSERT((testModule.currentSolution >= 0) and (testModule.currentSolution < 255));

    CutTheWireModule testModule4((rand() % 255));
    TEST_ASSERT((testModule.currentSolution >= 0) and (testModule.currentSolution < 255));
}
*/

extern "C" int app_main(int argc, char** argv){
    UNITY_BEGIN();
        //RUN_TEST(test_solution_generated_is_uint8_t);
    UNITY_END();

    return 0;
}