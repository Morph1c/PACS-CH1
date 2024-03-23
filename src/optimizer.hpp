//
// Main header fo defining the class Optimizer
// it define the main methods and attribute 
// in particular the class Optimizer take as input for the constructor:
// @param params my_param that is a struct containing all the parameters needed, like max iterations, .. look at Utilities.hpp
// @param vect sol is a std::vector<double> that contain the solution found from the optimizer
// @param fun const m_fun is a function wrapper that is used as objective function to be minimized
// @param m_grad const my_grad that is a function wrapper to the gradient of the function 

#ifndef PACS_CH_1
#define PACS_CH_1

#include "Utilities.hpp"

enum grad_scheme{
    grad_descent = 0,
    nesterov = 1
};

class Optimizer{
    private:
        params my_param;
        vect sol;
        fun const m_fun;
        m_grad const my_grad;
    public:
        Optimizer(params const & _p, fun const & _f, m_grad const & _mgrad);
        template <grad_scheme sch, bool exact_grad> void solver();
        double get_lr(int k, vect const & x_k) const;
        void get_solution() const;
};

#endif