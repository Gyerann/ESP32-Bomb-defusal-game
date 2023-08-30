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

extern "C" void app_main() {
    CutTheWireModule cutTheWireModule(1);
    std::string solutionString = std::bitset<8>(cutTheWireModule.currentSolution).to_string();
    ESP_LOGI("Cut the Wire", "Module Initialized\nSolution:%s", solutionString.c_str());

    
}