#include <stdio.h>

int main()
{
	double angle = 0.0;
	int a = 0;

	printf("������ �Է��Ͻÿ� : ");

	scanf_s("%lf", &angle);


	angle = angle + 180;
	a = angle / 360;
	angle = angle - 360 * a;
	angle = angle - 180;
	
	printf("��ȯ�� ������ %0.1lf[deg] �Դϴ�.\n\n", angle);
	
	return 0;
}