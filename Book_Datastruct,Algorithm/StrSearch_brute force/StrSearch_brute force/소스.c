#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
	int pt = 0;
	int pp = 0;
	int patpos = 0;
	int try = 0;
	while (txt[pt] != '\0'&&pat[pp] != '\0')
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
			for (int i = 0; i < pt-pp; i++)
				printf(" ");
			printf("   %s\n\n", pat);
			pt++;
			pp++;
		}
		else
		{
			printf("   |\n");
			for (int i = 0; i < pt-pp; i++)
				printf(" ");
			printf("   %s\n\n", pat);
			pt = pt - pp + 1;
			pp = 0;
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
	puts("브루트-포스법");
	printf("텍스트 : ");
	scanf_s("%s", s1,256);
	printf("패턴 : ");
	scanf_s("%s", s2,256);
	idx = bf_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}