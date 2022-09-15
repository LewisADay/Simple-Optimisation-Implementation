#ifndef __OPTIMISERS_H_INCLUDED__
#define __OPTIMISERS_H_INCLUDED__

#include <vector>
#include "problems.hpp"

class Optimiser {
    public:
        Optimiser();
        virtual std::vector<float> RunOptimisation(const OptimisationProblem *problem, int num_steps) const = 0;
        std::vector<float> GetInitialLocation(const OptimisationProblem *problem) const;
};

class StocasticOptimiser : public Optimiser {
    public:
        StocasticOptimiser();
        virtual std::vector<float> RunOptimisation(const OptimisationProblem *problem, int num_steps) const = 0;
        std::vector<float> GetInitialLocation(const OptimisationProblem *problem) const;
        std::vector<float> GetCandidateLocation(std::vector<float> x, float radius, const OptimisationProblem *problem) const;
};

class LocalRandomSearch : public StocasticOptimiser {
    public:
        LocalRandomSearch(float r);
        std::vector<float> RunOptimisation(const OptimisationProblem *problem, int num_steps) const;
        std::vector<float> GetInitialLocation(const OptimisationProblem *problem) const;
        std::vector<float> GetCandidateLocation(std::vector<float> x, float radius, const OptimisationProblem *problem) const;
        float radius;
};

class SimulatedAnnealing : public StocasticOptimiser {
    public:
        SimulatedAnnealing(float r, float T, float a);
        std::vector<float> RunOptimisation(const OptimisationProblem *problem, int num_steps) const;
        std::vector<float> GetInitialLocation(const OptimisationProblem *problem) const;
        std::vector<float> GetCandidateLocation(std::vector<float> x, float radius, const OptimisationProblem *problem) const;
        float radius;
        float start_temp;
        float alpha;
};

#endif // __OPTIMISERS_H_INCLUDED__