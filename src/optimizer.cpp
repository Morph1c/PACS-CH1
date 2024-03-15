#include "optimizer.hpp"
#include "Utilities.cpp"
#include <iostream>
#include <cmath>

//double obj_func(vect x){
    //return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
//    return x[0]*x[0] + x[1]*x[1] - 5;
//}

Optimizer::Optimizer(params const & p, fun const & f): my_param(p), m_fun(f){
    sol.resize(0.0, my_param.dim);
};


template <lr lr_choice> 
double Optimizer::get_lr(int k, vect const & x_k){
    double my_lr;
    if constexpr (lr_choice == exp_decay){
        my_lr = my_param.lr * exp(-1*my_param.mu * k);
    }

    else if constexpr (lr_choice == inv_decay){
        my_lr = my_param.lr * (1 / (1 + my_param.mu * k));
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

void 
Optimizer::solver(){
   
    vect x_k = my_param.x0;
    vect mgrad = grad(x_k, m_fun, my_param.h);

    int k{0};
    // choosing learning rate strategies at compile time
    lr const lr_scheme = arm;

    double my_lr = get_lr<lr_scheme>(k, x_k); 
    vect x_kk = concat<false>(x_k, mult(mgrad, my_lr));

    while((norm(concat<false>(x_k, x_kk)) > my_param.epsilon_step) && (fabs(m_fun(x_kk) - m_fun(x_k)) > my_param.epsilon_residual) &&
        k < my_param.k_max){
            k++;
            x_k = x_kk;
            mgrad = grad(x_k, m_fun, my_param.h);
            my_lr = get_lr<lr_scheme>(k, x_k); 
            x_kk = concat<false>(x_k, mult(mgrad, my_lr));
    }

    std::cout << "Converged in number of iters: " << k << " last learning rate value was "<< my_lr << std::endl;

    sol = x_k;
}

void Optimizer::get_solution(){
    std::cout << "Local minima found at: (";
    for(std::size_t i = 0; i < my_param.dim; ++i)
        std::cout << " " << sol[i];
    std::cout << " )" << std::endl;
    std::cout << "the value of function evaluated at the point is: " << m_fun(sol) << std::endl;
}