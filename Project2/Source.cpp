#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

double function(double x) {
    return pow(x - 1, 3) - 8;
}

double dfunction(double x) { //производная функции а)
    return 3 * pow(x - 1, 2);
}

double function2(double x) {
    return cos(M_PI * x) * cos(M_PI * x) - sqrt(x);
}

double dfunction2(double x) { //производная функции б)
    return -2 * M_PI * cos(M_PI * x) * sin(M_PI * x) - 0.5 / sqrt(x);
}

double tangent_method(double (*func)(double), double (*dfunc)(double), double x0, double epsilon, int& k_iter) {
    double x1;
    k_iter = 0;

    while (true) {
        x1 = x0 - func(x0) / dfunc(x0); //x(n+1)= xn - f(xn)/df(xn)
        k_iter++;
        if (fabs(x1 - x0) < epsilon) break;//абсолютное значение разности между текущим и следующим приближением
        x0 = x1;
    }
    return x1;
}

int main() {
    setlocale(LC_ALL, "");
    double a, b, epsilon = 1e-6, x0;
    int k_iter = 0;
    a = 1.0;
    b = 4.0;
    x0 = tangent_method(function, dfunction, (a + b) / 2.0, epsilon, k_iter);
    cout << "Уравнение a) f(x) = (x-1)^3 - 8" << endl;
    cout << "Корень уравнения: " << x0 << endl;
    cout << "Количество итераций: " << k_iter << endl;
    cout << "f(x0) = " << function(x0) << endl;
    cout << endl;

    a = 0.0;
    b = 1.5;
    x0 = tangent_method(function2, dfunction2, (a + b) / 2.0, epsilon, k_iter);
    cout << "Уравнение б) f(x) = scos^2(Пx) - sqrt(x)" << endl;
    cout << "Корень уравнения: " << x0 << endl;
    cout << "Количество итераций: " << k_iter << endl;
    cout << "f(x0) = " << function2(x0) << endl; 
    return 0;
}