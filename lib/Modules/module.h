#include <random>
#include <esp_log.h>
#include "../config.h"
#include "vector"

#pragma once

class Module {
    public:
    Module(){
        ESP_LOGI(this->_tag, "Module grandparent constructor called.");
        this->_s_activeModules++;
    }
    
    protected:
    ~Module(){
        ESP_LOGI(this->_tag, "Module destroyed.");
    }

    //Override this function
    void setup_gpio(){
        ESP_LOGI(this->_tag, "Setup gpio called.");
    }
    
    //Override this function
    uint8_t check_state(){
        return this->_state;
    }

    char* _tag = "Empty module";
    bool _isSetUp{false};
    char _state{0};
    static uint8_t _s_activeModules{0};
};

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

class KeyPad : protected DefusableModule{
    public:
    KeyPad(){
        this->_tag = "Keypad";
        ESP_LOGI(this->_tag, "Constructing module without seed...");
        this->_isSetUp = true;
        this->_solution = rand() % 256;
        setup_gpio();
        ESP_LOGI(this->_tag, "Module constructed successfully. Solution: %i", this->_solution);
    }

    KeyPad(uint8_t seed){
        this->_tag = "Keypad";
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
}

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
}

//Time in seconds, defaults to 120
class TimerModule : protected Module{
    public:
    TimerModule(){
        this->_tag = "Timer module";
        ESP_LOGI(this->_tag, "Constructing default timer module...");
        this->_isSetUp = true;
        setup_gpio();
        ESP_LOGI(this->_tag, "Default timer module constructed successfully, %is.", this->_time);
    }

    TimerModule(uint32_t time){
        this->_tag = "Timer module";
        ESP_LOGI(this->_tag, "Constructing custom timer module...");
        this->_time = time;
        this->_isSetUp = true;
        setup_gpio();
        ESP_LOGI(this->_tag, "Custom timer module constructed successfully, %is.", this->_time);
    }

    protected:
    void setup_gpio(){
        //Time display setup
    }

    bool is_time_over(){
        //Will return false if underflows, implement check
        return this->_time == 0;
    }

    private:
    uint32_t _time{120};
}

class StrikeModule : protected Module{
    public:
    StrikeModule(){
        this->_tag = "Strike module";
        ESP_LOGI(this->_tag, "Constructing default strike module...");
        this->_isSetUp = true;
        setup_gpio();
        ESP_LOGI(this->_tag, "Default strike module constructed successfully, 0/%i.", this->_strikes);
    }

    StrikeModule(uint8_t strikes){
        this->_tag = "Strike module";
        ESP_LOGI(this->_tag, "Constructing custom strike module...");
        this->_strikes = strike;
        this->_isSetUp = true;
        setup_gpio();
        ESP_LOGI(this->_tag, "Custom strike module constructed successfully, 0/%i.", this->_strikes);
    }

    protected:
    void setup_gpio(){
        //Implement gpio setup
    }

    void add_strike(){
        this->_currentStrikes++;
    }

    bool check_strikes_remaining(){
        return this->_currentStrikes != this->_strikes;
    }

    private:
    uint8_t _strikes{3};
    uint8_t _currentStrikes{0};
}

