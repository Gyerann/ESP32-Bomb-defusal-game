#include "app_main.h"
#include "modules.h"

#pragma once

//void test_display(){
//    SSD1306_t display;
//    int center, top, bottom;
//    char lineChar[20];
//	top = 2;
//	center = 3;
//	bottom = 8;
//
//	i2c_master_init(&display, DISPLAY_SDA_PIN, DISPLAY_SCL_PIN, DISPLAY_RESET_PIN);
//	ssd1306_init(&display, 128, 64);
//
//	ssd1306_display_text(&display, 0, "SSD1306 128x64", 14, false);
//	ssd1306_display_text(&display, 1, "ABCDEFGHIJKLMNOP", 16, false);
//	ssd1306_display_text(&display, 2, "abcdefghijklmnop",16, false);
//	ssd1306_display_text(&display, 3, "Hello World!!", 13, false);
//}
//
//void network_init(){ 
//	connect_wifi();
//    setup_server();
//}
//
//esp_err_t memory_init(){
//    esp_err_t ret = nvs_flash_init();
//    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
//    {
//        ESP_ERROR_CHECK(nvs_flash_erase());
//        ret = nvs_flash_init();
//    }
//    ESP_ERROR_CHECK(ret);
//    
//    return ret;
//}

extern "C" void app_main() {

	//esp_err_t ret = memory_init();

    //uint8_t ctwSeed = rand();
    //CutTheWireModule cutTheWireModule(ctwSeed);
    //GPIOHandler gpioHandler;

    //test_display();
	//network_init();

    CutTheWire testModule(ctwSeed);
}