#include <stdio.h>

int main() {
    int num1, num2, gcd, lcm, a, b, memo;

    printf("�� ���ڸ� �Է��ϼ���: ");
    scanf_s("%d %d", &num1, &num2);

    a = num1; //�Է¹��� ù��° �� a�� ����
    b = num2; //�Է¹��� �ι�° �� b�� ����

    
    do { //��Ŭ���� ȣ���� ����Ͽ� �ִ����� ���
        memo = a % b; //memo�� a�� b�� ���� �ٲٱ� ���� ��� ����
        a = b;
        b = memo;
    } while (b != 0); //b�� 0�� �ɶ����� �ݺ�

    gcd = a;  // �ִ�����
    lcm = (num1 * num2) / gcd;  // ����� �ִ������� �Է¹��� num1�� num2�� �̿��� �ּҰ���� ���.

    printf("�ִ�����: %d\n", gcd);
    printf("�ּҰ����: %d\n", lcm);

    return 0;
}