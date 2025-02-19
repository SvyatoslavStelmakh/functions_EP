#include "Header1.4b.h"

double Derivative(double (*function)(double), double x)
{
	double h = 1e-5; // Шаг для численного дифференцирования
	return (function(x + h) - function(x - h)) / (2 * h);
}

double Derivative(double (*function)(double x, double s), double x, double s)
{
	double h = 1e-5; // Шаг для численного дифференцирования
	return (function(x + h, s) - function(x - h, s)) / (2 * h);
}

double SecondDerivative(double (*function)(double), double x)
{
	double h = 1e-5; // Шаг для численного дифференцирования
	return (function(x + h) - 2 * function(x) + function(x - h)) / (h * h);
}

double SecondDerivative(double (*function)(double x, double s), double x, double s)
{
	double h = 1e-5; // Шаг для численного дифференцирования
	return (function(x + h, s) - 2 * function(x, s) + function(x - h, s)) / (h * h);
}

int FindRootA(double (*function)(double), double* x, double up_lim, double down_lim, double eps)
{
	int k_iter = 0;
	*x = 0;
	if (function(up_lim) * SecondDerivative(function, up_lim) > 0)
		*x = up_lim;
	else
		*x = down_lim;

	while (eps < fabs(function(*x) / Derivative(function, *x)))
	{
		*x = *x - (function(*x) / Derivative(function, *x));
		++k_iter;
	}

	return k_iter;
}

int FindRootB(double (*function)(double , double ), double* x, double s, double up_lim, double down_lim, double eps )
{
	int k_iter = 0;
	*x = 0;
	if (function(up_lim, s) * SecondDerivative(function, up_lim, s) > 0)
		*x = up_lim;
	else
		*x = down_lim;

	while (eps < fabs(function(*x, s) / Derivative(function, *x, s)))
	{
		*x = *x - (function(*x, s) / Derivative(function, *x, s));
		++k_iter;
	}

	return k_iter;
}