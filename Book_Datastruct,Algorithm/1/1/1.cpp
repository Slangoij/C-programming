// 1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>

void triangleLU(int n);
void triangleRU(int n);
void triangleRB(int n);

int main()
{
	int n;
	printf("삼각형 크기: ");
	scanf_s("%d", &n);

	triangleLU(n);
	triangleRU(n);
	triangleRB(n);


    return 0;
}

void triangleLU(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}


void triangleRU(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int h = 0; h < i; h++)
		{
			printf(" ");
		}
		for (int j = 0; j < n - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}



void triangleRB(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			printf(" ");
		}
		for (int h = 0; h < i+1; h++)
		{
			printf("*");
		}
		printf("\n");
	}
}