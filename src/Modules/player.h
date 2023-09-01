#include "config.h"
#include "freertos/task.h"
#include "tm1637.h"

class PlayerModuleHandler{};

class PlayerModule{
    public:
    PlayerModule();
    void boom();
    void setup_gpio();
};

class TimerModule{
    public: 
    int timeRemaining{TIMER_START};
    TimerModule();
    void beep();
    void update_timer();
};

class StrikeModule{
    public:
    char currentStrikes{0};
    StrikeModule();
    void add_strike(PlayerModule playerModule);
}