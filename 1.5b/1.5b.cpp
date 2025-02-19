#include "Header1.5b.h"

double Function(double x, double s, double t)
{
	return (((1 + pow(x, t) + pow(x, 2)) / pow((x, 3), 0.5)) * (1 - sin(s * x)));
}

int main()
{
	double a, b, eps;
	double Integral = 0;
	int setw = 15, k_iter = 0;

	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	std::cout << "Enter the accuracy: ";
	std::cin >> eps;

	std::cout << std::setw(setw) << "s" << std::setw(setw) << "t" << std::setw(setw) << "Integral" << std::setw(setw) << "k_iter" << std::endl;
	for (double s = 0; s <= 0.5; s += 0.1)
	{
		for (double t = 0.5; t <= 2.5; t += 0.5)
		{
			CalculateIntegral(Function, Integral, a, b, s, t, eps, k_iter);
			std::cout << std::setw(setw) << s << std::setw(setw) << t << std::setw(setw) << Integral << std::setw(setw) << k_iter << std::endl;
		}
	}
}