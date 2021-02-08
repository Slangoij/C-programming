#include <stdio.h>
#include <stdlib.h>
#include "IntQue.h"

int Initialize(IntQue *q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	for (int i = 0; i < max; i++)
	{
		q->que[i] = 0;
	}
	return 0;
}

int Enque(IntQue *q, int x)
{
	if (q->num >= q->max)
		return -1;
	else 
	{
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

int Deque(IntQue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

int Peek(const IntQue *q, int *x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

void Clear(IntQue *q)
{
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntQue *q)
{
	return q->max;
}

int Size(const IntQue *q)
{
	return q->num;
}

int IsEmpty(const IntQue *q)
{
	return q->num <= 0;
}

int IsFull(const IntQue *q)
{
	return q->num >= q->max;
}

int Search(const IntQue *q, int x)
{
	int i, idx;
	for (i = 0; i < q->num; i++)
	{
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

void Print(const IntQue *q)
{
	int i;
	for (i =0 ; i < q->max; i++)
	{
		printf("%d ", q->que[i]);
		//printf("%d ", q->que[(i + q->front) % q->max]);
	}
	putchar('\n');
}

void Terminate(IntQue *q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}