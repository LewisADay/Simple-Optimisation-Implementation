
#include <iostream>
#include "problems.hpp"
#include "optimisers.hpp"

std::vector<float> LocalRandomSearch::RunOptimisation (const OptimisationProblem *problem, int num_steps) const {
    std::vector<float> test_x = {1, 1, 1};
    float tmp = (*problem).func(test_x);
    std::cout << tmp << std::endl;
    return test_x;
}
