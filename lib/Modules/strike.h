#include "module.h"

#pragma once

//Available strikes defaults to 3
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
        esp_rom_gpio_pad_select_gpio(STRIKE_LED_1);
        gpio_set_direction(STRIKE_LED_1, GPIO_MODE_OUTPUT);

        esp_rom_gpio_pad_select_gpio(STRIKE_LED_2);
        gpio_set_direction(STRIKE_LED_2, GPIO_MODE_OUTPUT);

        esp_rom_gpio_pad_select_gpio(STRIKE_LED_3);
        gpio_set_direction(STRIKE_LED_3, GPIO_MODE_OUTPUT);
    }

    void add_strike(){
        this->_currentStrikes++;
    }

    bool check_strikes_remaining(){
        return this->_currentStrikes != this->_strikes;
    }

    void boom(){
        this->_currentStrikes = this->_strikes;
        ESP_LOGI(this->_tag, "BOOM!!!");
    }

    private:
    uint8_t _strikes{3};
    uint8_t _currentStrikes{0};
}