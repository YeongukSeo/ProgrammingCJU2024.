#include <stdio.h>

int main()
{
	int num1 = 0; //정수형 변수 설정 및 초기화
	
	printf("한 개의 정수를 입력하시오 : ");
	scanf_s("%d", &num1);

	if (num1 % 2 == 0) //입력받은 정수형 변수를 2로 나눈뒤 나머지가 0이면, 즉 짝수인지를 판별
	{
		printf("짝수입니다."); //참이면 "짝수입니다"를 출력
	}
	else
	{
		printf("홀수입니다."); //거짓이면 "홀수입니다"를 출력
	}

	return 0;
}