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

class Optimizer{
    private:
        params my_param;
        vect sol;
        fun const & m_fun;
    public:
        Optimizer(params const & p, fun const & f);
        void solver();
        template <lr> double get_lr(int k, vect const & x_k);
        void get_solution();
};

#endif