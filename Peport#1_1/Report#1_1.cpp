#include <stdio.h>

int main()
{
	double angle = 0.0;

	printf("������ �Է��Ͻÿ� : ");

	scanf_s("%lf", &angle);

	angle = angle + 180;
	angle = angle - 360 * ((int)(angle / 360));
	angle = angle - 180;
	
	printf("��ȯ�� ������ %0.1lf[deg] �Դϴ�.\n\n", angle);
	
	return 0;
}