#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 무작위 정수를 생성하여 배열에 저장하는 함수
void generate_random_numbers(int* array, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min; // 무작위 정수 생성
    }
}

// 지정된 범위 내에서 정수를 추출하는 함수
// 원본 배열(numbers), 원본 배열 크기(numbers_size), 추출된 정수를 저장할 배열(new_array), 저장가능한 최대 크기(new_array_size), 추출 범위(range_min, range_max)
// numbers 배열에서 range_min과 range_max 범위에 해당하는 정수를 최대 new_array_size만큼 추출하여 new_array 배열에 저장
int extract_numbers(int* numbers, int numbers_size, int* new_array, int new_array_size, int range_min, int range_max)
{
    int count = 0; // 추출된 정수 개수 초기화
    for (int i = 0; i < numbers_size && count < new_array_size; i++)
    {
        if (numbers[i] >= range_min && numbers[i] <= range_max) // 범위 검사
        {
            new_array[count++] = numbers[i]; // 추출된 정수를 대상 배열에 저장
        }
    }
    return count; // 추출된 정수 개수 반환
}

// 배열의 총합을 계산하는 함수
// 정수 배열(array), 배열 크기(size)
double calculate_sum(int* array, int size)
{
    double sum = 0.0; // 총합 초기화
    for (int i = 0; i < size; i++)
    {
        sum += array[i]; // 각 원소를 총합에 더함
    }
    return sum; // 총합 반환
}

// 배열의 분산을 계산하는 함수
// 정수 배열(array), 배열 크기(size), 배열의 평균(mean)
double calculate_variance(int* array, int size, double mean)
{
    double variance = 0.0; // 분산 초기화
    for (int i = 0; i < size; i++)
    {
        variance += pow(array[i] - mean, 2); // (값 - 평균)^2를 누적
    }
    return variance / size; // 분산 반환
}

// 배열의 표준편차를 계산하는 함수
// 분산(variance)
double calculate_standard_deviation(double variance)
{
    return sqrt(variance); // 표준편차는 분산의 제곱근
}

int main()
{
    int numbers[100]; // 100개의 무작위 정수를 저장할 배열
    int extracted[10]; // 추출된 정수를 저장할 배열 (최대 10개)
    int range_min, range_max; // 사용자 입력으로 받을 추출 범위
    int extracted_count; // 실제로 추출된 정수 개수
    double sum, variance, std_deviation; // 총합, 분산, 표준편차를 저장할 변수

    // 무작위 수 생성을 위해 시드 설정
    srand(time(0));

    // [1, 100] 범위의 무작위 정수를 100개 생성
    generate_random_numbers(numbers, 100, 1, 100);

    // 생성된 100개의 정수를 출력
    printf("생성된 100개의 정수:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", numbers[i]);
        if ((i + 1) % 10 == 0) printf("\n"); // 가독성을 위해 정수를 10개씩 끊어서 출력
    }

    // 사용자로부터 추출할 정수의 범위 입력
    printf("\n추출할 정수의 범위를 입력하세요.\n");
    printf("최소값: ");
    scanf_s("%d", &range_min); // 최소값 입력
    printf("최대값: ");
    scanf_s("%d", &range_max); // 최대값 입력

    // 유효성 검사 : 최소값이 최대값보다 크면 오류 메시지 출력 후 프로그램 종료
    if (range_min > range_max)
    {
        printf("오류: 최소값이 최대값보다 큽니다.\n");
        return 1; // 비정상 종료
    }

    // 지정된 범위 내에서 최대 10개의 정수를 추출
    extracted_count = extract_numbers(numbers, 100, extracted, 10, range_min, range_max);

    // 추출된 정수가 없을 경우 메시지 출력 후 종료
    if (extracted_count == 0)
    {
        printf("지정된 범위 내에 해당하는 정수가 없습니다.\n");
        return 0; // 정상 종료
    }

    // 추출된 정수 출력
    printf("\n추출된 %d개의 정수:\n", extracted_count);
    for (int i = 0; i < extracted_count; i++)
    {
        printf("%d ", extracted[i]);
    }
    printf("\n");

    // 총합 계산
    sum = calculate_sum(extracted, extracted_count);
    printf("총합: %.2lf\n", sum);

    // 분산 계산
    variance = calculate_variance(extracted, extracted_count, sum / extracted_count);
    printf("분산: %.2lf\n", variance);

    // 표준편차 계산
    std_deviation = calculate_standard_deviation(variance);
    printf("표준편차: %.2lf\n", std_deviation);

    return 0;
}



