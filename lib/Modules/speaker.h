#include "module.h"

#pragma once

class Speaker : protected Module{
    public:
    Speaker(){
        this->_tag = "Speaker module";
        ESP_LOGI(this->_tag, "Constructing speaker module...");
        this->_isSetUp = true;
        setup_gpio();
        ESP_LOGI(this->_tag, "Speaker module constructed.");
    }

    protected:
    void setup_gpio(){
        esp_rom_gpio_pad_select_gpio(SPEAKER_PIN);
        gpio_set_direction(SPEAKER_PIN, GPIO_MODE_OUTPUT);
    }

    void beep(){
        gpio_set_level(SPEAKER_PIN, 1);
        vTaskDelay(125/portTICK_PERIOD_MS);
    }
}