#include "optimizer.hpp"
#include <iostream>
#include <cmath>

void test_function(void){
    std::cout << "Test function from optimizer.cpp" << std::endl;
}

vect grad(vect const & x, fun const & f){
    // using finite difference
    vect my_grad(my_param.dim, 0.0);
    vect hvec(my_param.dim, 0.0);
    double h = my_param.h;

    // compute gradient ( to implement in a more general way)
    for(std::size_t i = 0; i < my_param.dim; ++i){
        hvec.resize(my_param.dim, 0.0);
        hvec[i] = my_param.h;
        my_grad[i] = (f(concat<true>(x, hvec)) - f(concat<false>(x, hvec))) / (2*h);
    }
    
    return my_grad;
}

vect mult(vect & x, double & val){
    vect res(my_param.dim, 0.0);
    for(std::size_t i = 0; i < my_param.dim; ++i)
        res[i] = val * x[i];
    return res;  
}

template <bool op>
vect concat(vect const & x, vect const & y){
    vect res(my_param.dim, 0.0);
    for(std::size_t i = 0; i < my_param.dim; ++i){
        if constexpr (op == true)
            res[i] = x[i] + y[i];
        else
            res[i] = x[i] - y[i];    
    }
    return res;
}

double obj_func(vect x){
    return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
}

double norm(vect const & x){
    double res = 0;
    for(std::size_t i = 0; i < my_param.dim; ++i)
        res += pow(x[i], 2);
    return res;
}

vect solver(fun const & f){
   
    vect x_k = my_param.x0;
    vect mgrad = grad(x_k, f);
    vect x_kk = concat<false>(x_k, mult(mgrad, my_param.lr));

    int k{0};
    std::cout << "x_kk[0] = " << x_kk[0] << " x_kk[1] = " << x_kk[1] << std::endl;
    std::cout << f(x_kk) << std::endl;
    std::cout << "||x_k < x_kk|| = " << norm(concat<false>(x_k, x_kk)) << std::endl;
    std::cout << "|f(x_k) - f(x_kk) = " << fabs(f(x_k) - f(x_kk)) << std::endl;
    while((norm(concat<false>(x_k, x_kk)) > my_param.epsilon_step) && (fabs(f(x_kk) - f(x_k)) > my_param.epsilon_step) &&
        k < my_param.k_max){
            x_k = x_kk;
            mgrad = grad(x_k, f);
            x_kk = concat<false>(x_k, mult(mgrad, my_param.lr));
            ++k;
    }

    std::cout << "Number of iters: " << k << std::endl;

    return x_k;
}