// p.27.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '|n')
			++nl;
	printf("%d|n", nl);
}

