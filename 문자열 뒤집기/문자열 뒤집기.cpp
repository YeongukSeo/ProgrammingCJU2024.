#include <stdio.h>
#include <string.h>

// 단어를 뒤집는 함수
// start: 단어의 시작 위치를 가리키는 포인터
// end: 단어의 끝 위치를 가리키는 포인터
void reverseWord(char* start, char* end) 
{
    char temp; // 문자 교환을 위한 임시 변수

    // 시작 포인터가 끝 포인터보다 작을 동안 반복
    while (start < end) 
    {
        temp = *start;   // 시작 위치의 문자를 임시 변수에 저장
        *start = *end;   // 끝 위치의 문자를 시작 위치로 이동
        *end = temp;     // 임시 변수에 저장된 문자를 끝 위치로 이동
        start++;         // 시작 포인터를 다음 문자로 이동
        end--;           // 끝 포인터를 이전 문자로 이동
    }
}

int main()
{
    char input[100]; // 사용자로부터 입력받을 문자열을 저장할 배열 (최대 99자 + null 문자)

    printf("Enter a string: "); 
   
    fgets(input, sizeof(input), stdin); // 문자열을 입력받음

    // 입력받은 문자열에 포함된 개행 문자('\n')를 찾아 이를 null 문자('\0')로 대체
    // strcspn 함수는 첫 번째 매개변수에서 두 번째 매개변수에 있는 문자 중 처음으로 등장하는 위치를 반환
    input[strcspn(input, "\n")] = '\0';

    int length = strlen(input); //문자열의 길이를 int 형태로 저장
    int start = 0; // 현재 단어의 시작 인덱스를 가리키는 변수

    // 문자열의 모든 문자에 대해 반복
    for (int i = 0; i <= length; i++) 
    {
        // 현재 문자가 공백이거나 문자열의 끝인 경우 단어의 끝으로 간주
        if (input[i] == ' ' || input[i] == '\0') 
        {
            // 단어의 시작과 끝을 가리키는 포인터를 reverseWord 함수에 전달하여 단어 뒤집기
            reverseWord(&input[start], &input[i - 1]);
            start = i + 1; // 다음 단어의 시작 인덱스를 설정
        }
    }

    
    printf("Reversed words: \"%s\"\n", input); // 최종 문자열을 출력

    return 0; 
}