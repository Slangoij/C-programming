#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXArraysize 10

void drawArray(int x[], int nx)
{
	for (int i = 0; i < nx; i++)
		printf("%3d", x[i]);
	printf("\n");
}

void drawArrow(int x[], int pl, int pc, int pr)
{
	for (int i = 0; i <= pr; i++)
	{
		if (i == pl)
			printf(" <-");
		else if (i == pc)
			printf("  +");
		else if (i == pr)
			printf(" ->");
		else
			printf("   ");
	}
	printf("\n");
}

int search(int x[], int key,int nx)
{
	int pl = 0;
	int pr = nx - 1;
	int pc;

	while (pl <= pr)
	{
		pc = (pl + pr) / 2;
		if (x[pc] == key)
			return pc;
		else if (x[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	}
	return -1;
}

int main()
{
	int i, key;
	int *x;
	srand(time(NULL));
	x = calloc(MAXArraysize, sizeof(int));
	
	x[0] = 0;
	for (i = 1; i < MAXArraysize; i++)
	{
		x[i] = x[i - 1] + rand() % 2 + 1;
	}
	printf("찾을 값을 입력하시오 : ");
	scanf_s("%d", &key);

	printf("\n   |");
	for (int i = 0; i < MAXArraysize; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	printf("---+-------------------------------\n");

	int pl = 0;
	int pr = MAXArraysize - 1;
	int pc = (pl + pr) / 2;
	while (pl<=pc && pc<=pr)
	{
		printf("   |");
		drawArrow(x, pl, pc, pr);
		printf("%3d|", pc);
		drawArray(x, MAXArraysize);
		printf("   |\n");

		if (x[pc] == key)
			break;
		else if (x[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
		pc = (pl + pr) / 2;
	}
	



	if (search(x, key, MAXArraysize) == -1)
		printf("\n찾는 값이 없습니다.\n");
	else
		printf("\n%d는 x[%d]에 있습니다.\n", key, search(x, key, MAXArraysize));

	free(x);
}