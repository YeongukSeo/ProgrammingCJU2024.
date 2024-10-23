#include <stdio.h>

int main() 
{
	int num1, num2, gcd, lcm, a, b, memo;

	printf("임의의 두 정수를 입력하시오. : ");
	scanf_s("%d %d", &num1, &num2);

	a = num1; //첫번째 입력받은 수를 a에 저장
	b = num2; //두번째 입력받은 수를 b에 저장


	while (b != 0) // 유클리드 호제법 사용하여 최대공약수 계산, b가 0이 될때까지 반복
	{
		memo = a % b; //memo는 a와 b값을 잠시 이동시키기위한 변수
		a = b;
		b = memo;

	}

	gcd = a; //최대공약수 계산
	lcm = (num1 * num2) / gcd; //계산한 최대공약수와 입력한 두 수를 이용하여 최소공배수 계산

	printf("최대공약수 : %d\n", gcd);
	printf("최소공약수 : %d\n", lcm);


	return 0;

}