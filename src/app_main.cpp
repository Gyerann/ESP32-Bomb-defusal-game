#include "app_main.h"

//Remove this function later
void test_display(){
    SSD1306_t display;
    int center, top, bottom;
    char lineChar[20];
    char* tag = "OLED Test";

    ESP_LOGI(tag, "INTERFACE is i2c");
	ESP_LOGI(tag, "CONFIG_SDA_GPIO=%d",DISPLAY_SDA_PIN);
	ESP_LOGI(tag, "CONFIG_SCL_GPIO=%d",DISPLAY_SCL_PIN);
	ESP_LOGI(tag, "CONFIG_RESET_GPIO=%d",DISPLAY_RESET_PIN);
	i2c_master_init(&display, DISPLAY_SDA_PIN, DISPLAY_SCL_PIN, DISPLAY_RESET_PIN);

    ESP_LOGI(tag, "Panel is 128x64");
	ssd1306_init(&display, 128, 64);

    top = 2;
	center = 3;
	bottom = 8;
	ssd1306_display_text(&display, 0, "SSD1306 128x64", 14, false);
	ssd1306_display_text(&display, 1, "ABCDEFGHIJKLMNOP", 16, false);
	ssd1306_display_text(&display, 2, "abcdefghijklmnop",16, false);
	ssd1306_display_text(&display, 3, "Hello World!!", 13, false);
	ssd1306_clear_line(&display, 4, true);
	ssd1306_clear_line(&display, 5, true);
	ssd1306_clear_line(&display, 6, true);
	ssd1306_clear_line(&display, 7, true);
	ssd1306_display_text(&display, 4, "SSD1306 128x64", 14, true);
	ssd1306_display_text(&display, 5, "ABCDEFGHIJKLMNOP", 16, true);
	ssd1306_display_text(&display, 6, "abcdefghijklmnop",16, true);
	ssd1306_display_text(&display, 7, "Hello World!!", 13, true);
}

extern "C" void app_main() {
    uint8_t ctwSeed = rand();
    CutTheWireModule cutTheWireModule(ctwSeed);
    GPIOHandler gpioHandler;

    test_display();

    //For testing
    while(1){
        cutTheWireModule.get_state();
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}