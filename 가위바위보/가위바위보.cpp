#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R_P_S 3
#define END_COND 999
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INITSTATUS 0


//���� ���� �Լ�
unsigned int GenRandNum(unsigned int nRange)
{
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nRange));
	return nRes;
}

int main()
	{
		

		//���� �ʱ�ȭ
		unsigned int nComRps = INITSTATUS;
		unsigned int nPlayerRps = INITSTATUS;

		int nRange = 0;


		//���� ����
		while (1)
		{
			printf(":Input Your Choice(Rock : 0, Paper : 1, Scissors : 2)\n");
			printf("if you want to end the loop, please input 999\n");
			scanf_s("%d", &nPlayerRps);

			//���� ����
			if (nPlayerRps == END_COND)
			{
				printf("end of the infinite while loop RPS game...\n\n");
				break;
			}

			//�߸��� �Է� ó��
			if ((nPlayerRps < 0) || (nPlayerRps >= R_P_S))
			{
				printf("�ٽ� �Է��Ͻÿ�.\n\n");
				continue;
			}

			//��ǻ���� ����
			unsigned nComRps = GenRandNum(R_P_S);



			printf("(Player, computer) : (%d, %d)\n\n", nPlayerRps, nComRps); //���� ��ǻ�Ͱ� ������ �� ���


			//���� ������ ���� ��ǻ�Ͱ� ������ ���� ���Ͽ� ��, ��, ���º� ���
			if (nPlayerRps == nComRps)
			{
				printf("draw!\n\n");
			}
			else if ((nPlayerRps == ROCK && nComRps == SCISSORS) || (nPlayerRps == PAPER && nComRps == ROCK) || (nPlayerRps == SCISSORS && nComRps == PAPER))
			{
				printf("you win!! \n\n");
			}
			else
			{
				printf("you lose\n\n");
			}

		}

		return 0;
	}
