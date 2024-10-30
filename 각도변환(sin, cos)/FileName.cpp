#include <stdio.h>
#include <math.h>


double sin_change(double x);
double cos_change(double x);

int main() 
{
    double angle = 0.0;
    double sinResult, cosResult;
   

    printf("������ �Է��ϼ��� (����: ��): ");
    scanf_s("%lf", &angle);

    sinResult = sin_change(angle); //sin ��ȯ�� ��ȯ
    cosResult = cos_change(angle); //cos ��ȯ�� ��ȯ

    printf("sin(%.1f��) = %.6f\n", angle, sinResult);
    printf("cos(%.1f��) = %.6f\n", angle, cosResult);

    return 0;
}

double sin_change(double x) 
{
    double pi = 3.141592;
    double radian = x * pi / 180.0; // ������ �������� ��ȯ
    return sin(radian); // sin �Լ� ���
}

double cos_change(double x) 
{
    double pi = 3.141592;
    double radian = x * pi / 180.0; // ������ �������� ��ȯ
    return cos(radian); // cos �Լ� ���
}