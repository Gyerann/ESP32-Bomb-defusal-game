#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "tm1637.h"
#include "analog_servo.h"
#include "morse.h"

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

//Beeps
void beep() {
    if(SOUND_ON){
        gpio_set_level(BEEP_PIN, 1);
        vTaskDelay(125 / portTICK_PERIOD_MS);
        gpio_set_level(BEEP_PIN, 0);
    } else {
        vTaskDelay(125 / portTICK_PERIOD_MS);
    }  
}

//Updates display timer
void update_timer(tm1637_led_t* display, int *currTime) {
    *currTime = *currTime - 1;
    tm1637_set_number_lead_dot(display, *currTime, 0, 0b11111111);
    beep();
    vTaskDelay(875 / portTICK_PERIOD_MS);
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

//Adds a strike
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

void time_over() {
    gpio_set_level(STRIKE_1_PIN, 1);
    gpio_set_level(STRIKE_2_PIN, 1);
    gpio_set_level(STRIKE_3_PIN, 1);
}

void update_modules() {


}

/*
set_servo_angle(PWM_PIN, 80);
*/

//Main
void app_main() {

init_gpio_pins();
init_pwm_fade(PWM_PIN);

//Display setup
tm1637_led_t* tm1637 = tm1637_init(TM1637_CLK_PIN, TM1637_DIO_PIN);
tm1637_set_brightness(tm1637, 4);

//Variables
int secondsLeft = 30;
int maxStrikes = 3;
int currStrikes = 0;

bool isPlayerAlive = true;
bool solved = false;

morse_blink("SOS", STRIKE_1_PIN);

//Main loop
while (secondsLeft > 0 && !solved) {
        update_timer(tm1637, &secondsLeft);
        update_modules();

        if(gpio_get_level(STRIKE_BTN) == 1){
            add_strike(&currStrikes);
        }

    }

time_over();

}
