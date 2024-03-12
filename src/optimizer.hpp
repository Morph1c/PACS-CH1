//
// Header for the optimizer
// defining the main structure of the code and all
// the important parameters
//

#ifndef PACS_CH_1
#define PACS_CH_1

#include <vector>
#include <functional>

// R2 generic function
using vect = std::vector<double>;
using fun = std::function<double(vect)>;

struct params
{
    vect x0 = {0. , 0.};
    double epsilon_step = 1E-6;
    double epsilon_residual = 1E-6;
    double h = 0.1;
    double lr = 0.05; // NEED TO BE CHANGED TO IMPLEMENT DIFFERENT LEARNING STRATEGIES
    int k_max = 500;
    int dim = 2;

};

params my_param;

void test_function(void);
vect solver(fun const & f);
double obj_func(vect x);

// Helper functions (need to be moved in an Utilities.hpp files)
vect grad(vect const & x, fun const & f);
template <bool op> vect concat(vect const & x, vect const & y);
vect mult(vect & x, double & val);
double norm(vect const & x);


#endif