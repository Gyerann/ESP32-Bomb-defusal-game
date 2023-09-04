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
    generate_solution(int seed);
};

class Keypad{
    public:
    Keypad(int seed);
    void setup_module();
    void setup_gpio();
    void check_module();
    void solve_module();
    void get_state();
};