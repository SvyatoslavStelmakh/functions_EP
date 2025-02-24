#define _USE_MATH_DEFINES
#include "Header1.4b.h"

double DerivativeA(double x)
{
	return (3 * pow((x - 1), 2));
}

double DerivativeB(double x, double s)
{
	return (-2 * s * cos(M_PI * x) * sin(M_PI * x) * M_PI - (0.5 / pow(x, 0.5)));
}

double SecondDerivativeA(double x)
{
	return (6 * (x - 1));
}

double SecondDerivativeB(double x, double s)
{
	return (2 * s * M_PI * M_PI * pow(sin(M_PI * x), 2) - 2 * s * M_PI * M_PI * pow(cos(M_PI * x), 2));

}

int FindRootA(double (*function)(double), int& k_iter, double up_lim, double down_lim, double eps)
{
	int x0, x;
	k_iter = 0;
	/*if (function(up_lim) * SecondDerivativeA(up_lim) > 0)
		x0 = up_lim;
	else
		x0 = down_lim;*/

	x0 = (up_lim + down_lim) / 2.0;
	while (true)
	{
		x = x0 - (function(x0) / DerivativeA(x0));
		++k_iter;
		if (fabs(x - x0) < eps) 
			break;
		x0 = x;
	}

	return x;
}

int FindRootB(double (*function)(double , double ), int& k_iter, double s, double up_lim, double down_lim, double eps )
{
	int x0, x;
	k_iter = 0;
	/*
	if (function(up_lim, s) * SecondDerivativeB(up_lim, s) > 0)
		x0 = up_lim;
	else
		x0 = down_lim;*/

	x0 = (up_lim + down_lim) / 2.0;

	while (true)
	{
		x = x0 - (function(x0, s) / DerivativeB(x0, s));
		++k_iter;
		if (fabs(x - x0) < eps) 
			break;
		x0 = x;
	}

	return x;
}