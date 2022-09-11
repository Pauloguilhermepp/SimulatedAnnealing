#include " SimulatedAnnealing/ SimulatedAnnealing.cpp"

long double evaluationFunc(std::vector<long double> vector){
    long double sum = 0;

    for(int i = 0; i < vector.size(); i++){
        sum += vector[i];
    }

    return sum;
}

int main(){
    SimulatedAnnealing sa(3, 100, 50, 0.1, 0.1, 0, 1, &evaluationFunc);
    sa.run();

    return 0;
}