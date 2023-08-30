#include "cut_the_wire.h"

//CutTheWireSolution
CutTheWireSolution::CutTheWireSolution(int seed){
    currentSolution = generate_solution(seed);
}

char CutTheWireSolution::generate_solution(int seed){
    srand(seed);
    char generatedSolution = rand() % 255;
    return generatedSolution; 
}

//CutTheWireHandler
CutTheWireHandler::CutTheWireHandler(){}

//CutTheWireModule
CutTheWireModule::CutTheWireModule(int seed){
    CutTheWireSolution moduleSolution(seed);
    currentSolution = moduleSolution.currentSolution;
    setup_module(moduleSolution.currentSolution);
}

void CutTheWireModule::setup_module(char currentSolution){
}

void CutTheWireModule::solve_module(){}