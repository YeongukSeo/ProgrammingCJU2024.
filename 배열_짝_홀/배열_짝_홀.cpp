#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10  // 입력 배열 크기
#define UnusedValue -1 // 사용하지 않은 인덱스 표시용 값

// 짝수와 홀수를 분리하는 함수
void CalcEvenOddArray(int input[], int size, int even[], int odd[], int* evenCount, int* oddCount) 
{
    *evenCount = 0; // 짝수 개수 초기화
    *oddCount = 0;  // 홀수 개수 초기화

    for (int i = 0; i < size; i++) 
    {
        if (input[i] % 2 == 0) 
        {
            even[*evenCount] = input[i]; // 짝수 배열에 추가
            (*evenCount)++;
        }
        else 
        {
            odd[*oddCount] = input[i]; // 홀수 배열에 추가
            (*oddCount)++;
        }
    }

    // 나머지 배열 공간을 초기화
    for (int i = *evenCount; i < ArraySize; i++) 
    {
        even[i] = UnusedValue;
    }
    for (int i = *oddCount; i < ArraySize; i++) 
    {
        odd[i] = UnusedValue;
    }
}

// 배열을 출력하는 함수
void PrintArray(int array[], int size, const char* message) 
{
    printf("%s:\n", message);
    for (int i = 0; i < size; i++) 
    {
        if (array[i] == UnusedValue) 
        {
            printf("- "); // 초기화된 값은 '-'로 출력
        }
        else {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

int main() 
{
    int inputArray[ArraySize]; // 입력 배열
    int evenArray[ArraySize]; // 짝수 배열
    int oddArray[ArraySize];  // 홀수 배열
    int evenCount, oddCount;  // 짝수와 홀수 개수

    // 랜덤 생성 초기화
    srand((unsigned int)time(NULL));

    // 입력 배열에 랜덤 값 생성 (0 ~ 100)
    for (int i = 0; i < ArraySize; i++) 
    {
        inputArray[i] = rand() % 101;
    }

    // 랜덤 생성된 배열 출력
    PrintArray(inputArray, ArraySize, "랜덤 생성된 배열");

    // 짝수와 홀수 분리
    CalcEvenOddArray(inputArray, ArraySize, evenArray, oddArray, &evenCount, &oddCount);

    // 결과 출력
    PrintArray(evenArray, ArraySize, "짝수 배열");
    PrintArray(oddArray, ArraySize, "홀수 배열");

    return 0;
}