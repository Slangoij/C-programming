// abcd_test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//선언부
	int c, d, i, k,j,l,m;
	int ndigit[26];

	//본체부
	for (i = 0; i < 26; ++i)
		ndigit[i] = 0;
	while ((c=getchar())!=EOF)
		if(c>='a'&&c<'z')
			++ndigit[c-'a'];
	for (j = 0; j<26; ++j)
		printf("%c의 개수: %d	", 97 + j, ndigit[j]);
	printf("\n\n");
	
	return 0;
}