#include <stdio.h>
#include <math.h>


double sin_change(double x);
double cos_change(double x);

int main() 
{
    double angle = 0.0;
    double sinResult, cosResult;
   

    printf("각도를 입력하세요 (단위: 도): ");
    scanf_s("%lf", &angle);

    sinResult = sin_change(angle); //sin 변환값 반환
    cosResult = cos_change(angle); //cos 변환값 반환

    printf("sin(%.1f°) = %.6f\n", angle, sinResult);
    printf("cos(%.1f°) = %.6f\n", angle, cosResult);

    return 0;
}

double sin_change(double x) 
{
    double pi = 3.141592;
    double radian = x * pi / 180.0; // 각도를 라디안으로 변환
    return sin(radian); // sin 함수 사용
}

double cos_change(double x) 
{
    double pi = 3.141592;
    double radian = x * pi / 180.0; // 각도를 라디안으로 변환
    return cos(radian); // cos 함수 사용
}