#include <stdio.h>

int main()
{
	double a, b, c, d = 0;
	double m, slug = 0;
	c = 0.3048;
	d = 0.068526;


	printf("�� �Է��ϼ���.(ft, kg) : ");
	scanf_s("%lf %lf", &a, &b);

	m = a * 0.3048;
	slug = b * 0.068526;

	printf("%0.1lfft�� %0.1lfm\t%0.1lfkg�� %0.2lfslug �Դϴ�.", a, m, b, slug);

	return 0;
}