#include "optimizer.hpp"
#include "Utilities.cpp"
#include <iostream>
#include <cmath>



Optimizer::Optimizer(params const & _p, fun const & _f, m_grad const & _mgrad): my_param(_p), m_fun(_f), my_grad(_mgrad){
    sol.resize(0.0, my_param.dim);
};

/// Implement the choice of the learning rate scheme that can be choose between: exponential decay, inverse decay and Armjirno's rule
/// @tparam lr_choice is the learnig rate scheme that has to be used
/// @param k is the iteration number
/// @param x_k is the vector x_k
/// @return return the value of the learning rate
template <lr_type lr_choice> 
double Optimizer::get_lr(int k, vect const & x_k) const{
    double my_lr;
    if constexpr (lr_choice == exp_decay){
        my_lr = my_param.lr * exp(-1*my_param.mu * k);
    }

    else if constexpr (lr_choice == inv_decay){
        my_lr = my_param.lr * (1.0 / (1.0 + my_param.mu * k));
    }

    else{
        // implement the Armijo rule
        my_lr = my_param.lr;
        vect mgrad = grad(x_k, m_fun, my_param.h);
        while( ( m_fun(x_k) - m_fun(concat<false>(x_k, mult(mgrad, my_lr))) ) < my_param.sigma * my_lr * pow(norm(mgrad), 2)){
            my_lr = my_lr / 2.0;
        }    
    }

    return my_lr;
}


/// Implement the solver for the Optimizer function, use a selected iterative algorithm to minimize the function
/// as template function takes as input
/// @tparam sch type of iterative scheme to be used for optimizing the function
/// @tparam lscheme type of learning rate to choose
/// @tparam exact_grad TRUE if you want to use exact gradient otherwise use centered finite difference using flexibility of function wrappers
/// we use this type of organization so that the code is more efficent avoiding to compute if else statement each time in the while loop
template <grad_scheme sch, lr_type lscheme, bool exact_grad>
void Optimizer::solver(){
   
    vect x_k, x_prev, y, x_kk, diff, mgrad ;
    x_k = x_prev = y = x_kk = diff = mgrad = my_param.x0;
    double my_lr;
    int k{0};

    // Choosing between exact gradient usage or finite difference
    if constexpr (exact_grad == true)
        mgrad = my_grad(x_k);
    else 
        mgrad = grad(x_k, m_fun, my_param.h);

    // Choosing between classical gradient descent and nesterov scheme
    if constexpr (sch == grad_descent){ // Grad descent scheme
        my_lr = get_lr<lscheme>(k, x_k);
        x_kk = concat<false>(x_k, mult(mgrad, my_lr)); 
    }
    else{ // Nesterov scheme
        my_lr = get_lr<lscheme>(k, x_k);
        x_k = concat<false>(x_k, mult(mgrad, my_lr)); // for inizializing x1
        diff = concat<false>(x_k, x_prev);
        y = concat<true>(x_k, mult(diff, my_param.ni));
        if constexpr (exact_grad == true)
            mgrad = my_grad(y);
        else
            mgrad = grad(y, m_fun, my_param.h);
        x_kk = concat<false>(y, mult(mgrad, my_lr));
    }

    while((norm(concat<false>(x_k, x_kk)) > my_param.epsilon_step) && (fabs(m_fun(x_kk) - m_fun(x_k)) > my_param.epsilon_residual) &&
        k < my_param.k_max){
            k++;
            if constexpr (sch == grad_descent){
                x_k = x_kk;
                if constexpr (exact_grad == true)
                    mgrad = my_grad(x_k);
                else
                    mgrad = grad(x_k, m_fun, my_param.h);
                my_lr = get_lr<lscheme>(k, x_k); 
                x_kk = concat<false>(x_k, mult(mgrad, my_lr));
            }
            else{
                x_prev = x_k;
                x_k = x_kk;
                my_lr = get_lr<lscheme>(k, x_k); 
                diff = concat<false>(x_k, x_prev);
                y = concat<true>(x_k, mult(diff, my_param.ni));
                if constexpr (exact_grad == true)
                    mgrad = my_grad(y);
                else
                    mgrad = grad(y, m_fun, my_param.h);
                x_kk = concat<false>(y, mult(mgrad, my_lr));
            }
    }

    if(k < my_param.k_max)
        std::cout << "Converged in number of iters: " << k << " last learning rate value was "<< my_lr << std::endl;
    else
        std::cout << "Reached max number of iteration, your solution could be not a local minima, " << " last learning rate value was "<< my_lr << std::endl;

    sol = x_kk;
}

// print the solution
void Optimizer::get_solution() const{
    std::cout << "Local minima found at: (";
    for(std::size_t i = 0; i < my_param.dim; ++i)
        std::cout << " " << sol[i];
    std::cout << " )" << std::endl;
    std::cout << "the value of function evaluated at the point is: " << m_fun(sol) << std::endl;
}