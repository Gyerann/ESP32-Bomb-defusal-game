#include <random>
#include "../config.h"
#include "esp_log.h"

class SimonSaysHandler{
    public:
    SimonSaysHandler();
};

class SimonSaysSeries{
    public:
    SimonSaysSeries();
    int generate_series(int seed);
};

class SimonSaysModule{
    public:
    int currentSeries;
    SimonSaysModule(int seed);
    void setup_module();
    void setup_gpio();
    void continue_series();
    void solve_module();
    void restart_series();
};