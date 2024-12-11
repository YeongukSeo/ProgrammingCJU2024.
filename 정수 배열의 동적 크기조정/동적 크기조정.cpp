#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// 합계, 평균, 분산, 표준편차를 계산하는 함수
// array: 정수 배열 (계산 대상), size: 배열의 크기, sum, mean, variance, std_dev: 계산 결과를 저장할 포인터 변수들
void All(int* array, int size, double* sum, double* mean, double* variance, double* std_dev)
{
    *sum = 0; // 합계를 0으로 초기화
    for (int i = 0; i < size; i++)  // 배열의 모든 요소를 더함
    {
        *sum += array[i];
    }
    *mean = *sum / size; // 평균 계산

    *variance = 0; // 분산을 0으로 초기화
    for (int i = 0; i < size; i++) // 분산 계산: (값 - 평균)^2의 합
    {
        *variance += pow(array[i] - *mean, 2);
    }
    *variance /= size; // 분산 = 합계 / 크기
    *std_dev = sqrt(*variance); // 표준편차 = 분산의 제곱근
}

int main()
{
    int first_size, second_size; // 초기 배열 크기와 추가 배열 크기를 저장할 변수
    double sum, mean, variance, std_dev; // 통계 결과를 저장할 변수

    // 초기 배열 크기 입력받기
    printf("초기 배열 크기: ");
    scanf_s("%d", &first_size); // 사용자로부터 초기 배열 크기 입력

    // 동적 메모리 할당
    // 사용자로부터 입력받은 크기만큼 정수 배열 생성
    int* array = (int*)malloc(first_size * sizeof(int));
    if (array == NULL)  // 메모리 할당 실패 시 프로그램 종료
    {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 배열 값 입력받기
    printf("입력한 값: ");
    for (int i = 0; i < first_size; i++)
    {
        scanf_s("%d", &array[i]); // 사용자가 배열의 각 값을 입력
    }

    // 통계 계산: 배열의 합계, 평균, 분산, 표준편차 계산
    All(array, first_size, &sum, &mean, &variance, &std_dev);
    // 통계 결과 출력
    printf("합계: %.2lf\n", sum);
    printf("평균: %.2lf\n", mean);
    printf("분산: %.2lf\n", variance);
    printf("표준편차: %.2lf\n", std_dev);

    // 추가 배열 크기 입력받기
    printf("추가 배열 크기: ");
    scanf_s("%d", &second_size); // 추가 배열 크기 입력

    // 기존 배열 크기 확장
    // 기존 배열에 추가 크기만큼 메모리 재할당
    array = (int*)realloc(array, (first_size + second_size) * sizeof(int));
    if (array == NULL) // 메모리 재할당 실패 시 프로그램 종료
    {
        printf("메모리 재할당 실패\n");
        return 1;
    }

    // 추가 값 입력받기
    printf("추가된 값: ");
    for (int i = 0; i < second_size; i++)
    {
        // 새로운 배열의 확장된 부분에 값을 입력
        scanf_s("%d", &array[first_size + i]);
    }

    // 확장된 배열에 대한 통계 계산
    All(array, first_size + second_size, &sum, &mean, &variance, &std_dev);
    // 새로운 통계 결과 출력
    printf("새로운 합계: %.2lf\n", sum);
    printf("새로운 평균: %.2lf\n", mean);
    printf("새로운 분산: %.2lf\n", variance);
    printf("새로운 표준편차: %.2lf\n", std_dev);

    // 동적으로 할당된 메모리 해제
    free(array);
    return 0;
}
