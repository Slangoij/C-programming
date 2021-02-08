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
		printf("(1)����   (2)����   (3)�˻�   \n(4)���   (5)������� (6)�ִ�  (7)�ּڰ�\n(0)���� : ");
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
			x = ScanMember("����", MEMBER_NO | MEMBER_NAME);
			root = Add(root, &x);
			break;
		case REMOVE :
			x = ScanMember("����", MEMBER_NO);
			Remove(&root, &x);
			break;
		case SEARCH :
			x = ScanMember("�˻�", MEMBER_NO);
			if ((temp = Search(root, &x)) != NULL)
				PrintLnMember(&temp->data);
			break;
		case PRINT : 
			puts("�ٸ�� ��� ��¡�");
			PrintTree(root);
			break;
		case PRINT_REV :
			puts("�ڸ�� ��� ���� ��¡�");
			PrintTreeReverse(root);
			break;
		case PRINT_MAX :
			if (GetMaxNode(root) != NULL)
				printf("%d %s\n", GetMaxNode(root)->data.no, GetMaxNode(root)->data.name);
			else
				printf("��Ʈ�� ������ϴ�.\n");
			break;
		case PRINT_MIN :
			if (GetMinNode(root) != NULL)
				printf("%d %s\n", GetMinNode(root)->data.no, GetMinNode(root)->data.name);
			else
				printf("��Ʈ�� ������ϴ�.\n");
			break;

		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}