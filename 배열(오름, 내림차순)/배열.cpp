#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ArraySize 10

// �迭�� �����ϴ� �Լ� (�������� �Ǵ� ��������)
void CalcSortArray(float array[], int size, int order)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // ��������: order == 1, ��������: order == 2
            if ((order == 1 && array[i] > array[j]) || (order == 2 && array[i] < array[j]))
            { 
                /*
                ���������� �������� ��(order = 1) �տ� �ִ� ���� �ڿ� �ִ� ������ Ŭ ��� �� ���� ����ġ
                ���������� �������� ��(order = 2) �տ� �ִ� ���� �ڿ� �ִ� ������ ���� ��� �� ���� ����ġ
                */
                float temp = array[i]; 
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// �迭�� ����ϴ� �Լ�
void PrintArray(float array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%.2f\t", array[i]); // �Ҽ��� 2�ڸ����� ���
    }
    printf("\n");
}

int main() 
{
    float num[10];  // �迭 ũ��: 10
    int order;     // ���� �ɼ� (1: ��������, 2: ��������)
    int i_or_f;      // ���� �Ǵ� �Ǽ� ���� (1: ����, 2: �Ǽ�)

    // ���� ���� ������ ���� �ʱ�ȭ
    srand((unsigned int)time(NULL));

    // ���� �Ǵ� �Ǽ� �迭 ����
    printf("������ �����Ϸ��� 1, �Ǽ��� �����Ϸ��� 2�� �Է��ϼ���: ");
    scanf_s("%d", &i_or_f);

    // �迭�� ���� �� ����
    printf("�������� ������ �迭:\n");
    for (int i = 0; i < 10; i++) 
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

    // ������ �迭 ���
    PrintArray(num, ArraySize);

    // ���� ��� ����
    printf("�������� ������ 1, �������� ������ 2�� �Է��ϼ���: ");
    scanf_s("%d", &order);

    // �迭 ���� ����
    CalcSortArray(num, ArraySize, order);

    // ���ĵ� �迭 ���
    printf("���ĵ� �迭:\n");
    PrintArray(num, ArraySize);

    return 0;
}