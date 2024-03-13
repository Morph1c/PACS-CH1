#include "Utilities.hpp"
#include <cmath>


vect grad(vect const & x, fun const & f, double h){
    // using finite difference
    int dim = x.size();
    vect my_grad(dim, 0.0);
    vect hvec(dim, 0.0);

    // compute gradient ( to implement in a more general way)
    for(std::size_t i = 0; i < dim; ++i){
        hvec.resize(dim, 0.0);
        hvec[i] = h;
        my_grad[i] = (f(concat<true>(x, hvec)) - f(concat<false>(x, hvec))) / (2*h);
    }
    
    return my_grad;
}

vect mult(vect & x, double & val){
    int dim = x.size();
    vect res(dim, 0.0);
    for(std::size_t i = 0; i < dim; ++i)
        res[i] = val * x[i];
    return res;  
}

template <bool op>
vect concat(vect const & x, vect const & y){
    int dim = x.size();
    vect res(dim, 0.0);
    for(std::size_t i = 0; i < dim; ++i){
        if constexpr (op == true)
            res[i] = x[i] + y[i];
        else
            res[i] = x[i] - y[i];    
    }
    return res;
}

double norm(vect const & x){
    double res = 0;
    for(std::size_t i = 0; i < x.size(); ++i)
        res += pow(x[i], 2);
    return sqrt(res);
}