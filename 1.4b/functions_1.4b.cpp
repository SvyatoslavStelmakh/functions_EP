#define _USE_MATH_DEFINES
#include "Header1.4b.h"

double DerivativeA(double x)
{
	return (3 * pow((x - 1), 2));
}

double DerivativeB(double x, double s)
{
	return (-2*s*cos(M_PI * x)*sin(M_PI * x)* M_PI-(0.5/pow(x, 0.5)));
}

double SecondDerivativeA(double x)
{
	return (6 * (x - 1));
}

double SecondDerivativeB(double x, double s)
{
	return (2 * s * M_PI * M_PI * pow(sin(M_PI * x), 2) - 2 * s * M_PI * M_PI * pow(cos(M_PI * x), 2));
}

int FindRootA(double (*function)(double), double* x, double up_lim, double down_lim, double eps)
{
	int k_iter = 0;
	*x = 0;
	if (function(up_lim) * SecondDerivativeA(up_lim) > 0)
		*x = up_lim;
	else
		*x = down_lim;

	while (eps <= fabs(function(*x)))
	{
		*x = *x - (function(*x) / DerivativeA(*x));
		++k_iter;
	}

	return k_iter;
}

int FindRootB(double (*function)(double , double ), double* x, double s, double up_lim, double down_lim, double eps )
{
	int k_iter = 0;
	*x = 0;
	if (function(up_lim, s) * SecondDerivativeB(up_lim, s) > 0)
		*x = up_lim;
	else
		*x = down_lim;

	while (eps <= fabs(function(*x, s)))
	{
		*x = *x - (function(*x, s) / DerivativeB(*x, s));
		++k_iter;
	}

	return k_iter;
}