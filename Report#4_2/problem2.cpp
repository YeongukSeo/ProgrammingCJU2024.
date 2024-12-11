#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ������ ������ �����Ͽ� �迭�� �����ϴ� �Լ�
void generate_random_numbers(int* array, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min; // ������ ���� ����
    }
}

// ������ ���� ������ ������ �����ϴ� �Լ�
// ���� �迭(numbers), ���� �迭 ũ��(numbers_size), ����� ������ ������ �迭(new_array), ���尡���� �ִ� ũ��(new_array_size), ���� ����(range_min, range_max)
// numbers �迭���� range_min�� range_max ������ �ش��ϴ� ������ �ִ� new_array_size��ŭ �����Ͽ� new_array �迭�� ����
int extract_numbers(int* numbers, int numbers_size, int* new_array, int new_array_size, int range_min, int range_max)
{
    int count = 0; // ����� ���� ���� �ʱ�ȭ
    for (int i = 0; i < numbers_size && count < new_array_size; i++)
    {
        if (numbers[i] >= range_min && numbers[i] <= range_max) // ���� �˻�
        {
            new_array[count++] = numbers[i]; // ����� ������ ��� �迭�� ����
        }
    }
    return count; // ����� ���� ���� ��ȯ
}

// �迭�� ������ ����ϴ� �Լ�
// ���� �迭(array), �迭 ũ��(size)
double calculate_sum(int* array, int size)
{
    double sum = 0.0; // ���� �ʱ�ȭ
    for (int i = 0; i < size; i++)
    {
        sum += array[i]; // �� ���Ҹ� ���տ� ����
    }
    return sum; // ���� ��ȯ
}

// �迭�� �л��� ����ϴ� �Լ�
// ���� �迭(array), �迭 ũ��(size), �迭�� ���(mean)
double calculate_variance(int* array, int size, double mean)
{
    double variance = 0.0; // �л� �ʱ�ȭ
    for (int i = 0; i < size; i++)
    {
        variance += pow(array[i] - mean, 2); // (�� - ���)^2�� ����
    }
    return variance / size; // �л� ��ȯ
}

// �迭�� ǥ�������� ����ϴ� �Լ�
// �л�(variance)
double calculate_standard_deviation(double variance)
{
    return sqrt(variance); // ǥ�������� �л��� ������
}

int main()
{
    int numbers[100]; // 100���� ������ ������ ������ �迭
    int extracted[10]; // ����� ������ ������ �迭 (�ִ� 10��)
    int range_min, range_max; // ����� �Է����� ���� ���� ����
    int extracted_count; // ������ ����� ���� ����
    double sum, variance, std_deviation; // ����, �л�, ǥ�������� ������ ����

    // ������ �� ������ ���� �õ� ����
    srand(time(0));

    // [1, 100] ������ ������ ������ 100�� ����
    generate_random_numbers(numbers, 100, 1, 100);

    // ������ 100���� ������ ���
    printf("������ 100���� ����:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", numbers[i]);
        if ((i + 1) % 10 == 0) printf("\n"); // �������� ���� ������ 10���� ��� ���
    }

    // ����ڷκ��� ������ ������ ���� �Է�
    printf("\n������ ������ ������ �Է��ϼ���.\n");
    printf("�ּҰ�: ");
    scanf_s("%d", &range_min); // �ּҰ� �Է�
    printf("�ִ밪: ");
    scanf_s("%d", &range_max); // �ִ밪 �Է�

    // ��ȿ�� �˻� : �ּҰ��� �ִ밪���� ũ�� ���� �޽��� ��� �� ���α׷� ����
    if (range_min > range_max)
    {
        printf("����: �ּҰ��� �ִ밪���� Ů�ϴ�.\n");
        return 1; // ������ ����
    }

    // ������ ���� ������ �ִ� 10���� ������ ����
    extracted_count = extract_numbers(numbers, 100, extracted, 10, range_min, range_max);

    // ����� ������ ���� ��� �޽��� ��� �� ����
    if (extracted_count == 0)
    {
        printf("������ ���� ���� �ش��ϴ� ������ �����ϴ�.\n");
        return 0; // ���� ����
    }

    // ����� ���� ���
    printf("\n����� %d���� ����:\n", extracted_count);
    for (int i = 0; i < extracted_count; i++)
    {
        printf("%d ", extracted[i]);
    }
    printf("\n");

    // ���� ���
    sum = calculate_sum(extracted, extracted_count);
    printf("����: %.2lf\n", sum);

    // �л� ���
    variance = calculate_variance(extracted, extracted_count, sum / extracted_count);
    printf("�л�: %.2lf\n", variance);

    // ǥ������ ���
    std_deviation = calculate_standard_deviation(variance);
    printf("ǥ������: %.2lf\n", std_deviation);

    return 0;
}



