#define _USE_MATH_DEFINES
#include "Header1.4b.h"

double Function1(double x)
{
    return pow((x - 1), 3) - 8;
}

double Function2(double x, double s)
{
    return (s * pow(cos(M_PI * x), 2) - sqrt(x));
}

int main()
{
    int up_lim = 1.5, down_lim = 0;
    double eps = 1e-6;
    int setw = 15;
    int k_iter = 0;
    /*std::cout << "Enter the boundaries of the segment" << std::endl;
    std::cin >> up_lim >> down_lim;
    std::cout << "Enter the margin of error";
    std::cin >> eps;*/
   
    /* std::cout << x << std::endl;
    std::cout << Function1(FindRootA(Function1, &x)) << std::endl;
    std::cout << FindRootA(Function1, &x) << std::endl;*/
    std::cout << std::setw(setw) << "x" << std::setw(setw) << "f(x)" << std::setw(setw) << "k_iter" << std::endl;
    std::cout << std::setw(setw) << FindRootA(Function1, k_iter, up_lim, down_lim, eps) << std::setw(setw) << Function1(FindRootA(Function1, k_iter, up_lim, down_lim, eps)) << std::setw(setw) << k_iter << std::endl;

    std::cout << std::setw(setw) << "s" << std::setw(setw) << "x" << std::setw(setw) << "f(x)" << std::setw(setw) << "k_iter" << std::endl;
    for (double s = 0.95; s <= 1.21; s += 0.05)
    {
        std::cout << std::setw(setw) << s << std::setw(setw) << FindRootB(Function2, k_iter, s, up_lim, down_lim, eps) << std::setw(setw) << Function2(FindRootB(Function2, k_iter, s, up_lim, down_lim, eps), s) << std::setw(setw) << k_iter << std::endl;
    }
}