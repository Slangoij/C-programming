#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void quick(int a[], int left,int right)
{
	int pl = left;
	int pr = right;
	int x = a[(pl+pr) / 2];
	while (pl <= pr)
	{
		while (a[pl] < x)
			pl++;
		while (a[pr] > x)
			pr--;
		if (pl <= pr)
		{
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	}

	if ((pr - left) > (right - pl))
	{
		if (left < pr)
			quick(a, left, pr);
		if (pl < right)
			quick(a, pl, right);
	}
	else
	{
		if (pl < right)
			quick(a, pl, right);
		if (left < pr)
			quick(a, left, pr);
	}
	
	/*
	printf("피벗의 값은 %d입니다.\n", x);
	printf("피벗 이하의 그룹\n");
	for (int i = 0; i <= pl - 1; i++)
		printf("%d ", a[i]);
	putchar('\n');
	if (pl > pr + 1)
	{
		printf("피벗과 일치하는 그룹\n");
		for (int i = pr + 1; i <= pr - 1; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	printf("피벗 이상의 그룹\n");
	for (int i = pr + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
	*/
	
}

int main()
{
	int i, nx;
	int *x;

	puts("배열을 나눕니다. ");
	printf("요소 개수 :");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	quick(x, 0, nx - 1);

	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] =%d\n", i, x[i]);
	/*
	
	printf("\n비교를 %d회 했습니다.", cpr);
	printf("\n교환을 %d회 했습니다.\n", swp);
	*/


	free(x);

	return 0;
}