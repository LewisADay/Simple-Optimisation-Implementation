#ifndef __PROBLEMS_H_INCLUDED__
#define __PROBLEMS_H_INCLUDED__

#include <vector>

class OptimisationProblem {
    public:
        virtual float func(std::vector<float> x) const = 0;
};

class Forrester : public OptimisationProblem {
    public:
        float func(std::vector<float> x) const;
};

class Levy : public OptimisationProblem {
    public:
        float func(std::vector<float> x) const;
};

#endif // __PROBLEMS_H_INCLUDED__