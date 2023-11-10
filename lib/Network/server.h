#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <esp_http_server.h>
#include "esp_wifi.h"
#include "esp_event.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "driver/gpio.h"
#include <lwip/sockets.h>
#include <lwip/sys.h>
#include <lwip/api.h>
#include <lwip/netdb.h>
#include <config.h>
#pragma once

//This is supposed to be a singleton

#define WIFI_SSID   "******"
#define WIFI_PASS   "******"
#define WIFI_MAX_RETRY      5
#define WIFI_CONNECTED_BIT  BIT0
#define WIFI_FAIL_BIT       BIT1

class Server {
public:
    Server(){
        this->_retry_num = WIFI_MAX_RETRY;
        connect_wifi();
        setup_server();
        update_webpage();
    }

    ~Server(){
        ESP_LOGI(this->_tag, "Server destructed.");
    }

protected:

    void connect_wifi(){
        ESP_LOGI(this->_tag, "connect_wifi called.");
    }

    httpd_handle_t setup_server(){
        httpd_config_t config = HTTPD_DEFAULT_CONFIG();
        httpd_handle_t server = NULL;

        if (httpd_start(&server, &config) == ESP_OK)
        {
            httpd_register_uri_handler(server, &this->_uriHandler);
        }

        ESP_LOGI(this->_tag, "setup_server called.");
        
        return server;
    }

    void send_state(){
        ESP_LOGI(this->_tag, "send_state called.");
    }

    void update_webpage(){
        ESP_LOGI(this->_tag, "update_webpage called.");
    }

    char* _tag = "Server";
    uint8_t _retry_num{};
    EventGroupHandle_t _wifi_event_group;
    httpd_uri_t _uriHandler;
};

//---------------------------------------------

class APIHandler{
public:
    APIHandler(){
        ESP_LOGI(this->_tag, "API Handler constructed.");
    }

    ~APIHandler(){
        ESP_LOGI(this->_tag, "API Handler destructed.");
    }
    
protected:
    char* _tag = "API Handler";
};