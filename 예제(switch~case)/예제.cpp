#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0;
    char sym;

    
    printf("��Ģ���� �Է�(����) : ");
    scanf_s("%d %c %d", &num1, &sym, sizeof(sym), & num2);

    switch (sym) {
    case '+':
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        break;
    case '/':
        printf("%d / %d = %d\n", num1, num2, num1 / num2);
        break;
    default:
        printf("�߸��� �������Դϴ�. (+, -, *, / �� �ϳ��� ����ϼ���.)\n");
       
    }

    return 0;
}
