#include "app_main.h"
#include "modules.h"

esp_err_t memory_init(){
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    
    return ret;
}

extern "C" void app_main() {

	esp_err_t ret = memory_init();

    //uint8_t ctwSeed = rand();
    //CutTheWireModule cutTheWireModule(ctwSeed);
    //GPIOHandler gpioHandler;
}