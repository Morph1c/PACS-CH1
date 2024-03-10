#include "optimizer.hpp"
#include <iostream>
#include <cmath>

void test_function(void){
    std::cout << "Test function from optimizer.cpp" << std::endl;
}

vect grad(vect const x, fun const f, vect & my_grad, params const & my_param){
    // using finite difference
    double h = my_param.h;
    my_grad[0] = (f(x[0] + h, x[1]) - f(x[0] - h, x [1])) / (2*h);
    my_grad[1] = (f(x[0], x[1] + h) - f(x[0], x [1] - h)) / (2*h);
    
    return my_grad;
}

vect mult(vect & x, params my_param){
    for(std::size_t i = 0; i < my_param.dim; ++i)
        x[i] = my_param.lr * x[i];
    return x;  
}

vect subtract(vect const & x, vect const & y, params my_params,  vect & res){
    for(std::size_t i = 0; i < my_param.dim; ++i)
        x[i] = my_param.lr * x[i];
    return x;  
}

double obj_func(double const x, double const y){
    return x*y + 4*pow(x, 4) + pow(y, 2) + 3*x;
}

double norm(vect const & x, params const & my_param){
    double res{0};
    for(std::size_t i = 0; i < my_param.dim; ++i)
        res += pow(x[i], 2);
    return res;
}

double solver(params const & my_params, fun  const &f){
    vect x_k = my_params.x0;
    vect mgrad = grad(x_k, obj_func, my_params);
    vect x_kk = x_k - mult(mgrad, my_params);
}