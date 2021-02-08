#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

typedef struct __node
{
	Member data;
	struct __node *next;
} Node;

typedef struct
{
	Node *head;
	Node *crnt;
} List;

void Initialize(List *list);
Node *search(List *list, const Member *x, int campare(const Member *x, const Member *y));
Node *Retrieve(List *list, int n);
void InsertFront(List *list, const Member *x);
void InsertRear(List *list, const Member *x);
void RemoveFront(List *list);
void RemoveRear(List *list);
void RemoveCurrent(List *list);
void Purge(List *list, int compare(const Member *x, const Member *y));
void Clear(List *list);
void PrintfCurrent(const List *list);
void PrintLnCurrent(const List *list);
void Print(const List *list);
void Terminate(List *list);

#endif