#include <stdio.h>

int main()
{
	int mon, prod, chan, a, b, c, d, e = 0; // 변수 선언.

	printf("투입한 금액과 물건 값을 적으시오. : ");

	scanf_s("%d %d", &mon, &prod); // 투입한 금액(mon)과 물건값(prod) 입력.

	chan = prod - mon; // 거스름돈(chan) 계산.

	a = chan / 1000; // 지급할 1000원 갯수 계산.
	b = chan - 1000 * a; // 1000원 지급한뒤 남은 돈 계산.
	c = b / 500; // 지급할 500원 갯수 계산.
	d = b - 500 * c; // 500원까지 지급한뒤 남은 돈 계산.
	e = d / 100; // 지급할 100원 갯수 계산.

	printf("거스름돈은 %d이며, 1000원 %d개, 500원 %d개, 100원 %d개 지급됩니다.", chan, a, c, e); // 계산한 값을 바탕으로 출력.
	
	return 0;
}