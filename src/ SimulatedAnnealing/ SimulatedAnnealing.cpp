#include " SimulatedAnnealing.hpp"

SimulatedAnnealing::SimulatedAnnealing(int NumVar, int NumIt, 
                    double InitialTemperature, double CoolingRate,
                    double RandomParam, long double MinValue, long double MaxValue,
                    long double (*EvaluationFunc)(std::vector<long double>)){
    srand(time(NULL));
    numVar = NumVar;
    numIt = NumIt;
    temperature = InitialTemperature;
    coolingRate = CoolingRate;
    randomParam = RandomParam;
    minValue = MinValue;
    maxValue = MaxValue;
    evaluationFunc = EvaluationFunc;
}

void SimulatedAnnealing::showBestSolution(){
    std::cout << "BetsAnsVector: ";
    for(int i = 0; i < numVar; i++){
        std::cout << solution[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "BetsAnsFitness: " << evaluationFunc(solution) << std::endl;
}

long double SimulatedAnnealing::checkNewValue(long double newValue){
    if(newValue > maxValue){
        newValue = maxValue;
    }else if(newValue < minValue){
        newValue = minValue;
    }

    return newValue;
}

bool SimulatedAnnealing::changeSolution(std::vector<long double> solution,
                        std::vector<long double> solutionNeighbor){
    long double dif;

    dif = evaluationFunc(solutionNeighbor) - evaluationFunc(solution);

    if(dif < 0){
        return true;
    }else if (exp(-dif/temperature) > uniformRandomNum(0,1)){
        return true;
    }

    return false;
}

void SimulatedAnnealing::run(){
    long double newValue;
    std::vector<long double> solutionNeighbor(numVar);
    solution = uniformVectorRandomNum(numVar);

    for(int i = 0; i < numIt; i++){
        
        for(int j = 0; j < numVar; j++){
            newValue = uniformRandomNum(solution[j] - randomParam,
                                        solution[j] + randomParam);
            solutionNeighbor[j] = checkNewValue(newValue);
        }

        if(changeSolution(solution, solutionNeighbor)){
            solution = solutionNeighbor;
        }

        temperature *= coolingRate;
    }

    showBestSolution();
}


long double SimulatedAnnealing::uniformRandomNum(long double MinValue, long double MaxValue){
    double f = (double)rand() / RAND_MAX;
    return (long double)(MinValue + f * (MaxValue - MinValue));
}

std::vector<long double> SimulatedAnnealing::uniformVectorRandomNum(int size){
    std::vector<long double> randomNums;

    for(int i = 0; i < size; i++){
        randomNums.push_back(uniformRandomNum(minValue, maxValue));
    }

    return randomNums;
}