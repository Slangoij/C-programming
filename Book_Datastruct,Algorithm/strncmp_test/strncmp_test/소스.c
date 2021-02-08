#include <stdio.h>
#include <string.h>

//strncmp와 같은 동작하는 함수
int str_ncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	for (i = 0; i < (int)n; i++)
	{
		if (s1[i] > s2[i])
			return 1;
		if (s1[i] < s2[i])
			return -1;
	}
	if (i == n)
		return 0;
}

//알파벳 대소문자 구분않고 두문자열 비교하는 함수
int str_ncmpic(const char *s1, const char *s2, size_t n)
{
	char *s3 = s1;
	char *s4 = s2;

	for (int i = 0; i < (int)n; i++)
	{
		if (s1[i] >= 'a'&&s1[i] <= 'z')
			s3[i] = s1[i] - 32;
		if (s2[i] >= 'a'&&s2[i] <= 'z')
			s4[i] = s2[i] - 32;
	}
	return str_ncmp(s3, s4, n);
}

int main()
{
	char st[128];
	puts("\"STRING\"의 처음 3개 문자와 비교합니다.");
	puts("\"XXXX\"를 입력하면 종료합니다.");
	while (1)
	{
		printf("문자열 st : ");
		scanf_s("%s", st,128);
		if (str_ncmpic("XXXX", st, 3) == 0)
			break;
		printf("str_ncmpic(\"STRING\",st,3) = %d\n", str_ncmpic("STRING", st, 3));
	}

	return 0;
}