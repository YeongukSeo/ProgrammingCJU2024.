#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 200 // �ִ� �л� ��
#define MAX_NAME_LENGTH 50 // �л� �̸��� �ִ� ����
#define SUBJECT_COUNT 3 // ���� �� (����, ����, ����)
#define TOTAL_CLASSES 2 // �� Ŭ����(��) ��

// �������� ����Ͽ� ���� ����
typedef enum
{
    KOREAN,  // 0
    ENGLISH, // 1
    MATH     // 2
} Subject;

// �л� ������ ����ü
struct Student
{
    char name[MAX_NAME_LENGTH]; // �л� �̸�
    int class_number;           // �� ��ȣ (1 �Ǵ� 2)
    int student_id;             // �л� ID
    int scores[SUBJECT_COUNT];  // �� ���� ���� (����, ����, ����)
    float average;              // ��� ����
    int class_rank;             // �� �� ���
    int overall_rank;           // ��ü ���
};


int read_students(const char* filename, struct Student students[], int class_number, int start_index);
void calculate_averages(struct Student students[], int count);
void calculate_ranks(struct Student students[], int count, int is_overall);
void write_class_results(const char* filename, struct Student students[], int count, int class_number);
void write_overall_results(const char* filename, struct Student students[], int count);

int main()
{
    struct Student all_students[MAX_STUDENTS]; // ��� �л� �����͸� �����ϴ� �迭
    int count = 0; // ������� ���� �л� ��

    // �л� ������ ���Ͽ��� �б� (1�� ������ �б�)
    int read_count1 = read_students("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_1.txt", all_students, 1, count);
    if (read_count1 == -1)
    {
        printf("�л� 1 ������ �д� �� ������ �߻��߽��ϴ�.\n");
        return 1; // ������ �߻��ϸ� ���α׷� ����
    }
    count += read_count1; // 1�� �л� �� ����

    // �л� ������ ���Ͽ��� �б� (2�� ������ �б�)
    int read_count2 = read_students("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_2.txt", all_students, 2, count);
    if (read_count2 == -1)
    {
        printf("�л� 2 ������ �д� �� ������ �߻��߽��ϴ�.\n");
        return 1; // ������ �߻��ϸ� ���α׷� ����
    }
    count += read_count2; // 2�� �л� �� ����

    if (count == 0)
    {
        printf("�о�� �л��� �����ϴ�. ���α׷��� �����մϴ�.\n");
        return 0; // �л� �����Ͱ� ������ ����
    }

    printf("��ü �л� ��: %d\n", count);

    // ��� ���� ���
    calculate_averages(all_students, count);

    // ��ü ��� ��� (is_overall = 1)
    calculate_ranks(all_students, count, 1);

    // �ݺ� ��� ��� (is_overall = 0)
    calculate_ranks(all_students, count, 0);

    // �� �ݺ� ����� ���Ͽ� ����
    write_class_results("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_1_results.txt", all_students, count, 1);
    write_class_results("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\students_2_results.txt", all_students, count, 2);

    // ��ü ����� ���Ͽ� ����
    write_overall_results("C:\\Users\\111\\Documents\\ProgrammingCJU2024\\Report#5_1\\class_results.txt", all_students, count);

    printf("���� ���� ���α׷��� ���������� �Ϸ�Ǿ����ϴ�.\n");
    return 0;
}

// �л� �����͸� ���Ͽ��� �о�� �迭�� ����
int read_students(const char* filename, struct Student students[], int class_number, int start_index)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL)
    {
        printf("������ �� �� �����ϴ�: %s\n", filename);
        return -1; // ���� ���� ���� �� -1 ��ȯ
    }

    int count = start_index; // �迭�� ������ ���� �ε���
    while (count < MAX_STUDENTS)
    {
        struct Student temp; // �ӽ� �л� ����ü
        temp.class_number = class_number; // ���� �д� �� ��ȣ ����
        temp.average = 0.0f; // �ʱ�ȭ
        temp.class_rank = 0;
        temp.overall_rank = 0;

        // ���Ͽ��� �л� ������ �о����
        int ret = fscanf_s(file, "%49s %d %d %d %d",
            temp.name, (unsigned)sizeof(temp.name), // �̸�
            &temp.student_id,                      // �л� ID
            &temp.scores[KOREAN],                  // ���� ����
            &temp.scores[ENGLISH],                 // ���� ����
            &temp.scores[MATH]);                   // ���� ����

        if (ret == 5) // �����Ͱ� �ùٸ��� ���� ���
        {
            students[count++] = temp; // �迭�� ���� �� �ε��� ����
        }
        else
        {
            if (feof(file)) // ���� ���� ������ ��� ���� ����
            {
                break;
            }
            else // ������ �б� ���� �� ���� ���
            {
                printf("�л� ������ �д� �� ������ �߻��߽��ϴ�: ret=%d\n", ret);
                break;
            }
        }
    }

    fclose(file); // ���� �ݱ�
    printf("���� %s���� %d���� �л��� �о�Խ��ϴ�.\n", filename, count - start_index);
    return count - start_index; // �о�� �л� �� ��ȯ
}

// �л� ��� ���� ���
void calculate_averages(struct Student students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int total = 0; // ���� �հ� �ʱ�ȭ
        for (int j = 0; j < SUBJECT_COUNT; j++)
        {
            total += students[i].scores[j]; // ���� �ջ�
        }
        students[i].average = total / (float)SUBJECT_COUNT; // ��� ���
    }
}

// �л� ��� ��� (��ü ��� �Ǵ� �ݺ� ���)
void calculate_ranks(struct Student students[], int count, int is_overall)
{
    for (int i = 0; i < count; i++)
    {
        int rank = 1; // �ʱ� ����� 1��
        for (int j = 0; j < count; j++)
        {
            if (is_overall) // ��ü ��� ���
            {
                if (students[j].average > students[i].average)
                    rank++;
            }
            else // �ݺ� ��� ���
            {
                if (students[j].class_number == students[i].class_number && students[j].average > students[i].average)
                    rank++;
            }
        }
        if (is_overall)
            students[i].overall_rank = rank; // ��ü ��� ����
        else
            students[i].class_rank = rank; // �ݺ� ��� ����
    }
}

// �ݺ� ����� ���Ͽ� ����
void write_class_results(const char* filename, struct Student students[], int count, int class_number)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        printf("��� ������ �� �� �����ϴ�: %s\n", filename);
        exit(EXIT_FAILURE); // ���� ���� ���� �� ���α׷� ����
    }

    // ���Ͽ� ��� �ۼ�
    fprintf(file, "ID\tName\tKorean\tEnglish\tMath\tAverage\tClass Rank\tOverall Rank\n");
    for (int i = 0; i < count; i++)
    {
        if (students[i].class_number != class_number) // �ش� �� �л��� �ƴ� ��� �ǳʶ�
            continue;
        // �л� ������ ���Ͽ� ����
        fprintf(file, "%d\t%s\t%d\t%d\t%d\t%.2f\t%d\t\t%d\n",
            students[i].student_id, // �й�
            students[i].name,       // �̸�
            students[i].scores[KOREAN], // ����
            students[i].scores[ENGLISH], // ����
            students[i].scores[MATH], // ����
            students[i].average,    // ���
            students[i].class_rank, // �ݺ� ���
            students[i].overall_rank); // ��ü ���
    }

    fclose(file); // ���� �ݱ�
    printf("����� ���� %s�� �����߽��ϴ�.\n", filename);
}

// ��ü ����� ���Ͽ� ����
void write_overall_results(const char* filename, struct Student students[], int count)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        printf("Ŭ���� ��� ������ �� �� �����ϴ�: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Ŭ������ ��� ���
    float class_avg[TOTAL_CLASSES] = { 0.0, 0.0 };
    int class_counts[TOTAL_CLASSES] = { 0, 0 };

    for (int i = 0; i < count; i++)
    {
        if (students[i].class_number >= 1 && students[i].class_number <= TOTAL_CLASSES)
        {
            class_avg[students[i].class_number - 1] += students[i].average; // ���� ����
            class_counts[students[i].class_number - 1]++; // �л� �� ����
        }
    }

    for (int i = 0; i < TOTAL_CLASSES; i++)
    {
        if (class_counts[i] > 0)
            class_avg[i] /= class_counts[i]; // ��� ���
    }

    // ��ü ��� ���
    float overall_avg = 0.0;
    for (int i = 0; i < count; i++)
    {
        overall_avg += students[i].average; // ��ü ��� ���� �ջ�
    }
    if (count > 0)
        overall_avg /= count; // ��ü ��� ���

    // Ŭ������ ��� �� ��ü ��� �ۼ�
    fprintf(file, "Class 1 Average: %.2f\n", class_avg[0]);
    fprintf(file, "Class 2 Average: %.2f\n", class_avg[1]);
    fprintf(file, "Overall Average: %.2f\n\n", overall_avg);

    // Ŭ������ ��� ���� �ۼ�
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

    // ��ü ��� ���� �ۼ�
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

    fclose(file); // ���� �ݱ�
    printf("Ŭ���� ��ü ����� ���� %s�� �����߽��ϴ�.\n", filename);
}
