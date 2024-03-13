#include "optimizer.hpp"
#include "Utilities.cpp"
#include <iostream>
#include <cmath>

//double obj_func(vect x){
    //return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
//    return x[0]*x[0] + x[1]*x[1] - 5;
//}


template <lr lr_choice> 
double Optimizer::get_lr(int k, fun const & f, vect const & x_k){
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
        vect mgrad = grad(x_k, f, my_param.h);
        while( ( f(x_k) - f(concat<false>(x_k, mult(mgrad, my_lr))) ) < my_param.sigma * my_lr * pow(norm(mgrad), 2)){
            my_lr = my_lr / 2.0;
            std::cout << "chosing alpha_k for iter " << k << " alpha_" << k << " = " << my_lr << std::endl;
            std::cout << "f(..) = " << f(concat<false>(x_k, mult(mgrad, my_lr))) << std::endl;
        }    
    }

    return my_lr;
}

vect Optimizer::solver(fun const & f){
   
    vect x_k = my_param.x0;
    vect mgrad = grad(x_k, f, my_param.h);

    int k{0};
    // choosing learning rate strategies at compile time
    lr const lr_scheme = arm;

    double my_lr = get_lr<lr_scheme>(k, f, x_k); 
    vect x_kk = concat<false>(x_k, mult(mgrad, my_lr));

    std::cout << "x_kk[0] = " << x_kk[0] << " x_kk[1] = " << x_kk[1] << std::endl;
    std::cout << f(x_kk) << std::endl;
    std::cout << "||x_k < x_kk|| = " << norm(concat<false>(x_k, x_kk)) << std::endl;
    std::cout << "|f(x_k) - f(x_kk) = " << fabs(f(x_k) - f(x_kk)) << std::endl;
    while((norm(concat<false>(x_k, x_kk)) > my_param.epsilon_step) && (fabs(f(x_kk) - f(x_k)) > my_param.epsilon_step) &&
        k < my_param.k_max){
            k++;
            x_k = x_kk;
            mgrad = grad(x_k, f, my_param.h);
            my_lr = get_lr<lr_scheme>(k, f, x_k); 
            x_kk = concat<false>(x_k, mult(mgrad, my_lr));

            std::cout << "iter number: " << k << " lr is = " << my_lr << std::endl;
    }

    std::cout << "Number of iters: " << k << std::endl;

    return x_k;
}