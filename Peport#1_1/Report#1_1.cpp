#include <stdio.h>

int main()
{
	double angle = 0.0; // �Ǽ� ���� ����
	int a = 0; // ���� ���� ����

	printf("������ �Է��Ͻÿ� : ");

	scanf_s("%lf", &angle); // ���� �Է�


	angle = angle + 180; //���� ���
	a = angle / 360; // ������ 360[deg]�� �Ѿ ��� 360[deg] �̳��� ������� ���� ���
	angle = angle - 360 * a; //�տ��� ����� ������ ���� a�� �̿��Ͽ� ���� ���
	angle = angle - 180; 
	
	printf("��ȯ�� ������ %0.1lf[deg] �Դϴ�.\n\n", angle); // ����� ���� ���
	
	return 0;
}