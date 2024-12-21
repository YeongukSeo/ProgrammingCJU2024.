#include <stdio.h>    // 표준 입출력 함수들을 사용하기 위한 헤더
#include <stdlib.h>   // 일반 유틸리티 함수들(예: 메모리 할당, 난수 생성)을 사용하기 위한 헤더
#include <math.h>     // 수학 함수들(예: cos, sin)을 사용하기 위한 헤더
#include <time.h>     // 시간 관련 함수들(예: time, srand)을 사용하기 위한 헤더

#define NUM_PARTICLES 100    // 시뮬레이션에 사용할 입자 수
#define TIME_STEPS 1000      // 시뮬레이션할 시간 단계의 수
#define DT 0.01              // 각 시간 단계에서의 시간 증분
#define M_PI 3.14159265358979323846    // 원주율 π의 값 정의

// 2차원 공간에서 입자의 위치를 나타내는 구조체 정의
typedef struct
{
    double x;    // 입자의 x 좌표
    double y;    // 입자의 y 좌표
} Particle;

// 예시 속도장 함수
// 주어진 (x, y) 위치에서의 속도 성분 (u, v)를 계산
void velocity_field(double x, double y, double* u, double* v)
{
    *u = -y;    // 수평 속도 성분: -y
    *v = x;     // 수직 속도 성분: x
}

int main()
{
    Particle particles[NUM_PARTICLES];    // 입자 배열 선언
    srand(time(NULL));                     // 난수 생성기의 시드 설정

    // 초기 입자 위치를 단위원(반지름 1)의 둘레에 균일하게 분포
    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        double angle = (2 * M_PI / NUM_PARTICLES) * i;    // 각 입자의 초기 각도 계산
        particles[i].x = cos(angle);                        // x 좌표 설정
        particles[i].y = sin(angle);                        // y 좌표 설정
    }

    // 입자 추적을 위한 시뮬레이션 루프
    for (int t = 0; t < TIME_STEPS; t++)
    {
        // 각 입자에 대해 속도를 계산하고 위치를 업데이트
        for (int i = 0; i < NUM_PARTICLES; i++)
        {
            double u, v;    // 현재 위치에서의 속도 성분을 저장할 변수

            // 현재 입자의 위치에서 속도장 함수를 호출하여 속도 성분 계산
            velocity_field(particles[i].x, particles[i].y, &u, &v);

            // 오일러 방법을 사용하여 입자의 위치 업데이트
            particles[i].x += u * DT;    // x 좌표 업데이트
            particles[i].y += v * DT;    // y 좌표 업데이트
        }
    }

    // 시뮬레이션이 끝난 후 모든 입자의 최종 위치를 출력
    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        printf("Particle %d: x=%.2f, y=%.2f\n", i, particles[i].x, particles[i].y);
    }

    return 0;    // 프로그램 종료
}
