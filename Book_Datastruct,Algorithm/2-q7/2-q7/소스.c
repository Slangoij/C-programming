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
		{
			int t = x;
			d[digits++] = dchar[x%n];
			x /= n;

			printf("%d | %5d ....... %c\n", n, t, d[digits-1]);
			printf("  + ------\n");
		}
		printf("        0\n");
	}

	return digits;
}

int main()
{
	unsigned no; /*변환할 정수*/
	int cd;  /*진법수*/
	int dno; /*변환된 결과*/
	char cno[1000];  /*변환한 값의 각 자리숫자 저장할 배열*/
	int retry; /*한번더할지 여부*/

	puts("10진수를 기수 변환합니다.");
	do
	{
		printf("변환하는 음이 아닌 정수: ");
		scanf_s("%u", &no);
		do
		{
			printf("어떤 진수로 변환할까요?(2-36): ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd>36);
		dno = card_convr(no, cd, cno);

		printf("%d진수로는", cd);
		for (int i = dno - 1; i >= 0; i--)
		{
			printf("%c", cno[i]);
		}
		printf("입니다.\n");



		printf("계속 할까요?(1예/0아니오)");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}











