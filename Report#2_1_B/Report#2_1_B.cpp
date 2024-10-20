#include <stdio.h>

int main()
{
	int num1 = 0, a = 0; //입력받는 정수와 switch문에서 사용할 정수를 지정 및 초기화

	printf("한 개의 정수를 입력하시오 : ");
	scanf_s("%d", &num1);

	a = num1 % 2; //입력받은 정수를 2로 나눈뒤 생긴 나머지를 a에 넣는다.

	switch (a)
	{
	case 0: //만약 a가 0일경우
		printf("짝수입니다."); // 즉 입력받은 정수가 짝수일경우 "짝수입니다." 출력
		break; //case 하나가 끝나면 끝내기


	default: //0이 아닌 경우
		printf("홀수입니다."); // 홀수인 경우에는 "홀수입니다."출력
		
		
	}

	return 0;
}