// p.23.cpp : �ܼ� ���� ���α׷��� ���� ���� ���ڼ� ���α׷����� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int n,c;
	
	n = 0;
	printf("input the words you want:\n");
	while ((c=getchar()) != EOF)
		if (c == '\t')
			++n;
	printf("%d\n", n);
		
	return 0;
}