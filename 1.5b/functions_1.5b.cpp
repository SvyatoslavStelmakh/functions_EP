#include "Header1.5b.h"

void Sum(double a, double b, double h, double s, double t, double (*function) (double, double, double), double& S)
{
    double x, sum;
    x = a;
    sum = 0;
    while (x <= b)
    {
        sum += (*function)(x + h/2, s, t); //���������� ����� ����� 
        x += h;
    }
    //���������� ������� 
    S = h * sum;
}

void CalculateIntegral(double (*function)(double, double, double), double& Integral, double a, double b, double s, double t, double eps, int &k_iter)
{
    int n = 4;                  //�������������  ���������� ��������� 
     
    double h = (b - a) / n;     //����������� ���� ��������������
    
    double S1 = 0, S2 = 0;      //���������� ��� �������� ���� � ����� h � � ����� h/2 

    // ����� ������� Sum c ����� h: � S1 ������������ �����
    Sum(a, b, h, s, t, function, S1);
    k_iter = 0;     //��������� �������� ���������� ��������
    // ������ �������� �������� ��������� 
    do
    {      // ��������� �������� ��������� ����������� ���� 
        S2 = S1;
        n *= 2; //���������� ���������� �������� ��������� � ���������� ���� �������������� � 2 ���� 
        h = (b - a) / n;
        //����� ������� Sum � ����� h = h/2 
        Sum(a, b, h, s, t, function, S1);
        k_iter++;
    } while (fabs(S1 - S2) > eps);
    Integral = S1;
}