#include <stdio.h>

int main() 
{
    int start, end;
    
    printf("구구단을 출력할 시작 단과 끝 단을 입력하세요 (2에서 9 사이의 숫자): ");
    scanf_s("%d %d", &start, &end);

    // 구구단 출력
    for (int i = start; i <= end; i++) // i를 start로 초기화 한뒤 end보다 작을때까지 1씩 늘려가며 진행.
    {
        printf("\n%d단 출력:\n", i);
        for (int j = 1; j <= 9; j++) // 중첩 반복문으로 선행된 반복문이 한번진행될때 이 반복문은 9번 진행.
        {
            printf("%d x %d = %d\n", i, j, i * j); //속에 있는 for문에 맞춰서 하나의 i값과 1-9까지의 j값을 잇다라 출력.
        }
    }

    return 0;
}
