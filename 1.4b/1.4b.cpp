#define _USE_MATH_DEFINES
#include "Header1.4b.h"

double Function1(double x)
{
    return pow((x - 1), 3) - 8;
}

double Function2(double x, double s)
{
    return (s * pow(cos(M_PI * x), 2) - pow(x, 0.5));
}

int main()
{
    int up_lim = 0, down_lim = 0;
    double eps = 0;
    int setw = 15;
    double x = 0;
    /*std::cout << "Enter the boundaries of the segment" << std::endl;
    std::cin >> up_lim >> down_lim;
    std::cout << "Enter the margin of error";
    std::cin >> eps;*/
   
    FindRootA(Function1, &x);
   /* std::cout << x << std::endl;
    std::cout << Function1(FindRootA(Function1, &x)) << std::endl;
    std::cout << FindRootA(Function1, &x) << std::endl;*/
    std::cout << std::setw(setw) << "x" << std::setw(setw) << "f(x)" << std::setw(setw) << "k_iter" << std::endl;
    std::cout << std::setw(setw) << x << std::setw(setw) << Function1(x) << std::setw(setw) << FindRootA(Function1, &x) << std::endl;

    std::cout << std::setw(setw) << "s" << std::setw(setw) << "x" << std::setw(setw) << "f(x)" << std::setw(setw) << "k_iter" << std::endl;
    for (double s = 0.95; s <= 1.21; s += 0.05)
    {
        FindRootB(Function2, &x, s);
        std::cout << std::setw(setw) << s << std::setw(setw) << x << std::setw(setw) << Function2(x, s) << std::setw(setw) << FindRootB(Function2, &x, s) << std::endl;
      }


}