#include "driver/gpio.h"
#include "esp_log.h"

#pragma once

//Module tags
#define CTW_TAG     "Cut the Wire"
#define PLAYER_TAG  "Player"

//Server macros
#define WIFI_SSID   "******"
#define WIFI_PASS   "******"
#define WIFI_MAX_RETRY      5
#define WIFI_CONNECTED_BIT  BIT0
#define WIFI_FAIL_BIT       BIT1

//Cut the Wire options
#define CTW_WIRE_1  GPIO_NUM_5
#define CTW_WIRE_2  GPIO_NUM_17
#define CTW_WIRE_3  GPIO_NUM_16
#define CTW_WIRE_4  GPIO_NUM_4
#define CTW_WIRE_5  GPIO_NUM_34
#define CTW_WIRE_6  GPIO_NUM_35

//PlayerModule options
#define SOUND_ON        true  
#define TIMER_START     90
#define SPEAKER_PIN     GPIO_NUM_32
#define TIMER_PIN_CLK   GPIO_NUM_14
#define TIMER_PIN_DIO   GPIO_NUM_27
#define STRIKE_LED_1    GPIO_NUM_26
#define STRIKE_LED_2    GPIO_NUM_25
#define STRIKE_LED_3    GPIO_NUM_33

//OLED Display options
#define DISPLAY_SDA_PIN     GPIO_NUM_22
#define DISPLAY_SCL_PIN     GPIO_NUM_21
#define DISPLAY_RESET_PIN   GPIO_NUM_26

//This might be unecessary

class ConfigHandler{
public:
    
    ConfigHandler(){
        ESP_LOGI(this->_tag, "ConfigHandler constructed.");
    }

    ~ConfigHandler(){
        ESP_LOGI(this->_tag, "ConfigHandler destructed.");
    }

    void log_config(){
        
        //CTW config
        ESP_LOGI(this->_tag, "%s config:", CTW_TAG);
        ESP_LOGI(this->_tag, "%i Wire 1 pin: ", CTW_WIRE_1);
        ESP_LOGI(this->_tag, "%i Wire 2 pin: ", CTW_WIRE_2);
        ESP_LOGI(this->_tag, "%i Wire 3 pin: ", CTW_WIRE_3);
        ESP_LOGI(this->_tag, "%i Wire 4 pin: ", CTW_WIRE_4);
        ESP_LOGI(this->_tag, "%i Wire 5 pin: ", CTW_WIRE_5);
        ESP_LOGI(this->_tag, "%i Wire 6 pin: ", CTW_WIRE_6);
    
    }

private:
    char* _tag = "ConfigHandler";
};