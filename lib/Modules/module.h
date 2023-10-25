#include <random>
#include <esp_log.h>
#include "../config.h"
#include "vector"

#pragma once

class Module {
    public:
    Module(){
        ESP_LOGI(this->_tag, "Module parent constructor called.");
    }
    
    protected:
    ~Module(){
        ESP_LOGI(this->_tag, "Module destroyed.");
    }

    void setup_gpio(){
        ESP_LOGI(this->_tag, "Setup gpio called.");
    }

    bool check_module(){
        ESP_LOGI(this->_tag, "Check module called.");
        this->_state = 0;
        return this->_state == this->_solution;
    }

    void solve_module(){
        ESP_LOGI(this->_tag, "Module solved.");
        this->_isSolved = true;
    }

    char* _tag = "Empty module";
    bool _isSolved{0};
    bool _isSetUp{false};
    char _solution{0};
    char _state{0};
};

class CutTheWire : protected Module{
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

    bool check_module(){
        ESP_LOGI(this->_tag, "Check module called.");
        this->_state = 0;
        return this->_state == this->_solution;
    }
};