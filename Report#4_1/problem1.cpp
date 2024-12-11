#include <stdio.h>

// ������ ����ϴ� �Լ�
// �Է�: �� ���� 3���� ���� a, b
// ���: ������ ��� ��
double dot_product(double* a, double* b) 
{
    double dot = 0.0; // ���� ����� ������ ����
    for (int i = 0; i < 3; i++) 
    {
        dot += a[i] * b[i]; // �� ������ ���� ����
    }
    return dot;
}

// ������ ����ϴ� �Լ�
// �Է�: �� ���� 3���� ���� a, b
// ���: ���� ����� ������ �迭 cross
void cross_product(double* a, double* b, double* cross) 
{
    // ������ ��� ���Ŀ� ���� �� ���� ���
    cross[0] = a[1] * b[2] - a[2] * b[1];
    cross[1] = a[2] * b[0] - a[0] * b[2];
    cross[2] = a[0] * b[1] - a[1] * b[0];
}

int main() 
{
    double vector1[3], vector2[3]; // ����ڷκ��� �Է¹��� �� ���� ����
    double dot, cross[3];          // ���� ����� ���� ����� ������ ����

    // ù ��° ���� �Է�
    printf("ù ��° 3���� ������ ������ �Է��ϼ��� (��: 1 2 3): ");
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%lf", &vector1[i]); // �� ������ �Է¹޾� ����
    }

    // �� ��° ���� �Է�
    printf("�� ��° 3���� ������ ������ �Է��ϼ��� (��: 4 5 6): ");
    for (int i = 0; i < 3; i++) 
    {
        scanf_s("%lf", &vector2[i]); // �� ������ �Է¹޾� ����
    }

    // ���� ���
    dot = dot_product(vector1, vector2);

    // ���� ���
    cross_product(vector1, vector2, cross);

    // ��� ���
    printf("\nù��° ���� : (%.2lf, %.2lf, %.2lf)\n", vector1[0], vector1[1], vector1[2]);
    printf("�ι�° ���� : (%.2lf, %.2lf, %.2lf)\n", vector2[0], vector2[1], vector2[2]);

    printf("\n���� : %.2lf\n", dot);
    printf("���� : (%.2lf, %.2lf, %.2lf)\n", cross[0], cross[1], cross[2]);

    return 0;
}