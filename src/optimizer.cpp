#include "optimizer.hpp"
#include <iostream>
#include <cmath>

void test_function(void){
    std::cout << "Test function from optimizer.cpp" << std::endl;
}

//void grad(vect const & x, fun const & f, vect & my_grad, double h){
    // using finite difference
//    my_grad[0] = (f(x[0] + h, x[1]) - f(x[0] - h, x [1])) / (2*h);
//    my_grad[1] = (f(x, x[1] + h) - f(x[0], x [1] - h)) / (2*h);
//}

double obj_func(double const x, double const y){
    return x*y + 4*pow(x, 4) + pow(y, 2) + 3*x;
}