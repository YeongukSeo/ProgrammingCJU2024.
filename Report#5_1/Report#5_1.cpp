#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 200 // 최대 학생 수
#define MAX_NAME_LENGTH 50 // 학생 이름의 최대 길이
#define SUBJECT_COUNT 3 // 과목 수 (국어, 영어, 수학)
#define TOTAL_CLASSES 2 // 총 클래스(반) 수

// 열거형을 사용하여 과목 정의
typedef enum
{
    KOREAN,  // 0
    ENGLISH, // 1
    MATH     // 2
} Subject;

// 학생 데이터 구조체
struct Student
{
    char name[MAX_NAME_LENGTH]; // 학생 이름
    int class_number;           // 반 번호 (1 또는 2)
    int student_id;             // 학생 ID
    int scores[SUBJECT_COUNT];  // 각 과목 점수 (국어, 영어, 수학)
    float average;              // 평균 점수
    int class_rank;             // 반 내 등수
    int overall_rank;           // 전체 등수
};


int read_students(const char* filename, struct Student students[], int class_number, int start_index);
void calculate_averages(struct Student students[], int count);
void calculate_ranks(struct Student students[], int count, int is_overall);
void write_class_results(const char* filename, struct Student students[], int count, int class_number);
void write_overall_results(const char* filename, struct Student students[], int count);

int main()
{
    struct Student all_students[MAX_STUDENTS]; // 모든 학생 데이터를 저장하는 배열
    int count = 0; // 현재까지 읽은 학생 수

    // 학생 데이터 파일에서 읽기 (1반 데이터 읽기)
    int read_count1 = read_students("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_1.txt", all_students, 1, count);
    if (read_count1 == -1)
    {
        printf("학생 1 파일을 읽는 중 오류가 발생했습니다.\n");
        return 1; // 오류가 발생하면 프로그램 종료
    }
    count += read_count1; // 1반 학생 수 누적

    // 학생 데이터 파일에서 읽기 (2반 데이터 읽기)
    int read_count2 = read_students("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_2.txt", all_students, 2, count);
    if (read_count2 == -1)
    {
        printf("학생 2 파일을 읽는 중 오류가 발생했습니다.\n");
        return 1; // 오류가 발생하면 프로그램 종료
    }
    count += read_count2; // 2반 학생 수 누적

    if (count == 0)
    {
        printf("읽어올 학생이 없습니다. 프로그램을 종료합니다.\n");
        return 0; // 학생 데이터가 없으면 종료
    }

    printf("전체 학생 수: %d\n", count);

    // 평균 점수 계산
    calculate_averages(all_students, count);

    // 전체 등수 계산 (is_overall = 1)
    calculate_ranks(all_students, count, 1);

    // 반별 등수 계산 (is_overall = 0)
    calculate_ranks(all_students, count, 0);

    // 각 반별 결과를 파일에 저장
    write_class_results("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_1_results.txt", all_students, count, 1);
    write_class_results("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_2_results.txt", all_students, count, 2);

    // 전체 결과를 파일에 저장
    write_overall_results("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\class_results.txt", all_students, count);

    printf("성적 관리 프로그램이 정상적으로 완료되었습니다.\n");
    return 0;
}

// 학생 데이터를 파일에서 읽어와 배열에 저장
int read_students(const char* filename, struct Student students[], int class_number, int start_index)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL)
    {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return -1; // 파일 열기 실패 시 -1 반환
    }

    int count = start_index; // 배열에 저장할 시작 인덱스
    while (count < MAX_STUDENTS)
    {
        struct Student temp; // 임시 학생 구조체
        temp.class_number = class_number; // 현재 읽는 반 번호 저장
        temp.average = 0.0f; // 초기화
        temp.class_rank = 0;
        temp.overall_rank = 0;

        // 파일에서 학생 정보를 읽어오기
        int ret = fscanf_s(file, "%49s %d %d %d %d",
            temp.name, (unsigned)sizeof(temp.name), // 이름
            &temp.student_id,                      // 학생 ID
            &temp.scores[KOREAN],                  // 국어 점수
            &temp.scores[ENGLISH],                 // 영어 점수
            &temp.scores[MATH]);                   // 수학 점수

        if (ret == 5) // 데이터가 올바르게 읽힌 경우
        {
            students[count++] = temp; // 배열에 저장 후 인덱스 증가
        }
        else
        {
            if (feof(file)) // 파일 끝에 도달한 경우 루프 종료
            {
                break;
            }
            else // 데이터 읽기 실패 시 오류 출력
            {
                printf("학생 정보를 읽는 중 오류가 발생했습니다: ret=%d\n", ret);
                break;
            }
        }
    }

    fclose(file); // 파일 닫기
    printf("파일 %s에서 %d명의 학생을 읽어왔습니다.\n", filename, count - start_index);
    return count - start_index; // 읽어온 학생 수 반환
}

// 학생 평균 점수 계산
void calculate_averages(struct Student students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int total = 0; // 점수 합계 초기화
        for (int j = 0; j < SUBJECT_COUNT; j++)
        {
            total += students[i].scores[j]; // 점수 합산
        }
        students[i].average = total / (float)SUBJECT_COUNT; // 평균 계산
    }
}

// 학생 등수 계산 (전체 등수 또는 반별 등수)
void calculate_ranks(struct Student students[], int count, int is_overall)
{
    for (int i = 0; i < count; i++)
    {
        int rank = 1; // 초기 등수는 1등
        for (int j = 0; j < count; j++)
        {
            if (is_overall) // 전체 등수 계산
            {
                if (students[j].average > students[i].average)
                    rank++;
            }
            else // 반별 등수 계산
            {
                if (students[j].class_number == students[i].class_number && students[j].average > students[i].average)
                    rank++;
            }
        }
        if (is_overall)
            students[i].overall_rank = rank; // 전체 등수 저장
        else
            students[i].class_rank = rank; // 반별 등수 저장
    }
}

// 반별 결과를 파일에 저장
void write_class_results(const char* filename, struct Student students[], int count, int class_number)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        printf("결과 파일을 열 수 없습니다: %s\n", filename);
        exit(EXIT_FAILURE); // 파일 열기 실패 시 프로그램 종료
    }

    // 파일에 헤더 작성
    fprintf(file, "ID\tName\tKorean\tEnglish\tMath\tAverage\tClass Rank\tOverall Rank\n");
    for (int i = 0; i < count; i++)
    {
        if (students[i].class_number != class_number) // 해당 반 학생이 아닌 경우 건너뜀
            continue;
        // 학생 정보를 파일에 저장
        fprintf(file, "%d\t%s\t%d\t%d\t%d\t%.2f\t%d\t\t%d\n",
            students[i].student_id, // 학번
            students[i].name,       // 이름
            students[i].scores[KOREAN], // 국어
            students[i].scores[ENGLISH], // 영어
            students[i].scores[MATH], // 수학
            students[i].average,    // 평균
            students[i].class_rank, // 반별 등수
            students[i].overall_rank); // 전체 등수
    }

    fclose(file); // 파일 닫기
    printf("결과를 파일 %s에 저장했습니다.\n", filename);
}

// 전체 결과를 파일에 저장
void write_overall_results(const char* filename, struct Student students[], int count)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        printf("클래스 결과 파일을 열 수 없습니다: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // 클래스별 평균 계산
    float class_avg[TOTAL_CLASSES] = { 0.0, 0.0 };
    int class_counts[TOTAL_CLASSES] = { 0, 0 };

    for (int i = 0; i < count; i++)
    {
        if (students[i].class_number >= 1 && students[i].class_number <= TOTAL_CLASSES)
        {
            class_avg[students[i].class_number - 1] += students[i].average; // 총합 누적
            class_counts[students[i].class_number - 1]++; // 학생 수 증가
        }
    }

    for (int i = 0; i < TOTAL_CLASSES; i++)
    {
        if (class_counts[i] > 0)
            class_avg[i] /= class_counts[i]; // 평균 계산
    }

    // 전체 평균 계산
    float overall_avg = 0.0;
    for (int i = 0; i < count; i++)
    {
        overall_avg += students[i].average; // 전체 평균 점수 합산
    }
    if (count > 0)
        overall_avg /= count; // 전체 평균 계산

    // 클래스별 평균 및 전체 평균 작성
    fprintf(file, "Class 1 Average: %.2f\n", class_avg[0]);
    fprintf(file, "Class 2 Average: %.2f\n", class_avg[1]);
    fprintf(file, "Overall Average: %.2f\n\n", overall_avg);

    // 클래스별 등수 분포 작성
    for (int c = 1; c <= TOTAL_CLASSES; c++)
    {
        fprintf(file, "Class %d Rank Distribution:\n", c);
        for (int r = 1; r <= count; r++)
        {
            for (int i = 0; i < count; i++)
            {
                if (students[i].class_number == c && students[i].class_rank == r)
                {
                    fprintf(file, "Rank %d: %s (ID: %d)\n", r, students[i].name, students[i].student_id);
                }
            }
        }
        fprintf(file, "\n");
    }

    // 전체 등수 분포 작성
    fprintf(file, "Overall Rank Distribution:\n");
    for (int r = 1; r <= count; r++)
    {
        for (int i = 0; i < count; i++)
        {
            if (students[i].overall_rank == r)
            {
                fprintf(file, "Rank %d: %s (ID: %d)\n", r, students[i].name, students[i].student_id);
            }
        }
    }

    fclose(file); // 파일 닫기
    printf("클래스 전체 결과를 파일 %s에 저장했습니다.\n", filename);
}
