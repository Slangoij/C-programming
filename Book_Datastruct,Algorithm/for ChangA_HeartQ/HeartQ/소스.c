#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_level 3

int selmun(int level);
void heartdraw(int level);

//���� 3��
/*int a;
printf("\nsdflnsdf");
scanf_s("%d", &a);
system("cls");*/

void main() //����ġ�� �� �ѱ� ����, �� ���̽����� ���� �� �� �ѱ��
			//heartshape�Լ��� �������� ��Ʈ��� ��� ����
{
	printf("\n   �ȳ��ϻ���. ����ũ���ֿ�. ���ݺ��� �־��� ������ ������ ��� ������ ���߾� ����� �ϸ� �ǿ�.");

	for (int k = 1; k <= max_level; k++)
	{
		if (selmun(k) == 1)
		{
			heartdraw(k);
		}
	}
}

int selmun(int level)
{
	int j = 0;
	char a[50];
	char b[] = "9��27��";
	char c[] = "896��";
	char d[] = "������";

	switch (level)
	{
	case 1:
		while (j == 0)
		{
			printf("\n\n   â���� ������?(m��dd��)�������� ����ϻ���.\n   "); //����1
			scanf_s("%s", a, sizeof(a));
			if (strcmp(a, b) == 0)
			{
				j = 1;
				break;
			}
			printf("\n   Ʋ�Ⱦ��.");
		}

		break;

	case 2:
		while (j == 0)
		{
			printf("\n\n   ���� �츮�� ������ ��ĥ°�ֿ�? (ddd��)�������� ����ϻ���\n   "); //����1
			scanf_s("%s", &a, 50);
			if (strcmp(a, c) == 0)
			{
				j = 1;
				break;
			}
			printf("\n   Ʋ�Ⱦ��.");
		}

		break;

	case max_level:
		while (j == 0)
		{
			printf("\n\n   â�ƴ� �������ֿ̾�?(ij��)�������� ����ϻ���\n   "); //����1
			scanf_s("%s", &a, 50);
			if (strcmp(a, d) == 0)
			{
				j = 1;
				break;
			}
			printf("\n   Ʋ�Ⱦ��.");
		}

		break;
	}

	return j;
}


void heartdraw(int level)
{
	switch (level)
	{
	case 1:
		system("cls");
		printf("\n ____   ____");
		printf("\n/    | /    |");

		break;

	case 2:
		system("cls");
		printf("\n ____   ____");
		printf("\n/    | /    |");
		printf("\n|          /");
		printf("\n|        /");

		break;

	case max_level:
		system("cls");
		printf("\n ____   ____");
		printf("\n/    | /    |");
		printf("\n|          /");
		printf("\n|        /");
		printf("\n|      /");
		printf("\n|____/");

		break;
	}
}