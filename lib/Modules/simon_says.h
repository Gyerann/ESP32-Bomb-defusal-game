#include <random>
#include "../config.h"
#include "esp_log.h"

class SimonSaysHandler{
    public:
    SimonSaysHandler();
};

class SimonSaysSeries{
    public:
    SimonSaysSolution();
    generate_series(int seed);
};

class SimonSaysModule{
    public:
    int currentSeries;
    SimonSays(int seed);
    void setup_module();
    void setup_gpio();
    void continue_series();
    void solve_module();
    void restart_series();
};