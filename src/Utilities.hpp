/////
// Implement all the utilities need for dealing with vectorial quantities
// so it implement functions for evaluating norms, vector summationa and subtraction
// and also scalar multiplication
//

#ifndef UTILITIES
#define UTILITIES


#include <vector>
#include <functional>

// R2 generic function
using vect = std::vector<double>;
using fun = std::function<double(vect)>;


// parameters struct
struct params
{
    vect x0 = {0. , 0.};
    double epsilon_step = 1E-6;
    double epsilon_residual = 1E-6;
    double h = 0.1;
    double lr = 0.05; // is the alpha_0 of the documenation
    double mu = 0.2;
    double sigma = 0.3;
    int k_max = 500;
    int dim = 2;

};

params my_param;


// Helper functions (need to be moved in an Utilities.hpp files)
vect grad(vect const & x, fun const & f);
template <bool op> vect concat(vect const & x, vect const & y);
vect mult(vect & x, double & val);
double norm(vect const & x);


#endif
