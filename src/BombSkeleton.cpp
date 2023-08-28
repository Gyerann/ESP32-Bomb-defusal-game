//Handler for player reladet stuff
class PlayerHandler{

    public:
    void InitPlayerHandler(){
        /*
        .
        .
        .
        */
    }
};

//Handler for networking
class NetworkHandler{

    public:
    void InitNetworkHandler(){
        /*
        ESP32 REST API setup
        */
    }
};

class Module{
    //Default module stuff, child class defines behavior
    /*
    .
    .
    .
    */
};

//Handler for bomb modules
class ModuleHandler{

    public:
    void DiscoverModules(){
        //How to do this? Challenge response if module has a microcontroller
        /*
        .
        .
        .
        */
    }

    void InitModuleHandler(){
        DiscoverModules();
    }
};

//Handler for scheduled jobs e.g: timer
class ScheduledHandler{
    
    public:
    void InitScheduledHandler(){

    }
};

class BombConfig{

    public:

    char strikes = 3;
    char time = 90;
    char difficulty = 1;

    void InitBombConfig(){

    }
};

void InitBomb(PlayerHandler* playerHandler, NetworkHandler* networkHandler, ModuleHandler* moduleHandler, ScheduledHandler* scheduledHandler, BombConfig* bombConfig){
    bombConfig->InitBombConfig();
    playerHandler->InitPlayerHandler();
    networkHandler->InitNetworkHandler();
    moduleHandler->InitModuleHandler();
    scheduledHandler->InitScheduledHandler();
}

int main() {
    BombConfig bombConfig;
    PlayerHandler playerHandler;
    NetworkHandler networkHandler;
    ModuleHandler moduleHandler;
    ScheduledHandler scheduledHandler;

    InitBomb(&playerHandler, &networkHandler, &moduleHandler, &scheduledHandler, &bombConfig);

    return 0;
}