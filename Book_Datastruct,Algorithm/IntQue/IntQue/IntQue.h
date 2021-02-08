#ifndef ___IntQue
#define ___IntQue

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int *que;
} IntQue;

int Initialize(IntQue *q, int max);

int Enque(IntQue *q, int x);

int Deque(IntQue *q, int *x);

int Peek (const IntQue *q, int *x);

void Clear(IntQue *q);

int Capacity(const IntQue *q);

int Size(const IntQue *q);

int IsEmpty(const IntQue *q);

int IsFull(const IntQue *q);

int Search(const IntQue *q, int x);

void Print(const IntQue *q);

void Terminate(IntQue *q);
#endif