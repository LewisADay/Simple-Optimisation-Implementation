
#include <iostream>
#include <math.h>
#include <vector>

#include "problems.hpp"

OptimisationProblem::OptimisationProblem() {}

Forrester::Forrester() {}

float Forrester::func(std::vector<float> x){
    float _x = x.at(0.0f);
    return (float) pow((6.0f * _x - 2.0f), 2.0f) * sin(12.0f * _x - 4.0f);
}

Levy::Levy() {}

float Levy::func(std::vector<float> x){

    int d = x.size();

    std::vector<float> w(d, 0.0f);
    
    for (int i = 0; i < d; i++) {
        w.at(i) = 1.0f + ((x.at(i) - 1.0f) / 4.0f);
    }

    float term1 = pow(sin(M_PI * w.at(0)), 2.0f);

    float term2 = 0.0f;
    for (int i = 0; i < d - 1; i++) {
        term2 += pow(w.at(i) - 1.0f, 2.0f) * (1.0f + 10*pow(sin(M_PI * w.at(i) + 1.0f), 2.0f));
    }

    float term3 = pow(w.at(d-1) - 1.0f, 2.0f) * (1.0f + pow(sin(2*M_PI * w.at(d-1)), 2.0f));

    return term1 + term2 + term3;
}
