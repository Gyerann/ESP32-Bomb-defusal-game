#include <random>
#include <esp_log.h>
#include "../config.h"

#pragma once

class Module {
    public:
    Module(){
        ESP_LOGI(this->_tag, "Module grandparent constructor called.");
        this->_isActive = true;
    }
    
    void log_config(){
        ESP_LOGI(this->_tag, "log_config called in empty object. Override this function.");
    }

    ~Module(){
        ESP_LOGI(this->_tag, "Module destroyed.");
        this->_isActive = false;
    }

    bool check_is_active(){
        return this->_isActive;
    }

    //Override this function
    uint8_t check_state(){
        return this->_state;
    }

    protected:
    //Override this function
    void setup_gpio(){
        ESP_LOGI(this->_tag, "Setup gpio called.");
    }

    char* _tag = "Empty module";
    bool _isSetUp{false};
    char _state{};
    bool _isActive{false};
};