#include <stdio.h>


float cel_to_fa(float celsius); // 섭씨를 화씨로 변환하는 함수
float fa_to_cel(float fahrenheit); // 화씨를 섭씨로 변환하는 함수


int main() 
{
    int choice;
    float temp, result_temp;
    printf("번호 '1' : 섭씨 -> 화씨\n");
    printf("번호 '2' : 화씨 -> 섭씨\n");
    printf("희망하는 변환을 선택하고 온도를 입력하시오. (예: 1 100)\n");
    printf("입력: ");

    scanf_s("%d %f", &choice, &temp);

    if (choice == 1) //1번을 선택(섭씨를 화씨로 변환)
    {
        result_temp = cel_to_fa(temp); // 섭씨값 반환
        printf("화씨 온도: %.2fF\n", result_temp);
    }
    else if (choice == 2) //2번 선택(화씨를 섭씨로 변환)
    {
        result_temp = fa_to_cel(temp); // 화씨값 반환
        printf("섭씨 온도: %.2fC\n", result_temp);
    }
    else 
    {
        printf("잘못된 선택입니다.\n"); //1과 2이외의 값 입력
    }

    return 0;
}

float cel_to_fa(float celsius) //입력받은 섭씨 온도를 화씨로 변환
{
    float result1;

    result1 = (celsius * 9 / 5) + 32;

    return result1;
}

float fa_to_cel(float fahrenheit) //입력받은 화씨 온도를 섭씨로 변환
{
    float result2;

    result2 = (fahrenheit - 32) * 5 / 9;


    return result2;
}