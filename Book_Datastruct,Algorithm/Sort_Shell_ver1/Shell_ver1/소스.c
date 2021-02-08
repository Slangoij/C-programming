#include <stdio.h>
#include <stdlib.h>

int shell0(int a[], int n, int count)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int tmp = a[i];
		for (j = i; j > 0 && a[j-1] > tmp; j--)
		{
			a[j] = a[j - 1];
			count++;
		}
		a[j] = tmp;
	}

	return count;
}

int shell1(int a[], int n, int count)
{
	int i, j, h;
	for (h = n / 2; h>0; h /= 2)
		for (i = h; i < n; i++)
		{
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
			{
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
		}

	return count;
}

int shell2(int a[], int n, int count)
{
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;
	for (; h>0; h /= 3)
		for (i = h; i < n; i++)
		{
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
			{
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
		}

	return count;
}

int main()
{
	int i, nx;
	int *x0;
	int *x1;
	int *x2;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;

	puts("셸 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x0 = calloc(nx, sizeof(int));
	x1 = calloc(nx, sizeof(int));
	x2 = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x0[i]);
		x2[i] = x1[i] = x0[i];
	}
	putchar('\n');

	count0 = shell0(x0, nx, count0);
	count1= shell1(x1, nx, count1);
	count2=shell2(x2, nx, count2);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x2[i]);

	printf("\nshell0의 이동횟수는 %d입니다.\n", count0);
	printf("shell1의 이동횟수는 %d입니다.\n", count1);
	printf("shell2의 이동횟수는 %d입니다.\n\n", count2);

	free(x0);
	free(x1);
	free(x2);

	return 0;
}