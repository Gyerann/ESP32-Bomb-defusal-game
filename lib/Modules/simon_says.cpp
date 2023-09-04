#include "simon_says.h"

//SimonSaysHandler
SimonSaysHandler::SimonSaysHandler(){

}

//SimonSaysSeries
SimonSaysSeries::SimonSaysSeries(){

}

void SimonSaysSeries::generate_series(uint8_t seed, uint8_t* outSeries){
    uint8_t seriesLength = 3 + srand(seed % 4);
    for (uint8_t i = 0; i < (seriesLength - 1); i++){
        outSeries[i] = (srand(seed) % 4);
    }
}

//SimonSaysModule
SimonSaysModule::SimonSaysModule(uint8_t seed){
    SimonSaysSeries simonSaysSeries;
    simonSaysSeries.generate_series(currentSeries);
}

void SimonSaysModule::setup_gpio(){

}

void SimonSaysModule::setup_module(){

}

void SimonSaysModule::continue_series(){
    
}

void SimonSaysModule::solve_module(){
    
}

void SimonSaysModule::restart_series(){
    
}