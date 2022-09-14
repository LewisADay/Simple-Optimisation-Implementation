#ifndef __OPTIMISERS_H_INCLUDED__
#define __OPTIMISERS_H_INCLUDED__

// Forward declared dependencies
class OptimisationProblem;

class Optimiser{
    public:
        Optimiser();
        virtual void RunOptimiser(int num_steps, OptimisationProblem f) = 0;
};

class LocalRandomSearch{
    public:
        void RunOptimiser(int num_steps, OptimisationProblem f);
};

#endif // __OPTIMISERS_H_INCLUDED__