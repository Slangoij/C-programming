#include <stdio.h>
#include <stdlib.h>

void merge(const int a[], int na, const int b[], int nb, int c[])
{
	int pa = 0;
	int pb = 0;
	int pc = 0;
	while (pa < na&&pb < nb)
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
	while (pa < na)
		c[pc++] = a[pa++];
	while (pb < nb)
		c[pc++] = b[pb++];
}

int main()
{
	int i, na, nb;
	int *a, *b, *c;
	printf("a의 요소 개수 : ");
	scanf_s("%d", &na);
	printf("b의 요소 개수 : ");
	scanf_s("%d", &nb);

	a = calloc(na, sizeof(int));
	b = calloc(nb, sizeof(int));
	c = calloc(na + nb, sizeof(int));

	printf("a[0] : ");
	scanf_s("%d", &a[0]);
	for (int i = 0; i < na; i++)
	{
		while (a[i] < a[i - 1])
		{
			printf("a[%d] : ", i);
			scanf_s("%d", &a[i]);
		}
	}
	printf("b[0] : ");
	scanf_s("%d", &b[0]);
	for (int i = 0; i < nb; i++)
	{
		while (b[i] < b[i - 1])
		{
			printf("b[%d] : ", i);
			scanf_s("%d", &b[i]);
		}
	}

	merge(a, na, b, nb, c);
	puts("배열 a와 b를 병합하여 배열 c에 저장했습니다.");
	for (i = 0; i < na + nb; i++)
		printf("c[%2d] = %2d\n", i, c[i]);

	free(a);
	free(b);
	free(c);

	return 0;
}