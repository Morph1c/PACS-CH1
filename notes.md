The definition of function and class templates go in a header file, not in the source file.

The reason is the a function template is NOT a function but the
template of a function. Te actual function is created by the compiler
at the meoment of the instance, i.e. when the actual tempalte
arguments are set.


You should have added an example of file parameter.dat in the directory test, to allow testing the different options.
