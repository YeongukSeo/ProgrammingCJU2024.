#include <stdio.h>
#include <math.h>

// 3차원 점을 나타내는 구조체 선언
struct Point_3D 
{
    double x;
    double y;
    double z;
};

// 유클리드 거리를 계산하는 함수
double euclidean_distance(struct Point_3D* p1, struct Point_3D* p2) 
{
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() 
{
    // 두 점을 저장할 구조체 변수 선언
    struct Point_3D point1, point2;

    // 사용자로부터 첫 번째 점의 좌표 입력 받기
    printf("첫 번째 점의 좌표를 입력하세요 (x y z): ");
    if (scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z) != 3) 
    {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    // 사용자로부터 두 번째 점의 좌표 입력 받기
    printf("두 번째 점의 좌표를 입력하세요 (x y z): ");
    if (scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z) != 3) 
    {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    // 유클리드 거리 계산
    double distance = euclidean_distance(&point1, &point2);

    // 결과 출력
    printf("두 점 사이의 유클리드 거리: %.4lf\n", distance);

    return 0;
}