#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const char *some1,const char *some2)
{
	return strcmp(some1, some2);
}

void print(const char some[][7], int no)
{
	for (int i = 0; i < no; i++)
		printf("%s\n", some[i]);
}

void printp(const char *some[], int no)
{
	for (int i = 0; i < no; i++)
		printf("%s\n", some[i]);
}

int main()
{
	char a[][7] = { "LISP","C","Ada","Pascal" };
	char *p[] = { "LISP","C","Ada","Pascal" };

	printf("정렬전\n");
	print(a, 4);

	qsort(a, 4, sizeof(a[0]), (int(*)(const void *, const void *))cmp);
	qsort(p, 4, sizeof(p[0]), (int(*)(const void *, const void *))cmp);

	printf("\n""a""의 상태는\n");
	print(a, 4);
	printf("\n""p""의 상태는\n");
	printp(p, 4);

	return 0;
}