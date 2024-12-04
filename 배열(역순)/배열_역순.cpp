#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10

// �迭�� �������� ��ȯ�ϴ� �Լ�
void CalcInverseArray(float array[], int size) 
{
    for (int i = 0; i < size / 2; i++) //�迭ũ��(10)�� ���ݸ�ŭ�� Ƚ���� �����ϸ� �ǹǷ� size/2�� ���� 
    {
        // �հ� �� ���� ��ȯ
        float temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

// �迭 ��� �Լ�
void PrintArray(float array[], int size, const char* message) 
{
    printf("%s:\n", message);
    for (int i = 0; i < size; i++) 
    {
        printf("%.2f ", array[i]); // �Ҽ��� �� �ڸ� ���
    }
    printf("\n");
}

int main() {
    float num[ArraySize]; // �迭 ����
    int i_or_f;            // ���� �Ǵ� �Ǽ� ���� (1: ����, 2: �Ǽ�)

    // ���� �ʱ�ȭ
    srand((unsigned int)time(NULL));

    // ���� �Ǵ� �Ǽ� �迭 ����
    printf("������ �����Ϸ��� 1, �Ǽ��� �����Ϸ��� 2�� �Է��ϼ���: ");
    scanf_s("%d", &i_or_f);

    // �迭�� ���� �� ����
    for (int i = 0; i < ArraySize; i++) 
    {
        if (i_or_f == 1)
        {
            // ���� ����: -100 ~ 100
            num[i] = (rand() % 201) - 100;
        }
        else 
        {
            // �Ǽ� ����: -100.0 ~ 100.0
            num[i] = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
        }
    }

    // ���� ������ �迭 ���
    PrintArray(num, ArraySize, "���� ������ �迭");

    // �迭�� �������� ��ȯ
    CalcInverseArray(num, ArraySize);

    // ���� �迭 ���
    PrintArray(num, ArraySize, "�������� ��ȯ�� �迭");

    return 0;
}