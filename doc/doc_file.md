# PARAMETERS STRUCTURE
This is official documentation for explaining the structure and meaning of the parameters structure.
In particular we use a GetPot file to pass all the important parameters for the class Optimizer, all the possible parameters are:
we pass the initial guess for starting the algorithm using this syntax x0_k = .. where k is the k-th coordinate
```bash
x0_0 = 0
x0_1 = 0
...
x0_n = ..
```
for tollerance for both the difference between solution at k and k+1 and respective values of the function:
```bash
epsilon_step = 1E-6;
epsilon_residual = 1E-6;

```
then h stand for the discretizaion step for computing a derivative through finite difference, lr is the initial learning rate to be used, mu and sigma the hyperparameters for the learning rate scheme of Inverse decay (mu) and Armjirno (sigma=
```bash
h = 0.01;
lr = 0.0125; // is the alpha_0 of the documenation
mu = 0.2;
sigma = 0.3;
```
finally we have k_max for the maximum number of iterations, dim is the dimension of the space $R^{dim}$ and grad_scheme is for selecting the optimization algorithm where 0 for using gradient descent while 1 for using Nesterov algorithm. Last exact grad takes value 0 for using finite difference scheme for computing the derivative while 1 for using exact formula of the gradient that need to be defined inside the Test.cpp file
```bash

k_max = 500;
dim = 2;
grad_scheme = 1
exact_grad = 1

```
