
#include <iostream>

//#include "optimisers.hpp"
#include "problems.hpp"
#include <vector>

int main()
{

    std::vector<float> test_x = {0.5};

    Forrester problemFunction;
    float f_x = problemFunction.func(test_x);

    std::cout << f_x << std::endl;
}
