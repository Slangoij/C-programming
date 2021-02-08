#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_level 3

int selmun(int level);
void heartdraw(int level);

//질문 3개
/*int a;
printf("\nsdflnsdf");
scanf_s("%d", &a);
system("cls");*/

void main() //스위치문 턴 넘길 변수, 각 케이스에서 질문 후 턴 넘기기
			//heartshape함수에 보상으로 하트모양 출력 구현
{
	printf("\n   안녕하새오. 제핑크스애오. 지금부터 주어진 문제에 정해진 답과 형식을 맞추어 대답을 하면 되오.");

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
	char b[] = "9월27일";
	char c[] = "896일";
	char d[] = "인제편";

	switch (level)
	{
	case 1:
		while (j == 0)
		{
			printf("\n\n   창아의 생일은?(m월dd일)형식으로 대답하새오.\n   "); //질문1
			scanf_s("%s", a, sizeof(a));
			if (strcmp(a, b) == 0)
			{
				j = 1;
				break;
			}
			printf("\n   틀렸어오.");
		}

		break;

	case 2:
		while (j == 0)
		{
			printf("\n\n   오늘 우리가 만난지 며칠째애오? (ddd일)형식으로 대답하새오\n   "); //질문1
			scanf_s("%s", &a, 50);
			if (strcmp(a, c) == 0)
			{
				j = 1;
				break;
			}
			printf("\n   틀렸어오.");
		}

		break;

	case max_level:
		while (j == 0)
		{
			printf("\n\n   창아는 누구편이애오?(ij편)형식으로 대답하새오\n   "); //질문1
			scanf_s("%s", &a, 50);
			if (strcmp(a, d) == 0)
			{
				j = 1;
				break;
			}
			printf("\n   틀렸어오.");
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