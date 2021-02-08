#include <stdio.h>
#include <stdlib.h>

//버전 1
/*
int search(const int a[], int n, int key)
{
	int i = 0;
	while (1)
	{
		if (i == n)
			return -1;
		if (a[i] == key)
			return i;
		i++;
	}
} 
*/

//버전 2

int search(const int a[], int n, int key) 
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == key)
			return i;
	return -1;
}


int main()
{
	int i, nx, ky, idx;
	int *x;
	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("검색값 : ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
	free(x);

	return 0;
}

