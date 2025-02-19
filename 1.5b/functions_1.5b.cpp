#include "Header1.5b.h"

void Sum(double a, double b, double h, double s, double t, double (*function) (double, double, double), double& S)
{
    double x, sum;
    x = a;
    sum = 0;
    while (x <= b)
    {
        sum += (*function)(x + h/2, s, t); //накопление суммы высот 
        x += h;
    }
    //вычисление площади 
    S = h * sum;
}

void CalculateIntegral(double (*function)(double, double, double), double& Integral, double a, double b, double s, double t, double eps, int &k_iter)
{
    int n = 4;                  //инициализация  количества разбиений 
     
    double h = (b - a) / n;     //определение шага интегрирования
    
    double S1 = 0, S2 = 0;      //переменные для значений сумм с шагом h и с шагом h/2 

    // вызов функции Sum c шагом h: в S1 возвращается сумма
    Sum(a, b, h, s, t, function, S1);
    k_iter = 0;     //обнуление счётчика количества итераций
    // запуск процесса двойного пересчета 
    do
    {      // сохраняем значение интеграла предыдущего шага 
        S2 = S1;
        n *= 2; //увеличение количества отрезков разбиения и уменьшение шага интегрирования в 2 раза 
        h = (b - a) / n;
        //вызов функции Sum с шагом h = h/2 
        Sum(a, b, h, s, t, function, S1);
        k_iter++;
    } while (fabs(S1 - S2) > eps);
    Integral = S1;
}