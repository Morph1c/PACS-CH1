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
    vect sol{0.0, 0.0};
    double h = 0.1;
    cout << "First version of test" << std::endl;
    cout << "Default number of max iterations is " << my_param.k_max << std::endl;
    test_function();
    cout << "f(1, 2)= " << obj_func(my_point) << std::endl;
    my_grad = grad(my_point, obj_func, my_param);
    cout << "grad f(1, 2) = " << my_grad[0] << " , " << my_grad[1] << std::endl;
    cout << "vector norm is " << norm(my_point, my_param) << std::endl;
    cout << std::endl;
    cout << "Running solver.." << std::endl;
    sol = solver(my_param, obj_func);
    cout << "Min is reached at point: " << "(" << sol[0] << " , " << sol[1] << ")" << std::endl;


    return 0;
}

