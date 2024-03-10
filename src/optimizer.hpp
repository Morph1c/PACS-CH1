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
using fun = std::function<double(double, double)>;
using vect = std::vector<double>;

struct params
{
    vect x0 = {0. , 0.};
    double epsilon_step = 1E-4;
    double epsilon_residual = 1E-4;
    double h = 0.1;
    double lr = 0.01; // NEED TO BE CHANGED TO IMPLEMENT DIFFERENT LEARNING STRATEGIES
    int k_max = 500;
    int dim = 2;

};

void test_function(void);
double solver(params const & my_params, fun  const &f);
vect grad(vect const & x, fun const & f, params const & my_param);
vect mult(vect & x, double const c, params my_param);
double obj_func(double const x, double const y);
double norm(vect const & x, params const & my_param);


#endif