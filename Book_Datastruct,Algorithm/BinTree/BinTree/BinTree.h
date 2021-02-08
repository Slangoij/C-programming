#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

typedef struct __bnode
{
	Member data;
	struct __bnode *left;
	struct __bnode *right;
} BinNode;

BinNode *Search(BinNode *p, const Member *x);
BinNode *Add(BinNode *p, const Member *x);
int Remove(BinNode **root, const Member *x);
void PrintTree(const BinNode *p);
void FreeTree(BinNode *p);
void PrintTreeReverse(const BinNode *p);
BinNode *GetMinNode(const BinNode *p);
BinNode *GetMaxNode(const BinNode *p);

#endif