#ifndef __OPTIMISERS_H_INCLUDED__
#define __OPTIMISERS_H_INCLUDED__

#include <vector>
#include "problems.hpp"

class Optimiser{
    public:
        virtual std::vector<float> RunOptimisation(const OptimisationProblem *problem, int num_steps) const = 0;
};

class LocalRandomSearch : public Optimiser{
    public:
        std::vector<float> RunOptimisation(const OptimisationProblem *problem, int num_steps) const;
};

#endif // __OPTIMISERS_H_INCLUDED__