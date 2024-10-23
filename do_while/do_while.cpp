#include <stdio.h>

int main() {
    int num1, num2, gcd, lcm, a, b, memo;

    printf("두 숫자를 입력하세요: ");
    scanf_s("%d %d", &num1, &num2);

    a = num1; //입력받은 첫번째 수 a에 저장
    b = num2; //입력받은 두번째 수 b에 저장

    
    do { //유클리드 호제법 사용하여 최대공약수 계산
        memo = a % b; //memo는 a와 b를 순서 바꾸기 위한 기억 변수
        a = b;
        b = memo;
    } while (b != 0); //b가 0이 될때까지 반복

    gcd = a;  // 최대공약수
    lcm = (num1 * num2) / gcd;  // 계산한 최대공약수와 입력받은 num1과 num2를 이용해 최소공배수 계산.

    printf("최대공약수: %d\n", gcd);
    printf("최소공배수: %d\n", lcm);

    return 0;
}