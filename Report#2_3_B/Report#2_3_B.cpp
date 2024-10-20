#include <stdio.h>

int main()
{
    float num1 = 0.0; //실수형 변수 설정 및 초기화
    int a; //switch문을 사용하기 위한 정수형 변수 설정 및 초기화

    printf("성적을 입력하시오(0.0-100.0 범위의 실수) : ");
    scanf_s("%f", &num1); //성적 입력

    
    a = num1 / 10; // 10으로 나누고 소수점을 버리기 위해 정수형으로 설정

    switch (a)
    {
    case 10: // 100점
    case 9:  // 90~99점
        printf("A학점입니다.\n\n");
        break;
    case 8:  // 80~89점
        printf("B학점입니다.\n\n");
        break;
    case 7:  // 70~79점
        printf("C학점입니다.\n\n");
        break;
    case 6:  // 60~69점
        printf("D학점입니다.\n\n");
        break;
    case 5:  // 50~59점
        printf("E학점입니다.\n\n");
        break;
    default: // 0~49점
        printf("F학점입니다.\n\n");
        break;
    }

    return 0;
}