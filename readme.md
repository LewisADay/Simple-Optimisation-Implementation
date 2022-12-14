# Simple Optimisation Implementation

Small program written in C++14 with the simple command line interface
> program-name \<Problem\> \<Optimiser\>

Where your choices for problem are "Forrester" and "Levy", and the defined optimisers are "LocalRandomSearch" and "SimulatedAnnealing".

### Compilation

Compiled with gcc version 9.4.0 using command:
> g++ *.cpp -o out

Which provides the program file "out" which may be subsituted for program-name above to run the optimisations.

### Future Work

Extensions to this work that may be carried out in the future are:

- Use Clap to process and manage the command line interface so usability and style.
- Add the functionality to be able to specify, by command line options, parameters such as the dimension of the Levy problem to use (default = 2), or the maximum number of iterations of the given optimiser.
