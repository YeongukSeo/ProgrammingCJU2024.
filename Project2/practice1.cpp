#include <stdio.h>

int main(void)
{
	double tri_x,tri_y, rec_x, rec_y, cir, sph = 0;
	double triR, recR, cirR, sphSR, sphVR = 0;
	double pi, a, d = 0;
	int b, c;

	pi = 3.14;
	a = 0.5;
	b = 4;
	c = 2;
	d = 1.333333;

	printf("���̸� �Է��Ͻÿ�(�ﰢ�� ����, �ﰢ�� ����, �簢�� ����, �簢�� ����, �� ������ , �� ������):" );

	scanf_s("%lf %lf %lf %lf %lf %lf", &tri_x, &tri_y, &rec_x, &rec_y, &cir, &sph);

	triR = tri_x * tri_y / 2;
	recR = rec_x * rec_y;
	cirR = pi * cir * cir;
	sphSR = b * pi * sph *sph;
	sphVR = d * pi * sph * sph * sph;

	printf("�ﰢ�� ���� : %lf, �簢�� ���� : %lf, ���� ���� : %lf, ���� ǥ���� : %lf, ���� ü�� : %lf", triR, recR, cirR, sphSR, sphVR);

	return 0;
}