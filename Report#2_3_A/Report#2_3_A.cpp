#include <stdio.h>

int main()
{
	float num1 = 0.0; //실수형 변수 지정 및 초기화

	printf("성적을 입력하시오(0.0-100.0 범위의 실수) : ");
	scanf_s("%f", &num1); //성적 입력

	//if문을 사용해 10씩 범위를 지정해 학점을 부여
	if (num1 >= 90.0)
	{
		printf("A학점입니다.\n\n");
	}
	else if (num1 >= 80.0)
	{
		printf("B학점입니다.\n\n");
	}
	else if (num1 >= 70.0)
	{
		printf("C학점입니다.\n\n");
	}
	else if (num1 >= 60.0)
	{
		printf("D학점입니다.\n\n");
	}
	else if (num1 >= 50.0)
	{
		printf("E학점입니다.\n\n");
	}
	else
	{
		printf("F학점입니다.\n\n");
	}

	return 0;
}