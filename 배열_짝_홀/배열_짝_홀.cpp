#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10  // �Է� �迭 ũ��
#define UnusedValue -1 // ������� ���� �ε��� ǥ�ÿ� ��

// ¦���� Ȧ���� �и��ϴ� �Լ�
void CalcEvenOddArray(int input[], int size, int even[], int odd[], int* evenCount, int* oddCount) 
{
    *evenCount = 0; // ¦�� ���� �ʱ�ȭ
    *oddCount = 0;  // Ȧ�� ���� �ʱ�ȭ

    for (int i = 0; i < size; i++) 
    {
        if (input[i] % 2 == 0) 
        {
            even[*evenCount] = input[i]; // ¦�� �迭�� �߰�
            (*evenCount)++;
        }
        else 
        {
            odd[*oddCount] = input[i]; // Ȧ�� �迭�� �߰�
            (*oddCount)++;
        }
    }

    // ������ �迭 ������ �ʱ�ȭ
    for (int i = *evenCount; i < ArraySize; i++) 
    {
        even[i] = UnusedValue;
    }
    for (int i = *oddCount; i < ArraySize; i++) 
    {
        odd[i] = UnusedValue;
    }
}

// �迭�� ����ϴ� �Լ�
void PrintArray(int array[], int size, const char* message) 
{
    printf("%s:\n", message);
    for (int i = 0; i < size; i++) 
    {
        if (array[i] == UnusedValue) 
        {
            printf("- "); // �ʱ�ȭ�� ���� '-'�� ���
        }
        else {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

int main() 
{
    int inputArray[ArraySize]; // �Է� �迭
    int evenArray[ArraySize]; // ¦�� �迭
    int oddArray[ArraySize];  // Ȧ�� �迭
    int evenCount, oddCount;  // ¦���� Ȧ�� ����

    // ���� ���� �ʱ�ȭ
    srand((unsigned int)time(NULL));

    // �Է� �迭�� ���� �� ���� (0 ~ 100)
    for (int i = 0; i < ArraySize; i++) 
    {
        inputArray[i] = rand() % 101;
    }

    // ���� ������ �迭 ���
    PrintArray(inputArray, ArraySize, "���� ������ �迭");

    // ¦���� Ȧ�� �и�
    CalcEvenOddArray(inputArray, ArraySize, evenArray, oddArray, &evenCount, &oddCount);

    // ��� ���
    PrintArray(evenArray, ArraySize, "¦�� �迭");
    PrintArray(oddArray, ArraySize, "Ȧ�� �迭");

    return 0;
}