//
// Test file for the optimizer
//

#include <iostream>
#include "optimizer.cpp"

using std::cout;

int main(void){
    //params my_param;
    vect my_grad{0., 0.};
    vect my_point{1.0, 2.0};
    vect sol(my_param.dim, 0.0);
    double h = 0.1;
    cout << "First version of test" << std::endl;
    cout << "Default number of max iterations is " << my_param.k_max << std::endl;
    cout << "f(1, 2)= " << obj_func(my_point) << std::endl;
    my_grad = grad(my_point, obj_func);
    cout << "grad f(1, 2) = " << my_grad[0] << " , " << my_grad[1] << std::endl;
    cout << "vector norm is " << norm(my_point) << std::endl;
    cout << std::endl;
    cout << "Running solver.." << std::endl;
    sol = solver(obj_func);
    cout << "Min is reached at point: " << "(" << sol[0] << " , " << sol[1] << ")" << std::endl;


    return 0;
}

