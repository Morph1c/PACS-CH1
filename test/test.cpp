//
// Test file for the optimizer
//

#include <iostream>
#include "optimizer.cpp"
#include "getpot_lib/GetPot"

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
    
        //my_param.x0.resize(my_param.dim, 0.0);
    std::string point = "x0_";
    for(std::size_t i = 0; i < my_param.dim; i++){
        point += std::to_string(i);
        my_param.x0[i] = gp(point.c_str(), 0.0);
        point = "x0_";
    }
    
    cout << my_param.x0[1] << std::endl;
    Optimizer op(my_param, obj_func);
    cout << "k_max is " << my_param.k_max << std::endl;
    op.solver();
    op.get_solution();

    return 0;
}

double obj_func(vect x){
    return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
    //return x[0]*x[0] + x[1]*x[1] - 5;
}

