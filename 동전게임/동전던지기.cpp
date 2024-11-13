#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COIN_FWD_BWD 2
#define NUM_FLIP 10000
#define COIN_FWD_STATUS 0 // �ո�
#define COIN_BWD_STATUS 1 // �޸�

// ���� ������ �Լ�
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    return rand() % nRange; // 0 �Ǵ� 1 ��ȯ (�ո� �Ǵ� �޸�)
}

int main()
{
    int nNumSumFwdFlip = 0; // �ո� ���� ��
    int nNumSumBwdFlip = 0; // �޸� ���� ��
    

    srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ

    // ���� ������ 10000�� ����
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FWD_BWD);

        switch (nStatusFlipCoin)
        {
        case COIN_FWD_STATUS: // �ո��� ��
            nNumSumFwdFlip++; // �ո��� ���� ���� 1 ����
            break;

        case COIN_BWD_STATUS: // �޸��� ��
            nNumSumBwdFlip++; // �޸��� ���� ���� 1 ����
            break;
        }
    }

    // �ո�, �޸��� Ȯ�� ���
    double dProbFwd = (double)nNumSumFwdFlip / NUM_FLIP * 100;
    double dProbBwd = (double)nNumSumBwdFlip / NUM_FLIP * 100;
   

    // ��� ���
    printf("�ո��� ���� Ƚ��: %d, Ȯ��: %.2f%%\n", nNumSumFwdFlip, dProbFwd);
    printf("�޸��� ���� Ƚ��: %d, Ȯ��: %.2f%%\n", nNumSumBwdFlip, dProbBwd);

    return 0;
}