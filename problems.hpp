#ifndef __PROBLEMS_H_INCLUDED__
#define __PROBLEMS_H_INCLUDED__

#include <vector>

// Just so the limits are nicely named for readability
struct lim {
    float upper;
    float lower;

    lim() {}

    lim(float l, float u) {
        lower = l;
        upper = u;
    }
};

class OptimisationProblem {
    public:
        OptimisationProblem();
        virtual float func(std::vector<float> x) const = 0;
        float get_dim();
        void set_dim(int d);
        lim get_limits();
        void set_limits(float l, float u);
        int dim;
        lim limits;
};

class Forrester : public OptimisationProblem {
    public:
        Forrester();
        float func(std::vector<float> x) const;
        int dim;
        lim limits;
};

class Levy : public OptimisationProblem {
    public:
        Levy(int d);
        float func(std::vector<float> x) const;
        int dim;
        lim limits;
};

#endif // __PROBLEMS_H_INCLUDED__