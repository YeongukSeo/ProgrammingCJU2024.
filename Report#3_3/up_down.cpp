#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10

int generate_random_number()
{
    return (rand() % 200) + 1; // 1부터 200 사이의 숫자 생성
}

int main()
{
    int computer_number, player_number = 0;

     computer_number = generate_random_number(); // 숫자 생성 함수 호출

    printf("0부터 200사이의 랜덤 숫자 맞추기 게임\n");

    for (int i = 0; i < COUNT; i++)
    {

        
        printf("수를 입력하시오(%d번째 시도) : ", i+1);
        scanf_s("%d", &player_number);

        if (computer_number == player_number)
        {
            printf("정답입니다.\n\n");
            return 0;
        }

        else if (computer_number > player_number)
        {
            printf("업!");
        }

        else 
        {
            printf("다운!");
        }
        printf("\n");
    }
    


    printf("탈락. 정답은 %d 였습니다. 다시 도전해보세요. \n\n", computer_number);
    return 0;

}