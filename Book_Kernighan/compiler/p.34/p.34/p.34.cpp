// p.34.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int power(int m, int n);

int main()
{
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d %8d %8d\n", i, power(2, i), power(-3, i));
	return 0;
}

int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p*base;
	return p;
}

