#include <random>
#include "../config.h"
#include "esp_log.h"

class KeypadHandler{
    public:
    KeypadHandler();
};

class KeypadSolution{
    public:
    KeypadSolution();
    void generate_solution(uint8_t seed);
};

class Keypad{
    public:
    Keypad(uint8_t seed);
    void setup_module();
    void setup_gpio();
    void check_module();
    void solve_module();
    void get_state();
};