/////
// Implement all the utilities need for the optimizer class
// in particular implement:
// -methods for dealing with vector<double>: norm, sum and subtraction, gradient with respect of a given function in a given point
// -struct of the parameters
// -enumeration for choosing the type of learning rate scheme
//

#ifndef UTILITIES
#define UTILITIES


#include <vector>
#include <functional>

// R2 generic function
using vect = std::vector<double>;
using fun = std::function<double(vect)>;
using m_grad = std::function<vect(vect)>;

// enumeration for the choice of the learning rate
enum lr_type{
    exp_decay = 0,
    inv_decay = 1,
    arm = 2
};

// parameters struct
struct params
{
    vect x0 = {10. , 10.};
    double epsilon_step = 1E-6;
    double epsilon_residual = 1E-6;
    double h = 0.1;
    double lr = 0.05; // is the alpha_0 of the documenation
    double mu = 0.2;
    double ni = 0.9;
    double sigma = 0.3;
    int k_max = 500;
    int dim = 2;
    lr_type lr_choice = exp_decay;

};

//params my_param;


// Helper functions (need to be moved in an Utilities.hpp files)
vect grad(vect const & x, fun const & f, double h);
template <bool op> vect concat(vect const & x, vect const & y);
vect mult(vect & x, double & val);
double norm(vect const & x);


#endif
