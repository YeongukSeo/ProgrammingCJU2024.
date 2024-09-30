#include <stdio.h>

int main()
{
	double angle = 0.0; // 실수 변수 선언
	int a = 0; // 정수 변수 선언

	printf("각도를 입력하시오 : ");

	scanf_s("%lf", &angle); // 각도 입력


	angle = angle + 180; //각도 계산
	a = angle / 360; // 각도가 360[deg]를 넘어갈 경우 360[deg] 이내로 끌어오기 위한 계산
	angle = angle - 360 * a; //앞에서 계산한 정수형 변수 a를 이용하여 각도 계산
	angle = angle - 180; 
	
	printf("변환된 각도는 %0.1lf[deg] 입니다.\n\n", angle); // 계산한 각도 출력
	
	return 0;
}