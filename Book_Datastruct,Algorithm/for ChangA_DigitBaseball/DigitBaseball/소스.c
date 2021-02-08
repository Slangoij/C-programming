#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;}while(0)

typedef struct
{
	char digit;
	int pos;
} Arrcouple;

void bubble(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		int exchg = 0;
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		if (exchg == 0)
			break;
	}
}

int *makeKey(int level) // 4�ڸ� �迭 ���� �� ����
{
	int *key;
	int odddigit[5] = { 1,3,5,7,9 };
	int evendigit[5] = { 0,2,4,6,8 };

	key = (int *)calloc(4, sizeof(int));

	//level,switch�ȿ� ���� ������ �ݺ�

	if (level == 1) //���̵� ���϶� ��� Ȧ��¦���̰� ������������
	{
		switch (rand() % 2) //���¦���Ǵ� ���Ȧ���� ����
		{
		case 0: //��� Ȧ��
			for (int i = 0; i < 4; i++)
			{
				key[i] = odddigit[rand() % 5];
			}
			while (1) //��ġ������ ��
			{
				int multi = 0; //��ġ�°� �ִ���
				for (int i = 0; i < 4; i++) //�ߺ�Ȯ��
				{
					for (int j = 0; j < i; j++)
					{
						if (key[i] == key[j])
						{
							multi = 1;
							key[i] = odddigit[rand() % 5];
						}
					}
				}
				if (!multi)
					break;
			}
			break;

		case 1:  //��� ¦��
			for (int i = 0; i < 4; i++)
			{
				key[i] = evendigit[rand() % 5];
			}
			while (1)
			{
				//��ġ������ �� 
				int multi = 0; //��ġ�°� �ִ���
				for (int i = 0; i < 4; i++) //�ߺ�Ȯ��
				{
					for (int j = 0; j < i; j++)
					{
						if (key[i] == key[j])
						{
							multi = 1;
							key[i] = evendigit[rand() % 5];
						}
					}
				}
				if (!multi)
					break;
			}
			break;
		}
		bubble(key, 4); //�����Ǵ� �������� ����
		switch (rand() % 2)
		{
		case 0:
			break;
		case 1:
			for (int i = 0; i < 2; i++)
				swap(int, key[i], key[3 - i]);
			break;
		}
	}

	else if (level == 2) //���̵� ���϶� �������� �Ǵ� Ȧ��¦�� ���� �ϳ���
	{
		switch (rand() % 2)
		{
		case 0: //������������
			for (int i = 0; i < 4; i++)
			{
				key[i] = rand() % 10;
			}
			//��ġ����, ���Ȧ��¦���� �ƴ��� �� 
			while (1)
			{
				//�ʱ�ȭ �ʼ�
				int multi = 0;
				int oddpos[4] = { 0,0,0,0 };
				int alleven = 0;
				int allodd = 0;

				for (int i = 0; i < 4; i++) //�ߺ�üũ,Ȧ������ ����
				{
					if ((key[i] % 2) == 1)
					{
						oddpos[i] = 1;
					}
					for (int j = 0; j < i; j++)
					{
						if (key[i] == key[j])
						{
							multi = 1;
						}
					}
				}
				for (int i = 0; i < 4; i++)
				{
					allodd *= oddpos[i];
					alleven += oddpos[i];
				}
				alleven = !alleven;

				if (!multi && !allodd && !alleven)
					break;
				else
					key[rand() % 4] = rand() % 10;
			}
			bubble(key, 4);
			switch (rand() % 2)
			{
			case 0:
				break;
			case 1:
				for (int i = 0; i < 2; i++)
					swap(int, key[i], key[3 - i]);
				break;
			}

			break;
		case 1: //���Ȧ��¦��
			switch (rand() % 2) //���¦���Ǵ� ���Ȧ���� ����
			{
			case 0: //��� Ȧ��
				for (int i = 0; i < 4; i++)
				{
					key[i] = odddigit[rand() % 5];
				}
				break;
			case 1:  //��� ¦��
				for (int i = 0; i < 4; i++)
				{
					key[i] = evendigit[rand() % 5];
				}
				break;
			}
			//������������ �ƴ��� ��
			while (1)
			{
				int multi[4] = { 0,0,0,0 };
				int multione = 0;
				int randind1 = rand() % 4;
				int randind2 = (randind1 + rand() % 3 + 1) % 4;
				int arrup[3] = { 0,0,0 };
				int arrupall = 0;
				int arrdnall = 0;

				for (int i = 0; i < 4; i++) //����Ƚ�� ����
				{
					if ((key[i] < key[i + 1]) && i != 4)
						arrup[i] = 1;
					for (int j = 0; j < i; j++)
					{
						if (key[i] == key[j])
							multi[i] = 1;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					arrupall *= arrup[i];
					arrdnall += arrup[i];
					multione += multi[i];
				}
				arrdnall = !arrdnall;

				if (!multione && !arrupall && !arrdnall)
					break;
				else
				{
					for (int i = 0; i < 4; i++)
						if (multi[i] == 1)
							key[i] = odddigit[rand() % 5];
					if (arrupall || arrdnall)
						swap(int, key[randind1], key[randind2]);
				}

			}

			break;
		}
	}

	else  //���̵� ���϶�
	{
		for (int i = 0; i < 4; i++)
		{
			key[i] = rand() % 10;
		}
		while (1)
		{
			int multi = 0; //��ġ�°� �ִ���
			int oddpos[4] = { 0,0,0,0 };
			int allodd = 0;
			int alleven = 0;
			int arrup[3] = { 0,0,0 };
			int arrupall = 0;
			int arrdnall = 0;

			for (int i = 0; i < 4; i++) //�ߺ�Ȯ��
			{
				for (int j = 0; j < i; j++)
				{
					if (key[i] == key[j])
						multi = 1;
				}
				if ((key[i] < key[i + 1]) && i != 4)
					arrup[i] = 1;
				if ((key[i] % 2) == 1)
					oddpos[i] = 1;
			}
			for (int i = 0; i < 4; i++)
			{
				if (i != 4)
				{
					arrupall *= arrup[i];
					arrdnall += arrup[i]; 
				}
				allodd *= oddpos[i];
				alleven += oddpos[i];
			}
			alleven = !alleven;
			arrdnall = !arrdnall;


			if (multi == 0 && !allodd && !alleven && !arrupall && !arrdnall)
				// ��� Ȧ��,¦���� �ƴϰ� ����,�������� ���ĵ� �ƴ϶�� �����Ϸ�
				break;
			else
				key[rand() % 4] = rand() % 10;
		}		
	}

	return key;
}

void triArr(int *key) //
{
	int trinum = 0; //��
	Arrcouple keycouple[4];
	Arrcouple targetcouple[4];
	char keyinsert[5];
	char a[1];

	for (int i = 0; i < 4; i++)
	{
		keycouple[i].digit = key[i];
		keycouple[i].pos = i;
	}

	while (1) // ������� ������ �Է� �ް� �ϰ� ��� ���
	{
		trinum++; //�� ��

		while (1)  //���� ���� ����� �Է��Ҷ����� �Է¹ޱ�
		{
			printf("������� ���ڿ��� �Է��ϼ��� : ");
			scanf_s("%s", &keyinsert, sizeof(keyinsert));

			int checkall = 0;

			for (int i = 0; i < 4; i++) //���Ŀ� ������ targetcoulpe�� ������� �ְ� �ƴϸ� �ٽ�
			{
				targetcouple[i].pos = i;
				a[0] = keyinsert[i];

				if (atoi(a) < 0 || atoi(a) > 9)
				{
					checkall = 1;
				}
				else
					targetcouple[i].digit = atoi(a);
			}

			if (checkall == 0)  //üũ�ϱ�
				break;
			else
				printf("���ڸ� �Է��Ͻÿ�\n");
		}

		int ball = 0;
		int strike = 0;
		for (int i = 0; i < 4; i++) //��, ��Ʈ����ũ ���
		{
			for (int j = 0; j < 4; j++)
			{
				if (targetcouple[i].digit == keycouple[j].digit)
				{
					if (targetcouple[i].pos == keycouple[j].pos)
					{
						strike++;
					}
					else
						ball++;
				}
			}
		}

		printf("\n���� �� Ƚ���� : %d, \n����� : ", trinum);
		if (strike == 4)
		{
			printf("\t�����Դϴ�!\n\n");
			break;
		}
		if (ball == 0 && strike == 0)
			printf("\tOUT\n\n");
		else

			printf("%d S %d B\n\n", strike, ball);
	}
}

int main()
{
	int *key; //��ǻ�Ͱ� ������ ����
	int level = 1; //�Է¹��� ����
	while (1)
	{
		printf("��ǻ�Ϳ� ���ھ߱� �����մϴ�\n���̵��� �����ϼ���");
		printf("\n""��""�� 1��, ""��""�� 2��, ""��""�� 3�� �Է��ϼ��� : ");
		scanf_s("%d", &level);
		if (level != 1 && level != 2 && level != 3)
			printf("1 �Ǵ� 2 �Ǵ� 3�� �ƴմϴ�.\n");
		else
			break;
	}

	srand((int)time(NULL));
	key = makeKey(level);

	printf("\n���ڰ� �����Ǿ����ϴ�. �������� ���纸����\n=============================================\n\n");

	/*
	for (int j = 0; j < 100; j++)
	{
		key = makeKey(level);

		printf("������ ");
		for (int i = 0; i < 4; i++)
		{
			printf("%d ", key[i]);
		}
		printf("�Դϴ�.\n");

	}
	*/

	triArr(key);

	free(key);

	return 0;
}