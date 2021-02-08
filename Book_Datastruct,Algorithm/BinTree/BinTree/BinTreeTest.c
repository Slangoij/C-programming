#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

typedef enum
{
	TERMINATE,ADD,REMOVE,SEARCH,PRINT,PRINT_REV,PRINT_MAX,PRINT_MIN
} Menu;

Menu SelectMenu()
{
	int ch;
	do
	{
		printf("(1)삽입   (2)삭제   (3)검색   \n(4)출력   (5)역순출력 (6)최댓값  (7)최솟값\n(0)종료 : ");
		scanf_s("%d", &ch);
	} while (ch<TERMINATE || ch>PRINT_MIN);
	
	return (Menu)ch;
}

int main()
{
	Menu menu;
	BinNode *root = NULL;

	do
	{
		Member x;
		BinNode *temp;
		switch (menu = SelectMenu())
		{
		case ADD:
			x = ScanMember("삽입", MEMBER_NO | MEMBER_NAME);
			root = Add(root, &x);
			break;
		case REMOVE :
			x = ScanMember("삭제", MEMBER_NO);
			Remove(&root, &x);
			break;
		case SEARCH :
			x = ScanMember("검색", MEMBER_NO);
			if ((temp = Search(root, &x)) != NULL)
				PrintLnMember(&temp->data);
			break;
		case PRINT : 
			puts("☆모든 노드 출력★");
			PrintTree(root);
			break;
		case PRINT_REV :
			puts("★모든 노드 역순 출력☆");
			PrintTreeReverse(root);
			break;
		case PRINT_MAX :
			if (GetMaxNode(root) != NULL)
				printf("%d %s\n", GetMaxNode(root)->data.no, GetMaxNode(root)->data.name);
			else
				printf("루트가 비었습니다.\n");
			break;
		case PRINT_MIN :
			if (GetMinNode(root) != NULL)
				printf("%d %s\n", GetMinNode(root)->data.no, GetMinNode(root)->data.name);
			else
				printf("루트가 비었습니다.\n");
			break;

		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}