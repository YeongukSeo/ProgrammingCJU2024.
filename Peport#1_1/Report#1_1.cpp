#include <stdio.h>

int main()
{
	double angle = 0.0;
	int a = 0;

	printf("각도를 입력하시오 : ");

	scanf_s("%lf", &angle);


	angle = angle + 180;
	a = angle / 360;
	angle = angle - 360 * a;
	angle = angle - 180;
	
	printf("변환된 각도는 %0.1lf[deg] 입니다.\n\n", angle);
	
	return 0;
}