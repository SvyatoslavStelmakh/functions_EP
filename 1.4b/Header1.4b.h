#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

//double Function(double x);
double DerivativeA(double x);
double DerivativeB(double x, double s);
double SecondDerivativeA(double x);
double SecondDerivativeB(double x, double s);
double FindRootA(double (*function)(double), int& k_iter, double up_lim, double down_lim, double eps);
double FindRootB(double (*function)(double, double), int& k_iter, double s, double up_lim, double down_lim, double eps);