#include <unity.h>
#include "cut_the_wire.h" 
#include "player.h"

#define TEST_TAG "test_cut_the_wire_module"

void setUp(){

}

void tearDown(){

}

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

void test_check_module(){
}

void test_solve_module_increases_modulesSolved(){
    CutTheWireModule cutTHeWireModule(1);
    PlayerModule playerModule;

    uint8_t initialSolves = playerModule.modulesSolved;
    cutTHeWireModule.solve_module(&playerModule);
    TEST_ASSERT((initialSolves + 1) == playerModule.modulesSolved);
}

void test_get_module_state(){
    
}

extern "C" int app_main(int argc, char** argv){
    UNITY_BEGIN();
        RUN_TEST(test_solution_generated_is_uint8_t);
        RUN_TEST(test_solve_module_increases_modulesSolved);
    UNITY_END();

    return 0;
}