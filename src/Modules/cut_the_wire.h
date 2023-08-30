/*
Cut the Wire module description:

Hardware:
6 Wires with different colors
3v + 1K Ohms in, 3 + 3 parallel connection
1. O----O Purple ----(LED) ---- GPIO
2. O----O White  ----(LED) ---- GPIO
3. O----O Yellow ----(LED) ---- GPIO
4. O----O Orange ----(LED) ---- GPIO
5. O----O Green  ----(LED) ---- GPIO
6. O----O Blue   ----(LED) ---- GPIO

Gameplay:
A char is randomly generated
0   -> wire gets cut
1   -> wire doesnt get cut
The module is solved if each required wire gets cut
*/

#include <random>

class CutTheWireSolution{
    public:
    CutTheWireSolution(int seed);
    char currentSolution;
    char generate_solution(int seed);
};

class CutTheWireHandler{
    private:
    CutTheWireHandler();
};

class CutTheWireModule{
    public:
    char currentSolution;
    CutTheWireModule(int seed);
    void setup_module(char currentSolution);
    void solve_module();
};