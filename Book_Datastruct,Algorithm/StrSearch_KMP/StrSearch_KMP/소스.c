#include <stdio.h>

int kmp_match(const char txt[], const char pat[])
{
	int pt = 1;
	int pp = 0;
	int skip[1024];

	skip[pt] = 0;
	while (pat[pt] != '\0')
	{
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if (pp == 0)
			skip[++pt] = pp;
		else
			pp = skip[pp];
	}
	
	for (int i = 2; skip[i] != '\0'; i++)
	{
		printf("%d ", skip[i]);
	}
	printf("\n");

	pt = pp = 0;
	int patpos = 0;
	int try = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (pt == patpos)
			printf("%2d ", patpos);
		else
			printf("   ");

		printf("%s\n", txt);
		for (int i = 0; i < pt; i++)
			printf(" ");

		if (txt[pt] == pat[pp])
		{
			printf("   +\n");
			for (int i = 0; i < pt - pp; i++)
				printf(" ");
			printf("   %s\n\n", pat);
			pt++;
			pp++;
		}
		else if (pp == 0)
		{
			printf("   |\n");
			for (int i = 0; i < pt - pp; i++)
				printf(" ");
			printf("   %s\n\n", pat);
			pt = pt - pp + 1;
			pp = 0;
			patpos = pt;
		}
		else
		{
			printf("   |\n");
			for (int i = 0; i < pt - pp; i++)
				printf(" ");
			printf("   %s\n\n", pat);
			pp = skip[pp];
			patpos = pt;
		}
		try++;
	}
	printf("비교를 %d회 시도합니다.\n", try);
	if (pat[pp] == '\0')
		return pt - pp;

	return -1;
}

int main()
{
	int idx;
	char s1[256];
	char s2[256];
	puts("KMP법");
	printf("텍스트 : ");
	scanf_s("%s", s1, sizeof(s1));
	printf("패턴 : ");
	scanf_s("%s", s2, sizeof(s2));
	idx = kmp_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.\n");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}