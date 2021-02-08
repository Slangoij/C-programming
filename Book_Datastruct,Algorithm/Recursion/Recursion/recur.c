#include <stdio.h>
#include "IntStack.h"

void recur(int n)
{
	IntStack stk;
	Initialize(&stk, 100);
Top:
	if (n > 0)
	{
		Push(&stk, n);
		n = n - 1;
		goto Top;
	}
	if (!IsEmpty(&stk))
	{
		Pop(&stk, &n);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}

	Terminate(&stk);
}

int main()
{
	int x;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &x);
	recur(x);

	return 0;
}