#include <stdio.h>

int main()
{
    float num1 = 0.0; //�Ǽ��� ���� ���� �� �ʱ�ȭ
    int a; //switch���� ����ϱ� ���� ������ ���� ���� �� �ʱ�ȭ

    printf("������ �Է��Ͻÿ�(0.0-100.0 ������ �Ǽ�) : ");
    scanf_s("%f", &num1); //���� �Է�

    
    a = num1 / 10; // 10���� ������ �Ҽ����� ������ ���� ���������� ����

    switch (a)
    {
    case 10: // 100��
    case 9:  // 90~99��
        printf("A�����Դϴ�.\n\n");
        break;
    case 8:  // 80~89��
        printf("B�����Դϴ�.\n\n");
        break;
    case 7:  // 70~79��
        printf("C�����Դϴ�.\n\n");
        break;
    case 6:  // 60~69��
        printf("D�����Դϴ�.\n\n");
        break;
    case 5:  // 50~59��
        printf("E�����Դϴ�.\n\n");
        break;
    default: // 0~49��
        printf("F�����Դϴ�.\n\n");
        break;
    }

    return 0;
}