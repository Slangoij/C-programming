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
	unsigned no; /*��ȯ�� ����*/
	int cd;  /*������*/
	int dno; /*��ȯ�� ���*/
	char cno[1000];  /*��ȯ�� ���� �� �ڸ����� ������ �迭*/
	int retry; /*�ѹ������� ����*/

	printf("10������ ��� ��ȯ�մϴ�.");
	while (retry == 1)
	{
		printf("��ȯ�ϴ� ���� �ƴ� ����: ");
		scanf("%u", &no);
		while (cd < 2 || cd>36)
		{
			printf("� ������ ��ȯ�ұ��?(2-36): ");
			scanf("%d", &cd);
		}
		dno = card_convr(no, cd, cno);
		printf("%d�����δ�", cd);
		for (int i = dno - 1; i >= 0; i--)
		{
			printf("%c");
		}
		printf("�Դϴ�.");
	}

	return 0;
}











