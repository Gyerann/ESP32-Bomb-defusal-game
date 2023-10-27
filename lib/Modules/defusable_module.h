#include "module.h"

#pragma once

class DefusableModule : protected Module{
    public:
    DefusableModule(){
        ESP_LOGI(this->_tag, "Defusable parent constructor called.");
        this->_tag = "Empty defusable module";
        this->_s_activeDefusables++;
    }
    
    protected:
    ~DefusableModule(){
        ESP_LOGI(this->_tag, "Defusable module destroyed.");
    }

    bool check_module_isSolved(){
        ESP_LOGI(this->_tag, "Check module called.");
        return this->_state == this->_solution;
    }

    void solve_module(){
        ESP_LOGI(this->_tag, "Module solved.");
        this->_isSolved = true;
        this->_s_activeDefusables--;
    }
    
    bool _isSolved{0};
    uint8_t _solution{0};
    static uint8_t _s_activeDefusables{0};
}