#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10

int generate_random_number()
{
    return (rand() % 200) + 1; // 1���� 200 ������ ���� ����
}

int main()
{
    int computer_number, player_number = 0;

     computer_number = generate_random_number(); // ���� ���� �Լ� ȣ��

    printf("0���� 200������ ���� ���� ���߱� ����\n");

    for (int i = 0; i < COUNT; i++)
    {

        
        printf("���� �Է��Ͻÿ�(%d��° �õ�) : ", i+1);
        scanf_s("%d", &player_number);

        if (computer_number == player_number)
        {
            printf("�����Դϴ�.\n\n");
            return 0;
        }

        else if (computer_number > player_number)
        {
            printf("��!");
        }

        else 
        {
            printf("�ٿ�!");
        }
        printf("\n");
    }
    


    printf("Ż��. ������ %d �����ϴ�. �ٽ� �����غ�����. \n\n", computer_number);
    return 0;

}