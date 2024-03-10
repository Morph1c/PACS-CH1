//
// Test file for the optimizer
//

#include <iostream>
#include "optimizer.cpp"

using std::cout;

int main(void){
    params my_param;
    vect my_grad{0., 0.};
    vect my_point{1.0, 2.0};
    double h = 0.1;
    cout << "First version of test" << std::endl;
    cout << "Default number of max iterations is " << my_param.k_max << std::endl;
    test_function();
    cout << "f(1, 2)= " << obj_func(1.0, 2.0) << std::endl;
    grad(my_point, obj_func, my_grad, my_param);
    cout << "grad f(1, 2) = " << my_grad[0] << " , " << my_grad[1] << std::endl;
    cout << "vector norm is " << norm(my_point, my_param) << std::endl;


    return 0;
}

