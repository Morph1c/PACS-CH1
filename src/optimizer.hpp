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
    double x0 = 0;
    double epsilon_step = 1E-4;
    double epsilon_residual = 1E-4;
    int k_max = 500;

};

void test_function(void);
double solver(params const & my_params, fun  const &f);
double grad(vect const & x, fun const & f, double h);
double obj_func(double const x, double const y);


#endif