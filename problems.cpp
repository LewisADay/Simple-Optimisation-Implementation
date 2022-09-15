
#include <iostream>
#include <math.h>
#include <vector>

#include "problems.hpp"

// Base class methods
// Constructor
OptimisationProblem::OptimisationProblem() {}

// Getters and setters for dim and limits
float OptimisationProblem::get_dim() {
    return this->dim;
}

void OptimisationProblem::set_dim(int d) {
    this->dim = d;
}

lim OptimisationProblem::get_limits() {
    return this->limits;
}

void OptimisationProblem::set_limits(float l, float u) {
    this->limits.lower = l;
    this->limits.upper = u;
}


// Forrester problem class
// http://www.sfu.ca/~ssurjano/forretal08.html
// Constructor
Forrester::Forrester() {
    this->set_dim(1);
    this->set_limits(0.0f, 1.0f);
}

// Function call
float Forrester::func(std::vector<float> x) const {
    float _x = x.at(0.0f);
    return (float) pow((6.0f * _x - 2.0f), 2.0f) * sin(12.0f * _x - 4.0f);
}

// Levy problem class
// http://www.sfu.ca/~ssurjano/levy.html
// Has arbitrary dimension >= 2, we use d = 2 for demonstration
// Constructor
Levy::Levy(int d) {
    this->set_dim(d);
    this->set_limits(-10.0f, 10.0f);
}

// Function call
float Levy::func(std::vector<float> x) const {

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
