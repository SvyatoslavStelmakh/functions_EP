#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

void Sum(double a, double b, double h, double s, double t, double (*function) (double, double, double), double& S);
void CalculateIntegral(double (*function)(double, double, double), double& Integral, double a, double b, double s, double t, double eps, int& k_iter);