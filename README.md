# Gradient-Based Optimizer
Repository for the first challenge of the course PACS. 
<br>
Implemented a gradient-based optimizer for solving the problem: $$x = argmin_{y \in R^d} \ f(x)$$
<br>
through an iterative algorithm of the form: $$x_{k+1} = x_k - \alpha_k \nabla f(x_k), \ k=0,1,2,..$$
using the Ajirno's rule for computing the learning rate $\alpha_k$: given $\alpha_0$ and $\sigma \in (0, 0.5)$ check the following condition:
$$f(x_k) - f(x_k - \alpha_0 \nabla f(x_k)) \geq \sigma \alpha_0 ||\nabla f(x_k)||^2$$
If hold then $\alpha_k = \alpha_0$, if not then take $\alpha_0 = \alpha_0 / 2$ and repeat until the condtion is satisfied.

# Prerequisite
Solver is written in C++17/20 and STL is used so that it not requires additional libraries.
To clone the repository on local, type:
```bash
git clone git@github.com:Morph1c/PACS-CH1
```
# Usage
Now implemented only a very simpple optimization problem that optimize $f(x) = x_1 x_2 + 4 x_1^4 + x_2^2 + 3 x_1$.
Just type:
```bash
make
```
to compile and get as output $text$ file and execute it:
```bash
./test -f ../src/param.dat
```
to get the optimizer work a compute the minimal point, given the parameters in the "param.dat" file.
For a better explanation of the structure of the parameters and how you can provided it through the param.dat file, read the documentation inside /doc
