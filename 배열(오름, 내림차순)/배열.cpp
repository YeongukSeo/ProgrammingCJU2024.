#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10

// 배열을 정렬하는 함수 (오름차순 또는 내림차순)
void CalcSortArray(float array[], int size, int order)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // 오름차순: order == 1, 내림차순: order == 2
            if ((order == 1 && array[i] > array[j]) || (order == 2 && array[i] < array[j]))
            { 
                /*
                오름차순을 선택했을 때(order = 1) 앞에 있는 수가 뒤에 있는 수보다 클 경우 두 수를 스위치
                내림차순을 선택했을 때(order = 2) 앞에 있는 수가 뒤에 있는 수보다 작을 경우 두 수를 스위치
                */
                float temp = array[i]; 
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// 배열을 출력하는 함수
void PrintArray(float array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%.2f\t", array[i]); // 소수점 2자리까지 출력
    }
    printf("\n");
}

int main() 
{
    float num[10];  // 배열 크기: 10
    int order;     // 정렬 옵션 (1: 오름차순, 2: 내림차순)
    int i_or_f;      // 정수 또는 실수 선택 (1: 정수, 2: 실수)

    // 랜덤 숫자 생성을 위한 초기화
    srand((unsigned int)time(NULL));

    // 정수 또는 실수 배열 선택
    printf("정수를 생성하려면 1, 실수를 생성하려면 2를 입력하세요: ");
    scanf_s("%d", &i_or_f);

    // 배열에 랜덤 값 생성
    printf("랜덤으로 생성된 배열:\n");
    for (int i = 0; i < 10; i++) 
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

    // 생성된 배열 출력
    PrintArray(num, ArraySize);

    // 정렬 방식 선택
    printf("오름차순 정렬은 1, 내림차순 정렬은 2를 입력하세요: ");
    scanf_s("%d", &order);

    // 배열 정렬 수행
    CalcSortArray(num, ArraySize, order);

    // 정렬된 배열 출력
    printf("정렬된 배열:\n");
    PrintArray(num, ArraySize);

    return 0;
}