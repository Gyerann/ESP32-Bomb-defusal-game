#include "cut_the_wire.h"

//CutTheWireSolution
CutTheWireSolution::CutTheWireSolution(int seed){
    currentSolution = generate_solution(seed);
}

char CutTheWireSolution::generate_solution(int seed){
    //srand(seed);
    char generatedSolution = seed % 255;
    return generatedSolution; 
}

//CutTheWireHandler
CutTheWireHandler::CutTheWireHandler(){}

//CutTheWireModule
CutTheWireModule::CutTheWireModule(int seed){
    ESP_LOGI(CTW_TAG, "Module discovered");
    CutTheWireSolution moduleSolution(seed);
    currentSolution = moduleSolution.currentSolution;
    setup_module(moduleSolution.currentSolution);
    ESP_LOGI(CTW_TAG, "Seed: %i Solution:%s", seed, 
        std::bitset<8>(this->currentSolution).to_string().c_str());
}

void CutTheWireModule::setup_gpio(){
    {esp_rom_gpio_pad_select_gpio(CTW_WIRE_1);
    gpio_set_direction(CTW_WIRE_1, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_2);
    gpio_set_direction(CTW_WIRE_2, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_3);
    gpio_set_direction(CTW_WIRE_3, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_4);
    gpio_set_direction(CTW_WIRE_4, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_5);
    gpio_set_direction(CTW_WIRE_5, GPIO_MODE_INPUT);

    esp_rom_gpio_pad_select_gpio(CTW_WIRE_6);
    gpio_set_direction(CTW_WIRE_6, GPIO_MODE_INPUT);
    }
    ESP_LOGI(CTW_TAG, "GPIO set up");
}

void CutTheWireModule::setup_module(char currentSolution){
    setup_gpio();
}

void CutTheWireModule::solve_module(){}

std::bitset<6> CutTheWireModule::get_state(){
    std::bitset<6> moduleState;
    moduleState[0] = gpio_get_level(CTW_WIRE_1);
    moduleState[1] = gpio_get_level(CTW_WIRE_2);
    moduleState[2] = gpio_get_level(CTW_WIRE_3);
    moduleState[3] = gpio_get_level(CTW_WIRE_4);
    moduleState[4] = gpio_get_level(CTW_WIRE_5);
    moduleState[5] = gpio_get_level(CTW_WIRE_6);

    std::string stateString = moduleState.to_string();
    ESP_LOGI(CTW_TAG, "State: %s", stateString.c_str());

    return moduleState;
}

bool CutTheWireModule::check_module(){
    get_state();
    if(
        (gpio_get_level(CTW_WIRE_1) == std::bitset<8>(this->currentSolution)[0]) &&
        (gpio_get_level(CTW_WIRE_2) == std::bitset<8>(this->currentSolution)[1]) &&
        (gpio_get_level(CTW_WIRE_3) == std::bitset<8>(this->currentSolution)[2]) &&
        (gpio_get_level(CTW_WIRE_4) == std::bitset<8>(this->currentSolution)[3]) &&
        (gpio_get_level(CTW_WIRE_5) == std::bitset<8>(this->currentSolution)[4]) &&
        (gpio_get_level(CTW_WIRE_6) == std::bitset<8>(this->currentSolution)[5])
    ){
        ESP_LOGI(CTW_TAG, "Module defused");
        return true;
    } else return false;
}