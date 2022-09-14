
#include <iostream>

#include <cstring>

#include "optimisers.hpp"
#include "problems.hpp"
#include <vector>

int main(int argc, char** argv)
{
    // Command line input validation
    if (argc != 3) {
        std::cout   << "Please provide appropriate inputs of the form\n"
                    << "./out <Problem> <Method>"
                    << std::endl;
        return -1;
    }

    // Problem function
    OptimisationProblem *problem;

    // Get problem function from command line arguments
    if (strcmp(argv[1], "Forrester") == 0) {
        problem = new Forrester;
    } else if (strcmp(argv[1], "Levy") == 0)
    {
        problem = new Levy;
    } else {
        std::cout   << "Invalid problem selection please select\n"
                    << "between Forrester and Levy"
                    << std::endl;
        return -1;
    }

    // Optimisation function
    Optimiser *opt;

    // Get optimisation function from command line arguments
    if (strcmp(argv[2], "LocalRandomSearch") == 0) {
        opt = new LocalRandomSearch;
    } else {
        std::cout   << "Invalid optimiser selection, please selct\n"
                    << "between LocalRandomSearch and "
                    << std::endl;
    }
    
    (*opt).RunOptimisation(problem, 10);

    std::vector<float> test_x = {1,1,1};
    float res = problem->func(test_x);
    std::cout << res << std::endl;

    Levy tmp;
    std::cout << tmp.func(test_x) << std::endl;
    Forrester tmp1;
    std::cout << tmp1.func(test_x) << std::endl;

    return 0;
}
