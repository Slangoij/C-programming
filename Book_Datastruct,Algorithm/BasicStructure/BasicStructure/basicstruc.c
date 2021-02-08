#include <stdio.h>

int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;

	if (x == 0)
	{
		d[digits++] = dchar[0];
	}
	else
	{
		while (x != 0)
			d[digits++] = dchar[x%n];
		x /= n;
	}

	return 0;
}

int main()
{
	unsigned no; /*변환할 정수*/
	int cd;  /*진법수*/
	int dno; /*변환된 결과*/
	char cno[1000];  /*변환한 값의 각 자리숫자 저장할 배열*/
	int retry; /*한번더할지 여부*/

	printf("10진수를 기수 변환합니다.");
	while (retry == 1)
	{
		printf("변환하는 음이 아닌 정수: ");
		scanf("%u", &no);
		while (cd < 2 || cd>36)
		{
			printf("어떤 진수로 변환할까요?(2-36): ");
			scanf("%d", &cd);
		}
		dno = card_convr(no, cd, cno);
		printf("%d진수로는", cd);
		for (int i = dno - 1; i >= 0; i--)
		{
			printf("%c");
		}
		printf("입니다.");
	}

	return 0;
}











