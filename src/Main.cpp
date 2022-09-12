#include " SimulatedAnnealing/ SimulatedAnnealing.cpp"

long double evaluationFunc(std::vector<long double> vector){
    long double sum = 0;

    for(int i = 0; i < vector.size(); i++){
        sum += vector[i];
    }

    return sum;
}

long double evaluationFunc2(std::vector<long double> vector){
    long double sum = 0;

    for(int i = 0; i < vector.size(); i++){
        sum += pow(vector[i] - 0.5, 2);
    }

    return sum;
}

int main(){
    SimulatedAnnealing sa(3, 100, 50, 0.9, 0.1, 0, 1, &evaluationFunc2);
    sa.run();

    return 0;
}