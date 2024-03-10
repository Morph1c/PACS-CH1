//
// Header for the optimizer
// defining the main structure of the code and all
// the important parameters
//

#ifndef PACS_CH_1
#define PACS_CH_1

#include <vector>

struct params
{
    double epsilon_step = 1E-4;
    double epsilon_residual = 1E-4;
    int k_max = 500;

};



#endif