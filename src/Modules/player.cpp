#include "player.h"

//PlayerModule
PlayerModule::PlayerModule(){
    TimerModule timerModule;
    StrikeModule strikeModule;
    setup_gpio();
}

PlayerModule::setup_gpio(){
    {esp_rom_gpio_pad_select_gpio(SPEAKER_PIN);
    gpio_set_direction(SPEAKER_PIN, GPIO_MODE_OUTPUT);

    esp_rom_gpio_pad_select_gpio(STRIKE_LED_1);
    gpio_set_direction(STRIKE_LED_1, GPIO_MODE_OUTPUT);

    esp_rom_gpio_pad_select_gpio(STRIKE_LED_2);
    gpio_set_direction(STRIKE_LED_2, GPIO_MODE_OUTPUT);

    esp_rom_gpio_pad_select_gpio(STRIKE_LED_3);
    gpio_set_direction(STRIKE_LED_3, GPIO_MODE_OUTPUT);
    }
    ESP_LOGI(PLAYER_TAG, "GPIO set up");
}

PlayerModule::boom(){
    ESP_LOGI(PLAYER_TAG, "BOOM!!!");
}

//TimerModule
TimerModule::TimerModule(){
    //setup_pins();
}

TimerModule::beep(){
    gpio_set_level(SPEAKER_PIN, 1);
    vTaskDelay(125/portTICK_PERIOD_MS);
}

TimerModule::update_timer(){
    //implement tm1637 timer update
}

//StrikeModule
StrikeModule::StrikeModule(){
    //setup_pins();
}

StrikeModule::add_strike(PlayerModule playerModule){
    currentStrikes++;
    switch (currentStrikes)
    {
    case 1:
        gpio_set_level(STRIKE_LED_1, 1);
        ESP_LOGI(PLAYER_TAG, "Strike %d/3", currentStrikes);
        break;
    case 2:
        gpio_set_level(STRIKE_LED_1, 1);
        gpio_set_level(STRIKE_LED_2, 1);
        ESP_LOGI(PLAYER_TAG, "Strike %d/3", currentStrikes);
        break;
    case 3:
        gpio_set_level(STRIKE_LED_1, 1);
        gpio_set_level(STRIKE_LED_2, 1);
        gpio_set_level(STRIKE_LED_3, 1);
        ESP_LOGI(PLAYER_TAG, "Strike %d/3", currentStrikes);
        playerModule.boom();
        break;
    }
}