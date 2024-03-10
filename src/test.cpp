//
// Test file for the optimizer
//

#include <iostream>
#include "optimizer.cpp"

using std::cout;

int main(void){
    params my_param;
    cout << "First version of test" << std::endl;
    cout << "Default number of max iterations is " << my_param.k_max << std::endl;
    test_function();

    return 0;
}

