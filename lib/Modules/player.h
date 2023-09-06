#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../Hardware/tm1637.h"
#include "../config.h"

class PlayerModuleHandler{};

class PlayerModule{
    public:
    PlayerModule();
    void boom();
    void setup_gpio();
};

class TimerModule{
    public: 
    uint16_t timeRemaining{TIMER_START};
    TimerModule();
    void beep();
    void update_timer();
};

class StrikeModule{
    public:
    uint8_t currentStrikes{0};
    StrikeModule();
    void add_strike(PlayerModule playerModule);
};