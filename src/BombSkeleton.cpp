#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "tm1637.h"
#include "analog_servo.h"

#define PWM_PIN GPIO_NUM_33
#define TM1637_CLK_PIN GPIO_NUM_18
#define TM1637_DIO_PIN GPIO_NUM_19
#define BEEP_PIN GPIO_NUM_17
#define STRIKE_1_PIN GPIO_NUM_4
#define STRIKE_2_PIN GPIO_NUM_16
#define STRIKE_3_PIN GPIO_NUM_2
#define MORSE_PIN GPIO_NUM_0

#define STRIKE_BTN GPIO_NUM_33

#define SOUND_ON true

void add_strike(int *currStrikes){
*currStrikes = *currStrikes + 1;
switch(*currStrikes) {
    case 1:
        gpio_set_level(STRIKE_1_PIN, 1);
        break;
    case 2:
        gpio_set_level(STRIKE_2_PIN, 1);
        break;
    case 3:
        gpio_set_level(STRIKE_3_PIN, 1);
        break;
}
}

//Updates display timer
void update_timer(tm1637_led_t* display, int *currTime) {
    *currTime = *currTime - 1;
    tm1637_set_number_lead_dot(display, *currTime, 0, 0b11111111);
    beep();
    vTaskDelay(875 / portTICK_PERIOD_MS);
}

void time_over() {
    gpio_set_level(STRIKE_1_PIN, 1);
    gpio_set_level(STRIKE_2_PIN, 1);
    gpio_set_level(STRIKE_3_PIN, 1);
}

//Refactor so ScheduledTaskHandler calls this every 125ms and it doesnt halt control flow
void beep(){
    if(SOUND_ON){
        gpio_set_level(BEEP_PIN, 1);
        vTaskDelay(125 / portTICK_PERIOD_MS);
        gpio_set_level(BEEP_PIN, 0);
    }
}

//Initializing GPIO pins
void init_gpio_pins(){
    esp_err_t beepPinDir = gpio_set_direction(BEEP_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(BEEP_PIN, 0);

    esp_err_t strike1Pin = gpio_set_direction(STRIKE_1_PIN, GPIO_MODE_OUTPUT);
    esp_err_t strike2Pin = gpio_set_direction(STRIKE_2_PIN, GPIO_MODE_OUTPUT);
    esp_err_t strike3Pin = gpio_set_direction(STRIKE_3_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(STRIKE_1_PIN, 0);
    gpio_set_level(STRIKE_2_PIN, 0);
    gpio_set_level(STRIKE_3_PIN, 0);

    esp_err_t strikeBtnPin = gpio_set_direction(STRIKE_BTN, GPIO_MODE_INPUT);
    gpio_set_level(STRIKE_BTN, 0);
}

//Handler for player reladet stuff
class PlayerHandler{

    public:
    void init_player_handler(){
        /*
        .
        .
        .
        */
    }
};

//Handler for networking
class NetworkHandler{

    public:
    void init_network_handler(){
        /*
        ESP32 REST API setup
        */
    }
};

class Module{
    //Default module stuff, child class defines behavior
    /*
    .
    .
    .
    */
};

//Handler for bomb modules
class ModuleHandler{

    public:
    void discover_modules(){
        //How to do this? Challenge response if module has a microcontroller?
        /*
        .
        .
        .
        */
    }

    void init_module_handler(){
        discover_modules();
    }
};

//Handler for scheduled tasks e.g: beep
class ScheduledHandler{
    
    public:
    void init_scheduled_handler(){

    }
};

class BombConfig{

    public:

    char strikes = 3;
    char time = 90;
    char difficulty = 1;
    bool sound = true;

    void init_bomb_config(){

    }
};

void init_bomb(PlayerHandler* playerHandler, NetworkHandler* networkHandler, ModuleHandler* moduleHandler, ScheduledHandler* scheduledHandler, BombConfig* bombConfig){
    bombConfig->init_bomb_config();
    playerHandler->init_player_handler();
    networkHandler->init_network_handler();
    moduleHandler->init_module_handler();
    scheduledHandler->init_scheduled_handler();
}

int main() {
    BombConfig bombConfig;
    PlayerHandler playerHandler;
    NetworkHandler networkHandler;
    ModuleHandler moduleHandler;
    ScheduledHandler scheduledHandler;

    init_bomb(&playerHandler, &networkHandler, &moduleHandler, &scheduledHandler, &bombConfig);

    return 0;
}