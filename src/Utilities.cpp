#include "Utilities.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>    // needed for std::fill

// compute the gradient using the centered finite difference scheme
//
vect grad(vect const & x, fun const & f, double h){
    // using finite difference
    int dim = x.size();
    vect my_grad(dim, 0.0);
    vect hvec(dim, 0.0);

    for(int i = 0; i < dim; ++i){
        // using fill algorithm to fill the vector of the increment to all 0s
        std::fill(hvec.begin(), hvec.end(), 0.0);
        hvec[i] = h; // put equal to h only the i-th coordinate
        my_grad[i] = (f(concat<true>(x, hvec)) - f(concat<false>(x, hvec))) / (2*h);
    }
    
    return my_grad;
}

// compute scalar multiplication 
vect mult(vect & x, double & val){
    int dim = x.size();
    vect res(dim, 0.0);
    for(int i = 0; i < dim; ++i)
        res[i] = val * x[i];
    return res;  
}

// template function for computing the sum or subtraction between two vectors
// true -> compute the sum
// false -> compute subtraction
template <bool op>
vect concat(vect const & x, vect const & y){
    int dim = x.size();
    vect res(dim, 0.0);
    for(int i = 0; i < dim; ++i){
        if constexpr (op == true)
            res[i] = x[i] + y[i];
        else
            res[i] = x[i] - y[i];    
    }
    return res;
}

// compute euclidean norm of a vector
double norm(vect const & x){
    double res = 0;
    for(int i = 0; i < x.size(); ++i)
        res += pow(x[i], 2);
    return sqrt(res);
}