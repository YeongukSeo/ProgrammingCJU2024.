#include <stdio.h>

int main() 
{
    int start, end;
    
    printf("�������� ����� ���� �ܰ� �� ���� �Է��ϼ��� (2���� 9 ������ ����): ");
    scanf_s("%d %d", &start, &end);

    // ������ ���
    for (int i = start; i <= end; i++) // i�� start�� �ʱ�ȭ �ѵ� end���� ���������� 1�� �÷����� ����.
    {
        printf("\n%d�� ���:\n", i);
        for (int j = 1; j <= 9; j++) // ��ø �ݺ������� ����� �ݺ����� �ѹ�����ɶ� �� �ݺ����� 9�� ����.
        {
            printf("%d x %d = %d\n", i, j, i * j); //�ӿ� �ִ� for���� ���缭 �ϳ��� i���� 1-9������ j���� �մٶ� ���.
        }
    }

    return 0;
}
