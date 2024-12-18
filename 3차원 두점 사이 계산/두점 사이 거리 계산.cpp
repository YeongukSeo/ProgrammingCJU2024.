#include <stdio.h>
#include <math.h>

// 3���� ���� ��Ÿ���� ����ü ����
struct Point_3D 
{
    double x;
    double y;
    double z;
};

// ��Ŭ���� �Ÿ��� ����ϴ� �Լ�
double euclidean_distance(struct Point_3D* p1, struct Point_3D* p2) 
{
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() 
{
    // �� ���� ������ ����ü ���� ����
    struct Point_3D point1, point2;

    // ����ڷκ��� ù ��° ���� ��ǥ �Է� �ޱ�
    printf("ù ��° ���� ��ǥ�� �Է��ϼ��� (x y z): ");
    if (scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z) != 3) 
    {
        printf("�߸��� �Է��Դϴ�.\n");
        return 1;
    }

    // ����ڷκ��� �� ��° ���� ��ǥ �Է� �ޱ�
    printf("�� ��° ���� ��ǥ�� �Է��ϼ��� (x y z): ");
    if (scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z) != 3) 
    {
        printf("�߸��� �Է��Դϴ�.\n");
        return 1;
    }

    // ��Ŭ���� �Ÿ� ���
    double distance = euclidean_distance(&point1, &point2);

    // ��� ���
    printf("�� �� ������ ��Ŭ���� �Ÿ�: %.4lf\n", distance);

    return 0;
}