#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)

void bubbledn(int a[], int n, int lastdn, int lastup);
void bubbleup(int a[], int n, int lastdn, int lastup);

int main()
{
	int i, nx;
	int *x;

	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	int lastdn = 0;
	int lastup = nx - 1;

	x = (int *)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubbledn(x, nx,lastdn,lastup);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);


	free(x);

	return 0;
}

void bubbledn(int a[], int n,int lastdn,int lastup)
{
	int k = 0;
	if (lastdn < n - 1)
	{
		for (int j = n - 1; j > lastdn; j--)
			if (a[j - 1] > a[j])
			{
				printf("버블다운, %d\n",j);
				swap(int, a[j - 1], a[j]);
				k = j;
			}
		lastdn = k;
		bubbleup(a, n, lastdn, lastup);
	}	
}

void bubbleup(int a[], int n,int lastdn, int lastup)
{
	int k = 0;
	if (lastup > 0 )
	{
		lastup = n - 1;
		for (int j = 0; j<lastup; j++)
			if (a[j] > a[j + 1])
			{
				printf("버블업, %d\n",j);
				swap(int, a[j], a[j + 1]);
				k = j;
			}
		lastup = k;
		bubbledn(a, n, lastdn, lastup);
	}
}