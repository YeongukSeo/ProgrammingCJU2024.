#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0;
    char sym;

    
    printf("사칙연산 입력(정수) : ");
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
        printf("잘못된 연산자입니다. (+, -, *, / 중 하나를 사용하세요.)\n");
       
    }

    return 0;
}
