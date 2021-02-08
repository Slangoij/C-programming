#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

int cpr;
int swp;

void bubble(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		printf("패스 %d : \n", i);
		for (int j = n - 1; j > i; j--)
		{
			cpr++;
			printf("%4d", a[0]);
			for (int k = 1; k < n; k++)
			{
				if (k == j)
					if (a[j - 1] > a[j])
					{
						printf(" +%2d", a[k]);
						swap(int, a[j - 1], a[j]);
						swp++;
					}
					else
						printf(" -%2d", a[k]);
				else
					printf("%4d", a[k]);
			}
			putchar('\n');
		}		
	}
}

int main()
{
	int i, nx;
	int *x;

	puts("버블 정렬");
	printf("요소 개수 :");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);
	
	/*
	puts("오름차순으로 정렬했습니다.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] =%d\n", i, x[i]);
		*/
	printf("\n비교를 %d회 했습니다.", cpr);
	printf("\n교환을 %d회 했습니다.\n", swp);

	free(x);

	return 0;
}