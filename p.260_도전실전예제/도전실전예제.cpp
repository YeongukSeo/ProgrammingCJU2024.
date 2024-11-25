#include <stdio.h>

int main()
{
    char input[100]; // 최대 100자까지 입력받을 문자열을 저장할 배열
    int count = 0;   // 바뀐 문자수 카운트 변수
    int i = 0;       

    
    printf("문장을 입력하세요: ");

    // 키보드로부터 문자열 입력 받기 (최대 100자)
    fgets(input, sizeof(input), stdin);

    // 입력받은 문자열을 하나씩 확인
    for (i = 0; input[i] != '\0'; i++) // '\0'은 문자열의 끝을 의미
    {
        // 현재 문자가 대문자('A' ~ 'Z')라면
        if ((input[i] >= 'A') && (input[i] <= 'Z'))
        {
            // 대문자를 소문자로 변환 (ASCII 값 차이: 'a' - 'A' = 32)
            input[i] += ('a' - 'A');

            // 변환한 문자 수 증가
            count++;
        }
    }

    // 결과 출력
    printf("변환된 문장: ");
    puts(input); // 변환된 문자열을 출력 (fgets와 함께 사용 시 자동으로 개행 포함)
    printf("변환된 문자 수: %d\n", count); // 변환된 문자 개수 출력

    return 0;
}