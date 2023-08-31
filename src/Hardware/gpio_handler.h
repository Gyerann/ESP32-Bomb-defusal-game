#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "config.h"
#include "stdio.h"

class GPIOHandler{
    public:
    const char* Tag = "GPIOHandler";
    GPIOHandler();
    void init_module_pins();
};