
#include <iostream>
#include <cstring>
#include <vector>

#include "optimisers.hpp"
#include "problems.hpp"

int main(int argc, char** argv)
{

    // Setup random number generation
    std::srand(time(nullptr));

    // Haven't used Clap before, so I did this simple command line
    // input system for ease and minor validaton.
    // Playing around with Clap is now on my todo list, but didn't want to waste time on it
    // for the sake of this already over-time project - it was fun (read: frustrating at times)
    // to do c++ again, but towards the end I somewhat felt like I knew what I was doing
    // which is how I know I have a long way to go.

    // Command line input validation
    if (argc != 3) {
        std::cout   << "Please provide appropriate inputs of the form\n"
                    << "process-name <Problem> <Method>"
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
        problem = new Levy(2); // Default to 2D Levy for ease
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
        opt = new LocalRandomSearch(0.1f);
    } else if (strcmp(argv[2], "SimulatedAnnealing") == 0) {
        opt = new SimulatedAnnealing(0.1f, 100, 0.75);
    } else {
        std::cout   << "Invalid optimiser selection, please select\n"
                    << "between LocalRandomSearch and SimulatedAnnealing"
                    << std::endl;
    }
    

    // Run our optimiser
    std::vector<float> x = (*opt).RunOptimisation(problem, 1000);

    // Calcualte the value of the problem at that location
    float y = (*problem).func(x);

    // Report the optimised location and value
    std::cout << "Found location:\n";
    std::cout << "(" << x[0];
    for (int i = 1; i < x.size(); i++) {
        std::cout << ", " << x[i];
    }
    std::cout << ")" << std::endl;

    std::cout << "Location value: " << y << std::endl;

    return 0;
}
