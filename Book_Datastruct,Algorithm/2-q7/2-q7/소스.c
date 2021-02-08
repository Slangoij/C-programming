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
	unsigned no; /*��ȯ�� ����*/
	int cd;  /*������*/
	int dno; /*��ȯ�� ���*/
	char cno[1000];  /*��ȯ�� ���� �� �ڸ����� ������ �迭*/
	int retry; /*�ѹ������� ����*/

	puts("10������ ��� ��ȯ�մϴ�.");
	do
	{
		printf("��ȯ�ϴ� ���� �ƴ� ����: ");
		scanf_s("%u", &no);
		do
		{
			printf("� ������ ��ȯ�ұ��?(2-36): ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd>36);
		dno = card_convr(no, cd, cno);

		printf("%d�����δ�", cd);
		for (int i = dno - 1; i >= 0; i--)
		{
			printf("%c", cno[i]);
		}
		printf("�Դϴ�.\n");



		printf("��� �ұ��?(1��/0�ƴϿ�)");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}











