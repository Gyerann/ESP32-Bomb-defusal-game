#include "module.h"
#include "defusable_module.h"

#pragma once

class CutTheWire : protected DefusableModule{
    public:
    CutTheWire(){
        this->_tag = "Cut the Wire";
        ESP_LOGI(this->_tag, "Constructing module without seed...");
        this->_isSetUp = true;
        this->_solution = rand() % 256;
        setup_gpio();
        ESP_LOGI(this->_tag, "Module constructed successfully. Solution: %i", this->_solution);
    }

    CutTheWire(uint8_t seed){
        this->_tag = "Cut the Wire";
        ESP_LOGI(this->_tag, "Constructing module with seed %i...", seed);
        srand(seed);
        this->_solution = rand() % 256;
        this->_isSetUp = true;
        setup_gpio();
        ESP_LOGI(this->_tag, "Module constructed successfully. Solution: %i", this->_solution);
        }
    
    void log_config(){
        ESP_LOGI(this->_tag, "%s config:", this->_tag);
        ESP_LOGI(this->_tag, "Wire 1 pin: %i", CTW_WIRE_1);
        ESP_LOGI(this->_tag, "Wire 2 pin: %i", CTW_WIRE_2);
        ESP_LOGI(this->_tag, "Wire 3 pin: %i", CTW_WIRE_3);
        ESP_LOGI(this->_tag, "Wire 4 pin: %i", CTW_WIRE_4);
        ESP_LOGI(this->_tag, "Wire 5 pin: %i", CTW_WIRE_5);
        ESP_LOGI(this->_tag, "Wire 6 pin: %i", CTW_WIRE_6);
        ESP_LOGI(this->_tag, "Solution: %i", this->_solution);
    }

    protected:
    void setup_gpio(){
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

        ESP_LOGI(this->_tag, "GPIOs set up.");
    }
};