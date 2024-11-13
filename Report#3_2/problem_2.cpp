#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10

// ������ ���� ���� �Լ�
int generate_random_number(int start, int end) 
{
    return (rand() % (end - start + 1)) + start;
}

int main() {
    int start, end, number;
    int total_sum = 0;
    double mean, variance = 0.0, std_dev;

    
    srand(time(NULL)); // ���� �ʱ�ȭ

   
    // ���� �Է°� �ޱ�
    while (1) 
    {
        printf("���� ���� ���� ����: ");
        scanf_s("%d", &start);
        printf("���� ���� ���� ����: ");
        scanf_s("%d", &end);

        if (start < end) // ������ ��ȿ���� �Ǻ�
        {
            
            break; // ��ȿ�� �����̸� �ݺ��� ����
        }
        else //�׷��� ������ �ٽ� �Է�
        {
            printf("���� ������ ���� �������� �۾ƾ� �մϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }


    // ������ ���� ���� �� ȭ�鿡 ���
    printf("������ ����: ");
    for (int i = 0; i < COUNT; i++) 
    {
       
        number = generate_random_number(start, end); // ������ ���� ���� �Լ� ȣ��

        printf("%d ", number);

        total_sum += number; // ���տ� ���� ���ڸ� �߰�

        variance += number * number; // �л� ����� ���� �κ��� ���ϱ�
    }
    printf("\n");
   
    mean = (double)total_sum / COUNT; // ��� ���
   
    variance = (variance / COUNT) - (mean * mean); // �л� ���

    std_dev = sqrt(variance); // ǥ������ ���

    // ��� ���
    printf("����: %d\n", total_sum);
    printf("���: %.2f\n", mean);
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", std_dev);

    return 0;
}