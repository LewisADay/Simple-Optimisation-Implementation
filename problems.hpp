#ifndef __PROBLEMS_H_INCLUDED__
#define __PROBLEMS_H_INCLUDED__

#include <vector>

class OptimisationProblem {
    public:
        OptimisationProblem();
        
        virtual float func(std::vector<float> x) = 0;
};

class Forrester : public OptimisationProblem {
    public:
        Forrester();

        virtual float func(std::vector<float> x);
};

class Levy : public OptimisationProblem {
    public:
        Levy();
        
        virtual float func(std::vector<float> x);
};

#endif // __PROBLEMS_H_INCLUDED__