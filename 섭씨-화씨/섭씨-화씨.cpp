#include <stdio.h>


float cel_to_fa(float celsius); // ������ ȭ���� ��ȯ�ϴ� �Լ�
float fa_to_cel(float fahrenheit); // ȭ���� ������ ��ȯ�ϴ� �Լ�


int main() 
{
    int choice;
    float temp, result_temp;
    printf("��ȣ '1' : ���� -> ȭ��\n");
    printf("��ȣ '2' : ȭ�� -> ����\n");
    printf("����ϴ� ��ȯ�� �����ϰ� �µ��� �Է��Ͻÿ�. (��: 1 100)\n");
    printf("�Է�: ");

    scanf_s("%d %f", &choice, &temp);

    if (choice == 1) //1���� ����(������ ȭ���� ��ȯ)
    {
        result_temp = cel_to_fa(temp); // ������ ��ȯ
        printf("ȭ�� �µ�: %.2fF\n", result_temp);
    }
    else if (choice == 2) //2�� ����(ȭ���� ������ ��ȯ)
    {
        result_temp = fa_to_cel(temp); // ȭ���� ��ȯ
        printf("���� �µ�: %.2fC\n", result_temp);
    }
    else 
    {
        printf("�߸��� �����Դϴ�.\n"); //1�� 2�̿��� �� �Է�
    }

    return 0;
}

float cel_to_fa(float celsius) //�Է¹��� ���� �µ��� ȭ���� ��ȯ
{
    float result1;

    result1 = (celsius * 9 / 5) + 32;

    return result1;
}

float fa_to_cel(float fahrenheit) //�Է¹��� ȭ�� �µ��� ������ ��ȯ
{
    float result2;

    result2 = (fahrenheit - 32) * 5 / 9;


    return result2;
}