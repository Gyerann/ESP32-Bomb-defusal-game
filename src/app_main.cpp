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

    MPU6050 mpu(GPIO_NUM_19, GPIO_NUM_22, I2C_NUM_0);

    if(!mpu.init()) {
	    ESP_LOGE("mpu6050", "init failed!");
        vTaskDelete(0);
    }
	ESP_LOGI("mpu6050", "init success!");

    float ax,ay,az,gx,gy,gz;
    float pitch, roll;
    float fpitch, froll;

    KALMAN pfilter(0.005);
    KALMAN rfilter(0.005);

    uint32_t lasttime = 0;
    int count = 0;

    while(1) {
        ax = -mpu.getAccX();
        ay = -mpu.getAccY();
        az = -mpu.getAccZ();
        gx = mpu.getGyroX();
        gy = mpu.getGyroY();
        gz = mpu.getGyroZ();
        pitch = atan(ax/az)*57.2958;
        roll = atan(ay/az)*57.2958;
        fpitch = pfilter.filter(pitch, gy);
        froll = rfilter.filter(roll, -gx);
        count++;
        if(esp_log_timestamp() / 1000 != lasttime) {
            lasttime = esp_log_timestamp() / 1000;
            ESP_LOGI("mpu6050", "Samples: %d", count);
            count = 0;
            ESP_LOGI("mpu6050", "Acc: ( %.3f, %.3f, %.3f)", ax, ay, az);
            ESP_LOGI("mpu6050", "Gyro: ( %.3f, %.3f, %.3f)", gx, gy, gz);
            ESP_LOGI("mpu6050", "Pitch: %.3f", pitch);
            ESP_LOGI("mpu6050", "Roll: %.3f", roll);
            ESP_LOGI("mpu6050", "FPitch: %.3f", fpitch);
            ESP_LOGI("mpu6050", "FRoll: %.3f", froll);
        }
    }
}