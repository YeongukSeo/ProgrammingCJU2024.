#include <stdio.h>    // ǥ�� ����� �Լ����� ����ϱ� ���� ���
#include <stdlib.h>   // �Ϲ� ��ƿ��Ƽ �Լ���(��: �޸� �Ҵ�, ���� ����)�� ����ϱ� ���� ���
#include <math.h>     // ���� �Լ���(��: cos, sin)�� ����ϱ� ���� ���
#include <time.h>     // �ð� ���� �Լ���(��: time, srand)�� ����ϱ� ���� ���

#define NUM_PARTICLES 100    // �ùķ��̼ǿ� ����� ���� ��
#define TIME_STEPS 1000      // �ùķ��̼��� �ð� �ܰ��� ��
#define DT 0.01              // �� �ð� �ܰ迡���� �ð� ����
#define M_PI 3.14159265358979323846    // ������ ���� �� ����

// 2���� �������� ������ ��ġ�� ��Ÿ���� ����ü ����
typedef struct
{
    double x;    // ������ x ��ǥ
    double y;    // ������ y ��ǥ
} Particle;

// ���� �ӵ��� �Լ�
// �־��� (x, y) ��ġ������ �ӵ� ���� (u, v)�� ���
void velocity_field(double x, double y, double* u, double* v)
{
    *u = -y;    // ���� �ӵ� ����: -y
    *v = x;     // ���� �ӵ� ����: x
}

int main()
{
    Particle particles[NUM_PARTICLES];    // ���� �迭 ����
    srand(time(NULL));                     // ���� �������� �õ� ����

    // �ʱ� ���� ��ġ�� ������(������ 1)�� �ѷ��� �����ϰ� ����
    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        double angle = (2 * M_PI / NUM_PARTICLES) * i;    // �� ������ �ʱ� ���� ���
        particles[i].x = cos(angle);                        // x ��ǥ ����
        particles[i].y = sin(angle);                        // y ��ǥ ����
    }

    // ���� ������ ���� �ùķ��̼� ����
    for (int t = 0; t < TIME_STEPS; t++)
    {
        // �� ���ڿ� ���� �ӵ��� ����ϰ� ��ġ�� ������Ʈ
        for (int i = 0; i < NUM_PARTICLES; i++)
        {
            double u, v;    // ���� ��ġ������ �ӵ� ������ ������ ����

            // ���� ������ ��ġ���� �ӵ��� �Լ��� ȣ���Ͽ� �ӵ� ���� ���
            velocity_field(particles[i].x, particles[i].y, &u, &v);

            // ���Ϸ� ����� ����Ͽ� ������ ��ġ ������Ʈ
            particles[i].x += u * DT;    // x ��ǥ ������Ʈ
            particles[i].y += v * DT;    // y ��ǥ ������Ʈ
        }
    }

    // �ùķ��̼��� ���� �� ��� ������ ���� ��ġ�� ���
    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        printf("Particle %d: x=%.2f, y=%.2f\n", i, particles[i].x, particles[i].y);
    }

    return 0;    // ���α׷� ����
}
