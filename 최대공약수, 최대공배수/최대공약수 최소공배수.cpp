#include <stdio.h>

int main() 
{
	int num1, num2, gcd, lcm, a, b, memo;

	printf("������ �� ������ �Է��Ͻÿ�. : ");
	scanf_s("%d %d", &num1, &num2);

	a = num1; //ù��° �Է¹��� ���� a�� ����
	b = num2; //�ι�° �Է¹��� ���� b�� ����


	while (b != 0) // ��Ŭ���� ȣ���� ����Ͽ� �ִ����� ���, b�� 0�� �ɶ����� �ݺ�
	{
		memo = a % b; //memo�� a�� b���� ��� �̵���Ű������ ����
		a = b;
		b = memo;

	}

	gcd = a; //�ִ����� ���
	lcm = (num1 * num2) / gcd; //����� �ִ������� �Է��� �� ���� �̿��Ͽ� �ּҰ���� ���

	printf("�ִ����� : %d\n", gcd);
	printf("�ּҰ���� : %d\n", lcm);


	return 0;

}