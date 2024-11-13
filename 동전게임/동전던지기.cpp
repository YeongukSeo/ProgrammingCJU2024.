#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COIN_FWD_BWD 2
#define NUM_FLIP 10000
#define COIN_FWD_STATUS 0 // 앞면
#define COIN_BWD_STATUS 1 // 뒷면

// 동전 던지기 함수
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    return rand() % nRange; // 0 또는 1 반환 (앞면 또는 뒷면)
}

int main()
{
    int nNumSumFwdFlip = 0; // 앞면 나온 수
    int nNumSumBwdFlip = 0; // 뒷면 나온 수
    

    srand((unsigned int)time(NULL)); // 난수 초기화

    // 동전 던지기 10000번 수행
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FWD_BWD);

        switch (nStatusFlipCoin)
        {
        case COIN_FWD_STATUS: // 앞면일 때
            nNumSumFwdFlip++; // 앞면이 나온 수를 1 증가
            break;

        case COIN_BWD_STATUS: // 뒷면일 때
            nNumSumBwdFlip++; // 뒷면이 나온 수를 1 증가
            break;
        }
    }

    // 앞면, 뒷면의 확률 계산
    double dProbFwd = (double)nNumSumFwdFlip / NUM_FLIP * 100;
    double dProbBwd = (double)nNumSumBwdFlip / NUM_FLIP * 100;
   

    // 결과 출력
    printf("앞면이 나온 횟수: %d, 확률: %.2f%%\n", nNumSumFwdFlip, dProbFwd);
    printf("뒷면이 나온 횟수: %d, 확률: %.2f%%\n", nNumSumBwdFlip, dProbBwd);

    return 0;
}