#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

int cpr;
int swp;

void bubble(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		printf("�н� %d : \n", i);
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

	puts("���� ����");
	printf("��� ���� :");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);
	
	/*
	puts("������������ �����߽��ϴ�.");
	for (int i = 0; i < nx; i++)
		printf("x[%d] =%d\n", i, x[i]);
		*/
	printf("\n�񱳸� %dȸ �߽��ϴ�.", cpr);
	printf("\n��ȯ�� %dȸ �߽��ϴ�.\n", swp);

	free(x);

	return 0;
}