#include <stdio.h>

int main()
{
	float num1 = 0.0; //�Ǽ��� ���� ���� �� �ʱ�ȭ

	printf("������ �Է��Ͻÿ�(0.0-100.0 ������ �Ǽ�) : ");
	scanf_s("%f", &num1); //���� �Է�

	//if���� ����� 10�� ������ ������ ������ �ο�
	if (num1 >= 90.0)
	{
		printf("A�����Դϴ�.\n\n");
	}
	else if (num1 >= 80.0)
	{
		printf("B�����Դϴ�.\n\n");
	}
	else if (num1 >= 70.0)
	{
		printf("C�����Դϴ�.\n\n");
	}
	else if (num1 >= 60.0)
	{
		printf("D�����Դϴ�.\n\n");
	}
	else if (num1 >= 50.0)
	{
		printf("E�����Դϴ�.\n\n");
	}
	else
	{
		printf("F�����Դϴ�.\n\n");
	}

	return 0;
}