#include <unity.h>
#include "player.h"

#define TEST_TAG "test_playermodule"

void setUp(){

}

void tearDown(){

}

void test_strike(){
    PlayerModule playerModule;
    StrikeModule strikeModule;
    TEST_ASSERT(strikeModule.currentStrikes == 0);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_1) == 0);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_2) == 0);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_3) == 0);

    strikeModule.add_strike(playerModule);
    TEST_ASSERT(strikeModule.currentStrikes == 1);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_1) == 1);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_2) == 0);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_3) == 0);

    strikeModule.add_strike(playerModule);
    TEST_ASSERT(strikeModule.currentStrikes == 2);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_1) == 1);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_2) == 1);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_3) == 0);

    strikeModule.add_strike(playerModule);
    TEST_ASSERT(strikeModule.currentStrikes == 3);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_1) == 1);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_2) == 1);
    TEST_ASSERT(gpio_get_level(STRIKE_LED_3) == 1);
}

void test_timer(){
    PlayerModule playerModule;
    TimerModule timerModule;
}

void test_solves_after_setup_equals_zero(){
    PlayerModule playerModule;
    TEST_ASSERT(playerModule.modulesSolved == 0);
}

extern "C" int app_main(int argc, char** argv){
    UNITY_BEGIN();
    RUN_TEST(test_strike);
    RUN_TEST(test_solves_after_setup_equals_zero);
    UNITY_END();

    return 0;
}