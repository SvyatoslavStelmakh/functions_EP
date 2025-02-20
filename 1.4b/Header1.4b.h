#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

//double Function(double x);
double DerivativeA(double x);
double DerivativeB(double x, double s);
double SecondDerivativeA(double x);
double SecondDerivativeB(double x, double s);
int FindRootA(double (*function)(double), double* x, double up_lim = 4, double down_lim = 1, double eps = 1e-6);
int FindRootB(double (*function)(double , double ), double* x, double s, double up_lim = 2, double down_lim = 1, double eps = 1e-6);

