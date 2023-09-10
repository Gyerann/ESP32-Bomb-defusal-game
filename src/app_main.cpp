#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "tm1637.h"
#include "servo_analog.h"
#include "./config.h"
#include "cut_the_wire.h"
#include "esp_log.h"
#include "iostream"
#include "gpio_handler.h"
#include "bitset"

/*
TODO:
Use esp idf wrapper classes for GPIO handling
*/

extern "C" void app_main() {
    uint8_t ctwSeed = rand();
    CutTheWireModule cutTheWireModule(ctwSeed);
    GPIOHandler gpioHandler;


    //For testing
    while(1){
        cutTheWireModule.get_state();
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}