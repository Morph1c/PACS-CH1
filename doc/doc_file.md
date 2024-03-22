# PARAMETERS STRUCTURE
This is official documentation for explaining the structure and meaning of the parameters structure.
In particular we use a GetPot file to pass all the important parameters for the class Optimizer, all the possible parameters are:
```bash
we pass the initial guess for starting the algorithm using this syntax x0_k = .. where k is the k-th coordinate
x0_0 = 0
x0_1 = 0
...
x0_n = ..

epsilon_step = 1E-6;
epsilon_residual = 1E-6;
h = 0.01;
lr = 0.0125; // is the alpha_0 of the documenation
mu = 0.2;
sigma = 0.3;
k_max = 500;
dim = 2;
grad_scheme = 1
exact_grad = 1

```
