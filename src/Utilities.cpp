#include "Utilities.hpp"
#include <cmath>


vect grad(vect const & x, fun const & f){
    // using finite difference
    vect my_grad(my_param.dim, 0.0);
    vect hvec(my_param.dim, 0.0);
    double h = my_param.h;

    // compute gradient ( to implement in a more general way)
    for(std::size_t i = 0; i < my_param.dim; ++i){
        hvec.resize(my_param.dim, 0.0);
        hvec[i] = my_param.h;
        my_grad[i] = (f(concat<true>(x, hvec)) - f(concat<false>(x, hvec))) / (2*h);
    }
    
    return my_grad;
}

vect mult(vect & x, double & val){
    vect res(my_param.dim, 0.0);
    for(std::size_t i = 0; i < my_param.dim; ++i)
        res[i] = val * x[i];
    return res;  
}

template <bool op>
vect concat(vect const & x, vect const & y){
    vect res(my_param.dim, 0.0);
    for(std::size_t i = 0; i < my_param.dim; ++i){
        if constexpr (op == true)
            res[i] = x[i] + y[i];
        else
            res[i] = x[i] - y[i];    
    }
    return res;
}

double norm(vect const & x){
    double res = 0;
    for(std::size_t i = 0; i < my_param.dim; ++i)
        res += pow(x[i], 2);
    return sqrt(res);
}