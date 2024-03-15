//
// Test file for the optimizer
//

#include <iostream>
#include "optimizer.cpp"
#include "../getpot/GetPot"

using std::cout;

double obj_func(vect x);

int main(int argc, char ** argv){
    params my_param;

    GetPot command_line(argc, argv);
    const std::string filename = command_line.follow("param.dat", 2, "-f", "--file"); // 2 significa che sia -f che --file va bene per dichiarare il nome del file
    
    GetPot gp(filename.c_str());

    // fill the parameters
    // how to fill a vector?
    my_param.epsilon_step = gp("epsilon_step", my_param.epsilon_step);
    my_param.epsilon_residual = gp("epsilon_residual", my_param.epsilon_residual);
    my_param.h = gp("h", my_param.h);
    my_param.lr = gp("lr", my_param.lr);
    my_param.mu = gp("mu", my_param.mu);
    my_param.sigma = gp("sigma", my_param.sigma);
    my_param.k_max = gp("k_max", my_param.k_max);
    my_param.dim = gp("dim", my_param.dim);

    Optimizer op(my_param, obj_func);
    vect sol(my_param.dim, 0.0);
    cout << "mu is " << my_param.mu << std::endl;
    op.solver();
    op.get_solution();

    return 0;
}

double obj_func(vect x){
    return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
    //return x[0]*x[0] + x[1]*x[1] - 5;
}

