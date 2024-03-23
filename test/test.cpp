//
// Test file for the optimizer
// in that file we define the objectIve function to be minimized
// and also the exact gradient 
//

#include <iostream>
#include "optimizer.cpp"
#include "getpot_lib/GetPot"

using std::cout;

double obj_func(vect x);
vect grad_func(vect x);

int main(int argc, char ** argv){
    params my_param;
    int my_scheme_num;
    bool exact_grad;
    GetPot command_line(argc, argv);

    const std::string filename = command_line.follow("param.dat", 2, "-f", "--file"); // 2 significa che sia -f che --file va bene per dichiarare il nome del file
    GetPot gp(filename.c_str());

    // fill the parameters
    my_param.epsilon_step = gp("epsilon_step", my_param.epsilon_step);
    my_param.epsilon_residual = gp("epsilon_residual", my_param.epsilon_residual);
    my_param.h = gp("h", my_param.h);
    my_param.lr = gp("lr", my_param.lr);
    my_param.mu = gp("mu", my_param.mu);
    my_param.sigma = gp("sigma", my_param.sigma);
    my_param.k_max = gp("k_max", my_param.k_max);
    my_param.dim = gp("dim", my_param.dim);
    my_param.lr_choice = static_cast<lr_type>(gp("lr_scheme", 0));

    // Fill the hyperparameters
    my_scheme_num = gp("grad_scheme", 0);
    exact_grad = gp("exact_grad", 0);

    // used for fill the initial guess vector from getpot    
    std::string point = "x0_";
    for(int i = 0; i < my_param.dim; i++){
        point += std::to_string(i);
        my_param.x0[i] = gp(point.c_str(), 0.0);
        point = "x0_";
    }

    // Initialize the class Optimizer    
    Optimizer op(my_param, obj_func, grad_func);
    if(my_scheme_num == grad_descent){
        cout << "Running classical gradient descent..." << std::endl;
        if (exact_grad == true)
            op.solver<grad_descent, true>();
        else
            op.solver<grad_descent, false>();
    }
    else{
        cout << "Running nesterov algorithm..." << std::endl;
        if (exact_grad)
            op.solver<nesterov, true>();
        else
            op.solver<nesterov, false>();    
    }
    
    op.get_solution();

    return 0;
}

double obj_func(vect x){
    return x[0]*x[1] + 4*pow(x[0], 4) + pow(x[1], 2) + 3*x[0];
}

vect grad_func(vect x){
    vect computed_grad(x.size(), 0.0);
    computed_grad[0] = x[1] + 16 * pow(x[0], 3) + 3;
    computed_grad[1] = x[0] + 2 * x[1];

    return computed_grad;
}
