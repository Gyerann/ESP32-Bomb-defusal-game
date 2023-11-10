void test_display(){
    SSD1306_t display;
    int center, top, bottom;
    char lineChar[20];
	top = 2;
	center = 3;
	bottom = 8;

	i2c_master_init(&display, DISPLAY_SDA_PIN, DISPLAY_SCL_PIN, DISPLAY_RESET_PIN);
	ssd1306_init(&display, 128, 64);

	ssd1306_display_text(&display, 0, "SSD1306 128x64", 14, false);
	ssd1306_display_text(&display, 1, "ABCDEFGHIJKLMNOP", 16, false);
	ssd1306_display_text(&display, 2, "abcdefghijklmnop",16, false);
	ssd1306_display_text(&display, 3, "Hello World!!", 13, false);
}