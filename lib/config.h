#include "driver/gpio.h"
#include <random>
#include "esp_log.h"

//Module tags
#define CTW_TAG "Cut the Wire"
#define PLAYER_TAG "Player"

//Cut the Wire options
#define CTW_WIRE_1  GPIO_NUM_5
#define CTW_WIRE_2  GPIO_NUM_17
#define CTW_WIRE_3  GPIO_NUM_16
#define CTW_WIRE_4  GPIO_NUM_4
#define CTW_WIRE_5  GPIO_NUM_34
#define CTW_WIRE_6  GPIO_NUM_35

//PlayerModule options
#define SOUND_ON true  
#define TIMER_START 90
#define SPEAKER_PIN     GPIO_NUM_32
#define TIMER_PIN_CLK   GPIO_NUM_14
#define TIMER_PIN_DIO   GPIO_NUM_27
#define STRIKE_LED_1    GPIO_NUM_26
#define STRIKE_LED_2    GPIO_NUM_25
#define STRIKE_LED_3    GPIO_NUM_33

//OLED Display options
#define DISPLAY_SDA_PIN GPIO_NUM_22
#define DISPLAY_SCL_PIN GPIO_NUM_21
#define DISPLAY_RESET_PIN GPIO_NUM_26