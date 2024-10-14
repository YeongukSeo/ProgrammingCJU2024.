#include <stdio.h>

int main() 
{
    int num1 = 0, num2 = 0;
    char symbol;


    printf("사직연산 입력(정수) : ");
    scanf_s("%d %c %d", &num1, &symbol, sizeof(symbol), &num2);


    if (symbol == '+')
    {
        printf("%d%c%d = %d\n", num1, symbol, num2, num1 + num2);
    }
    else if (symbol == '-') 
    {
        printf("%d%c%d = %d\n", num1, symbol, num2, num1 - num2);
    }
    else if (symbol == '*') 
    {
        printf("%d%c%d = %d\n", num1, symbol, num2, num1 * num2);
    }
    else if (symbol == '/')
    {
        if (num2 != 0) 
        {
            printf("%d%c%d = %d\n", num1, symbol, num2, num1 / num2);
        }
        else 
        {
            printf("0으로 나눌 수 없습니다.\n");
        }
    
    }
    else
    {
        printf("잘못된 연산자 입니다.\n");
    }
    return 0;
}