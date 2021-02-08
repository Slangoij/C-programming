// p.23.cpp : 콘솔 응용 프로그램에 대한 진입 글자수 프로그램점을 정의합니다.
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