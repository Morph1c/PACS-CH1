#include "optimizer.hpp"
#include <iostream>
#include <cmath>

void test_function(void){
    std::cout << "Test function from optimizer.cpp" << std::endl;
}

vect grad(vect const & x, fun const & f, params const & my_param){
    // using finite difference
    vect my_grad;
    my_grad.reserve(my_param.dim);
    double h = my_param.h;

    // compute gradient ( to implement in a more general way)
    for(std::size_t i = 0; i < my_param.dim; ++i){
        vect hvec(my_param.dim, 0.0);
        hvec[i] = my_param.h;
        my_grad[i] = (f(concat(x, hvec, true, my_param)) - f(concat(x, hvec, false, my_param))) / (2*h);
    }
    
    return my_grad;
}

// DA CAMBIARE
vect mult(vect & x, double val){
    vect res;
    res.reserve(2); // DA CAMBIARE ASSOLUTAMENTE

    for(std::size_t i = 0; i < 2; ++i)
        res[i] = val * x[i];
    return res;  
}

vect concat(vect const & x, vect const & y, bool op, params const & my_param){
    vect res;
    res.reserve(my_param.dim);

    for(std::size_t i = 0; i < my_param.dim; ++i){
        if (op == true)
            res[i] = x[i] + y[i];
        else
            res[i] = x[i] - y[i];    
    }
    return res;
}

double obj_func(vect const & x){
    return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
}

double norm(vect const & x, params const & my_param){
    double res{0};
    for(std::size_t i = 0; i < my_param.dim; ++i)
        res += pow(x[i], 2);
    return res;
}

vect solver(params const & my_param, fun  const &f){
    vect x_k = my_param.x0;
    vect mgrad = grad(x_k, obj_func, my_param);
    vect x_kk = concat(x_k, mult(mgrad, my_param.lr), false, my_param);

    int k{0};
    while((norm(concat(x_k, x_kk, false, my_param), my_param) > my_param.epsilon_step) && (abs(f(x_k) - f(x_k)) > my_param.epsilon_step) &&
        k < my_param.k_max){
            x_k = x_kk;
            x_kk = concat(x_k, mult(mgrad, my_param.lr), false, my_param);
    }

    return x_kk;
}