#include "module.h"

#pragma once


class DefusableModule : protected Module{
    public:
    DefusableModule(){
        ESP_LOGI(this->_tag, "Defusable parent constructor called.");
        this->_tag = "Empty defusable module";
    }
    
    ~DefusableModule(){
        ESP_LOGI(this->_tag, "Defusable module destroyed.");
    }

    bool check_module_is_solved(){
        return this->_isSolved;
    }

    void solve_module(){
        ESP_LOGI(this->_tag, "Module solved.");
        this->_isSolved = true;
    }

    uint8_t get_solution(){
        return this->_solution;
    }

    protected:
    
    bool _isSolved{false};
    uint8_t _solution{0};
};