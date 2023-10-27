#include "module.h"

#pragma once

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