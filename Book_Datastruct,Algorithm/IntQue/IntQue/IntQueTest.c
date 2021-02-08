#include <stdio.h>
#include "IntQue.h"

int main()
{
	IntQue que;
	int j;

	printf("�ִ� ť size�� �Է��ϼ��� : \n");
	scanf_s("%d", &j, sizeof(j));
	if (Initialize(&que, j) == -1)
	{
		puts("ť ���� ����");
		return 1;
	}

	while (1)
	{
		int m, x;

		printf("���� ������ �� : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (0)���� : ");
		scanf_s("%d", &m);

		if (m == 0)
			break;
		switch (m)
		{
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a���� : ��ť�� ����");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a���� : ��ť�� ����");
			else
				printf("��ť�� �����ʹ� %d\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a���� : ��ũ�� ����");
			else
				printf("��ũ�� �����ʹ� %d\n", x);
			break;
		case 4:
			Print(&que);
			break;
		}
	}
	Terminate(&que);
	return 0;
}