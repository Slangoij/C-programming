// abcd_test.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	//�����
	int c, d, i, k,j,l,m;
	int ndigit[26];

	//��ü��
	for (i = 0; i < 26; ++i)
		ndigit[i] = 0;
	while ((c=getchar())!=EOF)
		if(c>='a'&&c<'z')
			++ndigit[c-'a'];
	for (j = 0; j<26; ++j)
		printf("%c�� ����: %d	", 97 + j, ndigit[j]);
	printf("\n\n");
	
	return 0;
}