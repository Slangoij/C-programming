#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void insertion(int a[],int idx, int n)
{
	for (int i = idx; i < n+1; i++)
	{
		int j;
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

void quick(int a[], int left, int right)
{
	IntStack lstack;
	IntStack rstack;
	
	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack))
	{
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];

		int i;
		printf("a[%d]~a[%d] : {", left, right);
		for (i = left; i < right; i++)
			printf("%d, ", a[i]);
		printf("%d}\n", a[right]);

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

		if ((pr - left) >= (right - pl))
		{
			if (left < pr)
			{
				if ((pr - left) >= 9)
				{
					Push(&lstack, left);
					Push(&rstack, pr);
				}
				else
					insertion(a, left, pr);
			}
			
			if (pl < right)
			{
				if ((right - pl) >= 9)
				{
					Push(&lstack, pl);
					Push(&rstack, right);
				}
				else
					insertion(a, pl, right);
				
			}
		}
		else
		{
			if (pl < right)
			{
				if ((right - pl) >= 9)
				{
					Push(&lstack, pl);
					Push(&rstack, right);
				}
				else
					insertion(a, pl, right);

			}

			if (left < pr)
			{
				if ((pr - left) >= 9)
				{
					Push(&lstack, left);
					Push(&rstack, pr);
				}
				else
					insertion(a, left, pr);
			}
		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
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