#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10

// 무작위 숫자 생성 함수
int generate_random_number(int start, int end) 
{
    return (rand() % (end - start + 1)) + start;
}

int main() {
    int start, end, number;
    int total_sum = 0;
    double mean, variance = 0.0, std_dev;

    
    srand(time(NULL)); // 난수 초기화

   
    // 범위 입력값 받기
    while (1) 
    {
        printf("정수 생성 시작 범위: ");
        scanf_s("%d", &start);
        printf("정수 생성 종료 범위: ");
        scanf_s("%d", &end);

        if (start < end) // 범위가 유효한지 판별
        {
            
            break; // 유효한 범위이면 반복문 종료
        }
        else //그렇지 않으면 다시 입력
        {
            printf("시작 범위는 종료 범위보다 작아야 합니다. 다시 입력하세요.\n");
        }
    }


    // 무작위 숫자 생성 및 화면에 출력
    printf("생성된 숫자: ");
    for (int i = 0; i < COUNT; i++) 
    {
       
        number = generate_random_number(start, end); // 무작위 숫자 생성 함수 호출

        printf("%d ", number);

        total_sum += number; // 총합에 현재 숫자를 추가

        variance += number * number; // 분산 계산을 위한 부분합 구하기
    }
    printf("\n");
   
    mean = (double)total_sum / COUNT; // 평균 계산
   
    variance = (variance / COUNT) - (mean * mean); // 분산 계산

    std_dev = sqrt(variance); // 표준편차 계산

    // 결과 출력
    printf("총합: %d\n", total_sum);
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", std_dev);

    return 0;
}