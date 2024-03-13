//
// Test file for the optimizer
//

#include <iostream>
#include "optimizer.cpp"

using std::cout;

double obj_func(vect x);

int main(void){
    params my_param;
    Optimizer op(my_param);
    
    vect my_grad{0., 0.};
    vect my_point{1.0, 2.0};
    vect sol(my_param.dim, 0.0);
    cout << "First version of test" << std::endl;
    cout << "Default number of max iterations is " << my_param.k_max << std::endl;
    cout << "f(1, 2)= " << obj_func(my_point) << std::endl;
    my_grad = grad(my_point, obj_func, my_param.h);
    cout << "grad f(1, 2) = " << my_grad[0] << " , " << my_grad[1] << std::endl;
    cout << "vector norm is " << norm(my_point) << std::endl;
    cout << std::endl;
    cout << "Running solver.." << std::endl;
    sol = op.solver(obj_func);
    cout << "Min is reached at point: " << "(" << sol[0] << " , " << sol[1] << ")" << std::endl;


    return 0;
}

double obj_func(vect x){
    //return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
    return x[0]*x[0] + x[1]*x[1] - 5;
}

