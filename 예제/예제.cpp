#include <stdio.h>

int main() 
{
    int num1 = 0, num2 = 0;
    char symbol;


    printf("�������� �Է�(����) : ");
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
            printf("0���� ���� �� �����ϴ�.\n");
        }
    
    }
    else
    {
        printf("�߸��� ������ �Դϴ�.\n");
    }
    return 0;
}