#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_match(const char txt[], const char pat[])
{
	int pt;
	int pp;
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1];
	for (pt = 0; pt <= UCHAR_MAX; pt++)
		skip[pt] = pat_len;
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;

	//비출력용
	/*
	while (pt < txt_len)
	{
		pp = pat_len - 1;
		while (txt[pt] == pat[pp])
		{
			if (pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}
	return -1;
	*/

	//출력용
	int try = 0;
	while (pt < txt_len)
	{
		pp = pat_len - 1;
		printf("%2d ", pt - pp);

		while (txt[pt] == pat[pp])
		{
			if (pp != pat_len - 1)
				printf("   ");
			printf("%s\n   ", txt);
			for (int i = 0; i < pt; i++)
				printf(" ");
			printf("+\n   ");
			for (int i = 0; i < pt - pp; i++)
				printf(" ");
			printf("%s\n", pat);

			if (pp == 0)
				return pt;
			pp--;
			pt--;
			try++;
		}
		
		printf("%s\n   ", txt);
		for (int i = 0; i < pt; i++)
			printf(" ");
		printf("|\n   ");
		for (int i = 0; i < pt - pp; i++)
			printf(" ");
		printf("%s\n", pat);
		
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
		try++;
	}
	printf("비교를 %d회 시도합니다.\n",try);

	return -1;
}

int main()
{
	int idx;
	char s1[256];
	char s2[256];
	puts("Boyer-Moore법");
	printf("텍스트 : ");
	scanf_s("%s", s1, sizeof(s1));
	printf("패턴 : ");
	scanf_s("%s", s2, sizeof(s2));
	idx = bm_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.\n");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}