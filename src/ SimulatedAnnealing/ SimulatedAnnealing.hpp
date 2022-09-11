#include <math.h>
#include <vector>
#include <iostream>

#ifndef SIMULATED_ANNEALING_HPP
#define SIMULATED_ANNEALING_HPP

class  SimulatedAnnealing{
    public:
        SimulatedAnnealing(int NumVar, int NumIt, double InitialTemperature,
                    double CoolingRate, double RandomParam,
                    long double minValue, long double maxValue,
                    long double (*EvaluationFunc)(std::vector<long double>));
        void showBestSolution();
        void run();
    
    private:
        int numVar, numIt; 
        double temperature, coolingRate, randomParam;
        long double minValue, maxValue;
        std::vector<long double> solution;
        long double (*evaluationFunc)(std::vector<long double>);

        long double checkNewValue(long double newValue);
        bool changeSolution(std::vector<long double> solution, std::vector<long double> solutionNeighbor);
        long double uniformRandomNum(long double MinValue, long double MaxValue);
        std::vector<long double> uniformVectorRandomNum(int size);

};
#endif