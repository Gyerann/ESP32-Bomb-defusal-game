#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "./Hardware/tm1637.h"
#include "./Hardware/servo_analog.h"
#include "./config.h"
#include "./Modules/cut_the_wire.h"
#include "esp_log.h"
#include "bitset"
#include "iostream"
#include "./Hardware/gpio_handler.h"

void setup_ctw(){
    esp_rom_gpio_pad_select_gpio(CTW_WIRE_1);
    gpio_set_direction(CTW_WIRE_1, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_2);
    gpio_set_direction(CTW_WIRE_2, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_3);
    gpio_set_direction(CTW_WIRE_3, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_4);
    gpio_set_direction(CTW_WIRE_4, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_5);
    gpio_set_direction(CTW_WIRE_5, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_6);
    gpio_set_direction(CTW_WIRE_6, GPIO_MODE_INPUT);
}

bool test_ctw(CutTheWireModule cutTheWireModule) {
    if(
        (gpio_get_level(CTW_WIRE_1) == std::bitset<8>(cutTheWireModule.currentSolution)[0]) &&
        (gpio_get_level(CTW_WIRE_2) == std::bitset<8>(cutTheWireModule.currentSolution)[1]) &&
        (gpio_get_level(CTW_WIRE_3) == std::bitset<8>(cutTheWireModule.currentSolution)[2]) //&&
        //(gpio_get_level(CTW_WIRE_4) == std::bitset<8>(cutTheWireModule.currentSolution)[3]) &&
        //(gpio_get_level(CTW_WIRE_5) == std::bitset<8>(cutTheWireModule.currentSolution)[4]) &&
        //(gpio_get_level(CTW_WIRE_6) == std::bitset<8>(cutTheWireModule.currentSolution)[5])
    ){
        return true;
    } else return false;
}

extern "C" void app_main() {
    CutTheWireModule cutTheWireModule((int)rand());
    GPIOHandler gpioHandler;
    
    std::string solutionString = std::bitset<8>(cutTheWireModule.currentSolution).to_string();
    ESP_LOGI("Cut the Wire", "Module Initialized\nSolution:%s", solutionString.c_str());

    setup_ctw();
    ESP_LOGI("Cut the Wire", "CTW Pins set up");

    while(1){
        if(test_ctw(cutTheWireModule)){
            ESP_LOGI("Cut the Wire", "Module defused");
            break;
        }
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}