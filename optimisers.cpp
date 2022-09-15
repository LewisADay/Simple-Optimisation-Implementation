
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "problems.hpp"
#include "optimisers.hpp"

float randomInRange(float min, float max) {
    float dif = max - min;
    return (dif * ((float) rand() / RAND_MAX)) + min;
}

bool validLocation(std::vector<float> x, const OptimisationProblem *problem) {
    for (const float& i : x) {
        if (i < (*problem).limits.lower || i > (*problem).limits.upper) {
            std::cout << "invalid" << std::endl;
            return false;
        }
    }
    return true;
}

void printVec(std::vector<float> vec) {
    std::cout << "Printing vector:\n(  ";
    for (const float& i : vec) {
        std::cout << i << "  ";
    }
    std::cout << ")" << std::endl;
}

Optimiser::Optimiser() {}

std::vector<float> Optimiser::GetInitialLocation(const OptimisationProblem *problem) const {

    // Get problem dimension
    int d = (*problem).dim;

    // Get initial location
    std::vector<float> init_x;
    float best_y;
    for (int i = 0; i < d; i++) {
        init_x.push_back(randomInRange((*problem).limits.lower, (*problem).limits.upper));
    }

    return init_x;
}

StocasticOptimiser::StocasticOptimiser()  {}

std::vector<float> StocasticOptimiser::GetCandidateLocation(std::vector<float> x, float radius, const OptimisationProblem *problem) const {
    // We generate n-dimensional coordinates, such that they lie within the
    // n-dimensional hypercube with sidelength radius.
    // Whilst not properly uniform, nor sampling from within the hypershere of radius radius,
    // it suits our purposes.

    // Get starting random vector and determine its magnitude
    std::vector<float> randVec;
    do { // Do until a valid location is selected

        // Reset our random vector
        randVec = {};

        // Get its elements
        for (int i = 0; i < x.size(); i++) {
            // Get random float between -0.5 and 0.5
            float elem = ((float) rand() / RAND_MAX) - 0.5f;
            // Scale appropriately and add to x
            elem = (2 * elem * radius) + x[i];
            // Add to our random vector
            randVec.push_back(elem);
        }

    } while (!validLocation(randVec, problem));
    
    return randVec;
}

LocalRandomSearch::LocalRandomSearch(float r) {
    radius = r;
}

std::vector<float> LocalRandomSearch::RunOptimisation(const OptimisationProblem *problem, int num_steps) const {

    // Set radius
    float radius = 0.1f;

    // Get starting location
    std::vector<float> best_x = Optimiser::GetInitialLocation(problem);
    float best_y = (*problem).func(best_x);

    // Setup candidate location
    std::vector<float> cand_x;
    float cand_y;


    // Main optimiser loop
    for (int _ = 0; _ < num_steps; _++) {

        // Get candidate location
        cand_x = StocasticOptimiser::GetCandidateLocation(best_x, radius, problem);
        
        cand_y = (*problem).func(cand_x);

        // Compare candidate to best known solution
        // we assume we are minimising
        if (cand_y < best_y) {
            // Adopt the candidate as our best solution
            best_x = cand_x;
            best_y = cand_y;
        }
    }

    return best_x;
}

SimulatedAnnealing::SimulatedAnnealing(float r, float T, float a) {
    radius = r;
    start_temp = T;
    alpha = a;
}

std::vector<float> SimulatedAnnealing::RunOptimisation(const OptimisationProblem *problem, int num_steps) const {

    // Get starting location
    std::vector<float> best_x = Optimiser::GetInitialLocation(problem);
    float best_y = (*problem).func(best_x);

    // Setup current and candidate locations
    std::vector<float> curr_x = best_x;
    float curr_y = best_y;
    std::vector<float> cand_x;
    float cand_y;

    // Set temperature
    float temp = start_temp;

    // Main optimiser loop
    for (int _ = 0; _ < num_steps; _++) {

        // Get candidate location
        cand_x = StocasticOptimiser::GetCandidateLocation(curr_x, radius, problem);
        cand_y = (*problem).func(cand_x);

        // Compare candidate to best known solution
        // we assume we are minimising
        if (cand_y < best_y) {
            // Adopt the candidate as our best solution
            best_x = cand_x;
            best_y = cand_y;
            continue;
        }

        // Otherwise perform temperature check
        float mac = pow(M_E, (curr_y - cand_y)/temp);
        if (mac > randomInRange(0.0f, 1.0f)) {
            curr_x = cand_x;
            curr_y = cand_y;
        }

        // Decrease our temperature to simulate the progressive cooling
        temp *= alpha;
    }

    return best_x;
}
