#include <random>
#include "../config.h"
#include "esp_log.h"
#include <stdio>

class SimonSaysHandler{
    public:
    SimonSaysHandler();
};

class SimonSaysSeries{
    public:
    uint8_t* outSeries;
    SimonSaysSeries();
    void generate_series(uint8_t seed, uint8_t* outSeries);
};

class SimonSaysModule{
    public:
    uint8_t* currentSeries[7] = {0};
    SimonSaysModule(uint8_t seed);
    void setup_module();
    void setup_gpio();
    void continue_series();
    void solve_module();
    void restart_series();
};