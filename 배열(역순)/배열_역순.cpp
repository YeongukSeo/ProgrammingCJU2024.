#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10

// 배열을 역순으로 변환하는 함수
void CalcInverseArray(float array[], int size) 
{
    for (int i = 0; i < size / 2; i++) //배열크기(10)의 절반만큼의 횟수만 실행하면 되므로 size/2로 설정 
    {
        // 앞과 뒤 값을 교환
        float temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

// 배열 출력 함수
void PrintArray(float array[], int size, const char* message) 
{
    printf("%s:\n", message);
    for (int i = 0; i < size; i++) 
    {
        printf("%.2f ", array[i]); // 소수점 두 자리 출력
    }
    printf("\n");
}

int main() {
    float num[ArraySize]; // 배열 선언
    int i_or_f;            // 정수 또는 실수 선택 (1: 정수, 2: 실수)

    // 랜덤 초기화
    srand((unsigned int)time(NULL));

    // 정수 또는 실수 배열 선택
    printf("정수를 생성하려면 1, 실수를 생성하려면 2를 입력하세요: ");
    scanf_s("%d", &i_or_f);

    // 배열에 랜덤 값 생성
    for (int i = 0; i < ArraySize; i++) 
    {
        if (i_or_f == 1)
        {
            // 정수 생성: -100 ~ 100
            num[i] = (rand() % 201) - 100;
        }
        else 
        {
            // 실수 생성: -100.0 ~ 100.0
            num[i] = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
        }
    }

    // 랜덤 생성된 배열 출력
    PrintArray(num, ArraySize, "랜덤 생성된 배열");

    // 배열을 역순으로 변환
    CalcInverseArray(num, ArraySize);

    // 역순 배열 출력
    PrintArray(num, ArraySize, "역순으로 변환된 배열");

    return 0;
}