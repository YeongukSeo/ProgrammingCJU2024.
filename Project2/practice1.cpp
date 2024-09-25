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

	printf("길이를 입력하시오(삼각형 가로, 삼각형 세로, 사각형 가로, 사각형 세로, 원 반지름 , 구 반지름):" );

	scanf_s("%lf %lf %lf %lf %lf %lf", &tri_x, &tri_y, &rec_x, &rec_y, &cir, &sph);

	triR = tri_x * tri_y / 2;
	recR = rec_x * rec_y;
	cirR = pi * cir * cir;
	sphSR = b * pi * sph *sph;
	sphVR = d * pi * sph * sph * sph;

	printf("삼각형 넓이 : %lf, 사각형 넓이 : %lf, 원의 넓이 : %lf, 구의 표면적 : %lf, 구의 체적 : %lf", triR, recR, cirR, sphSR, sphVR);

	return 0;
}