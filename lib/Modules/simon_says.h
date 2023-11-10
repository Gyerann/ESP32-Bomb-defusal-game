#include "module.h"
#include "defusable_module.h"

#pragma once

class SimonSays : protected DefusableModule{
    public:
    SimonSays(){
        this->_tag = "Simon Says";
        ESP_LOGI(this->_tag, "Constructing module without seed...");
        this->_isSetUp = true;
        this->_solution = rand() % 256;
        setup_gpio();
        ESP_LOGI(this->_tag, "Module constructed successfully. Solution: %i", this->_solution);
    }

    SimonSays(uint8_t seed){
        this->_tag = "Simon Says";
        ESP_LOGI(this->_tag, "Constructing module with seed %i...", seed);
        srand(seed);
        this->_solution = rand() % 256;
        this->_isSetUp = true;
        setup_gpio();
        ESP_LOGI(this->_tag, "Module constructed successfully. Solution: %i", this->_solution);
        }
    
    protected:
    void setup_gpio(){
        //Override parent function with actual setup
    }
};