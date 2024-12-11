#include <stdio.h>

// 내적을 계산하는 함수
// 입력: 두 개의 3차원 벡터 a, b
// 출력: 내적의 결과 값
double dot_product(double* a, double* b) 
{
    double dot = 0.0; // 내적 결과를 저장할 변수
    for (int i = 0; i < 3; i++) 
    {
        dot += a[i] * b[i]; // 각 성분의 곱을 누적
    }
    return dot;
}

// 외적을 계산하는 함수
// 입력: 두 개의 3차원 벡터 a, b
// 출력: 외적 결과를 저장할 배열 cross
void cross_product(double* a, double* b, double* cross) 
{
    // 외적의 계산 공식에 따라 각 성분 계산
    cross[0] = a[1] * b[2] - a[2] * b[1];
    cross[1] = a[2] * b[0] - a[0] * b[2];
    cross[2] = a[0] * b[1] - a[1] * b[0];
}

int main() 
{
    double vector1[3], vector2[3]; // 사용자로부터 입력받을 두 개의 벡터
    double dot, cross[3];          // 내적 결과와 외적 결과를 저장할 변수

    // 첫 번째 벡터 입력
    printf("첫 번째 3차원 벡터의 성분을 입력하세요 (예: 1 2 3): ");
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%lf", &vector1[i]); // 각 성분을 입력받아 저장
    }

    // 두 번째 벡터 입력
    printf("두 번째 3차원 벡터의 성분을 입력하세요 (예: 4 5 6): ");
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%lf", &vector2[i]); // 각 성분을 입력받아 저장
    }

    // 내적 계산
    dot = dot_product(vector1, vector2);

    // 외적 계산
    cross_product(vector1, vector2, cross);

    // 결과 출력
    printf("\n첫번째 벡터 : (%.2lf, %.2lf, %.2lf)\n", vector1[0], vector1[1], vector1[2]);
    printf("두번째 벡터 : (%.2lf, %.2lf, %.2lf)\n", vector2[0], vector2[1], vector2[2]);

    printf("\n내적 : %.2lf\n", dot);
    printf("외적 : (%.2lf, %.2lf, %.2lf)\n", cross[0], cross[1], cross[2]);

    return 0;
}