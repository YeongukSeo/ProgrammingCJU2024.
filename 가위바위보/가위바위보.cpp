#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R_P_S 3
#define END_COND 999
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INITSTATUS 0


//난수 생성 함수
unsigned int GenRandNum(unsigned int nRange)
{
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nRange));
	return nRes;
}

int main()
	{
		

		//변수 초기화
		unsigned int nComRps = INITSTATUS;
		unsigned int nPlayerRps = INITSTATUS;

		int nRange = 0;


		//무한 루프
		while (1)
		{
			printf(":Input Your Choice(Rock : 0, Paper : 1, Scissors : 2)\n");
			printf("if you want to end the loop, please input 999\n");
			scanf_s("%d", &nPlayerRps);

			//종료 조건
			if (nPlayerRps == END_COND)
			{
				printf("end of the infinite while loop RPS game...\n\n");
				break;
			}

			//잘못된 입력 처리
			if ((nPlayerRps < 0) || (nPlayerRps >= R_P_S))
			{
				printf("다시 입력하시오.\n\n");
				continue;
			}

			//컴퓨터의 선택
			unsigned nComRps = GenRandNum(R_P_S);



			printf("(Player, computer) : (%d, %d)\n\n", nPlayerRps, nComRps); //나와 컴퓨터가 선택한 수 출력


			//내가 선택한 수와 컴퓨터가 선택한 수를 비교하여 승, 패, 무승부 출력
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
