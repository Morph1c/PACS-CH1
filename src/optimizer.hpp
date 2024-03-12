//
// Header for the optimizer
// defining the main structure of the code and all
// the important parameters
//

#ifndef PACS_CH_1
#define PACS_CH_1

#include "Utilities.hpp"

// enumeration for the choice of the learning rate
enum lr{
    exp_decay,
    inv_decay,
    arm
};

vect solver(fun const & f);
double obj_func(vect x);
template <lr> double get_lr(int k);


#endif