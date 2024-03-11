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
    double epsilon_step = 1E-4;
    double epsilon_residual = 1E-4;
    double h = 0.1;
    double lr = 0.05; // NEED TO BE CHANGED TO IMPLEMENT DIFFERENT LEARNING STRATEGIES
    int k_max = 500;
    int dim = 2;

};

void test_function(void);
vect solver(params const & my_params, fun  const &f );
double obj_func(vect const & x);

// Helper functions (need to be moved in an Utilities.hpp files)
vect grad(vect const & x, fun const & f, params const & my_param);
vect concat(vect const & x, vect const & y, bool op, params const & my_param);
vect mult(vect & x, double val);
double norm(vect const & x, params const & my_param);


#endif