class CutTheWireHandler{
    
    public:

    CutTheWireModule init_cut_the_wire(int seed = 0, char wireAmount = 6){
        CutTheWireModule cutTheWireModule;
        cutTheWireModule.setup_module(seed, wireAmount);
    }
};

class CutTheWireModule{

    private:
    bool wireSolutions[6];

    //Todo: Develop algo to generate a solution based on a seed
    //True -> cut wire
    void init_solution_array(bool (&wireSolutions)[], char wireAmount){
        wireSolutions[1] = {false};
        wireSolutions[2] = {true};
        wireSolutions[3] = {true};
        wireSolutions[4] = {false};
        wireSolutions[5] = {false};
        wireSolutions[6] = {false};
    }

    void attach_module(bool (&wireSolutions)[], char wireAmount){
        //LOG($"Cut the Wire module attached with {wireAmount} wires. +
        //Solution: {wireSolutions.List}");
    }

    //0 - module detached due to error
    //1 - module detached after correct solution
    //define macros maybe
    void detach_module(char detachReason){
        //LOG($"Cut the Wire module detached with code {detachReason}");
    }

    public:  

    void setup_module(int seed = 0, char wireAmount){
        init_solution_array(wireSolutions, wireAmount);
        attach_module(wireSolutions, wireAmount);
        //Add a listener for user interactions, architecture has to be tought out
    }

    void solve_module(){
        detach_module(1);
    }
};