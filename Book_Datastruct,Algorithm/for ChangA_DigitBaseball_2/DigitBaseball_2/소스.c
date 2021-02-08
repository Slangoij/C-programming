#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

typedef struct
{
	char digit;
	int pos;
} Arrcouple;

int odddigit[5] = { 1,3,5,7,9 };
int evendigit[5] = { 0,2,4,6,8 };

void bubbleup(int a[], int n)
{
	
	for (int i = 0; i < n - 1; i++)
	{
		int exchg = 0;
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		if (exchg == 0)
			break;
	}
}

void bubbledn(int a[], int n)
{

	for (int i = n-1; i >0; i--)
	{
		int exchg = 0;
		for (int j = 0; j < i; j++)
			if (a[j] < a[j+1])
			{
				swap(int, a[j], a[j+1]);
				exchg++;
			}
		if (exchg == 0)
			break;
	}
}

int *makeKey(int level) // ������ ���� 4�ڸ� �迭 ���� �� ����
{
	int *key;

	key = (int *)calloc(4, sizeof(int));

	for (int i = 0; i < 4; i++)
	{
		key[i] = rand() % 10;
	}
	while (1) // �迭 �ߺ� Ȯ��
	{
		int k = 0; //��ġ�°� �ִ��� Ȯ�ο� ����
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (key[i] == key[j] )
				{
					k = 1;
					if (level == 1 )
						if ((key[1] % 2) == 1)
							key[i] = odddigit[rand() % 5];
						else
							key[i] = evendigit[rand() % 5];
					else
							key[i] = rand() % 10;
				}
			}
		}
		if (k == 0)
			break;
	}

	return key;
}

int *reArr(int *key, int level)
{
	int oddpos[4] = { 0,0,0,0 }; //��� Ȧ�� ����
	int oddnum = 0;
	int allodd = 0;
	int alleven = 0;
	int arrup[3] = { 0,0,0 }; //�ڰ� ū �� ����
	int arrupnum = 0;
	int arrupall = 0;
	int arrdnall = 0;

	for (int i = 0; i < 4; i++)
	{
		if (key[i] < key[i + 1] && i != 4) //����Ƚ�� ����
		{
			arrup[i] = 1;
			arrupnum++;
		}
		if ((key[i] % 2) == 1)  //Ȧ������ ����
		{
			oddpos[i] = 1;
			oddnum++;
		}
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
	arrdnall = !arrdnall;
	alleven = !alleven;


	//1�����϶��� ��������+���¦��orȦ��, 2�����϶��� ��������,¦Ȧ���� 1����,3�����϶��� ��� x
	while (1)
	{
		if (!allodd && !alleven && !arrupall && !arrdnall)
			break;


		if (level == 3) {
			
		}
		else if (level == 1)
		{
			if ((allodd || alleven) && (arrupall || arrdnall))
				break;
			else
				while (1)
				{

				}
		}
				
		while (1)
		{
			if (level == 2)
				if ((!allodd && !alleven) || ())
					break;
				else
			
							
				}

	}


	return key;
}



void triArr(int *key) //�Է¹ް� ���� ������ ��, ��Ʈ����ũ �˷��ֱ�
{
	int trinum = 0; //��
	Arrcouple keycouple[4];
	Arrcouple targetcouple[4];
	char keyinsert[5];
	char a[1];

	for (int i = 0; i < 4; i++) //���� �迭 ����ü ���·� ��ȯ
	{
		keycouple[i].digit = key[i];
		keycouple[i].pos = i;
	}

	while (1) // ������� ������ �ݺ��ؼ� �Է� �ް� �ϰ� ��� ���
	{
		trinum++;

		while (1)  //���� ���� ����� �Է��Ҷ����� �Է¹ޱ�
		{
			printf("������� ���ڿ��� �Է��ϼ��� : ");
			scanf_s("%s", keyinsert, sizeof(keyinsert));

			int checkall = 0; //���Ŀ� �´��� üũ�뵵 ����
			for (int i = 0; i < 4; i++) //���Ŀ� ������ targetcoulpe�� ������� �ְ� �ƴϸ� �ٽ�
			{
				targetcouple[i].pos = i;
				a[0] = keyinsert[i];

				if (atoi(a) < 0 || atoi(a) > 9) //���� �ȸ����� 
				{
					checkall = 1;
				}
				else
					targetcouple[i].digit = atoi(a);
			}

			if (checkall == 0 && sizeof(keyinsert) < 6)  //üũ�ϱ�
				break;
			else
				printf("���Ŀ� ���� �ʽ��ϴ�. ����� �Է�plz~!\n");
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
						strike++;
					else
						ball++;
				}
			}
		}

		printf("���� �� Ƚ���� : %d, \n����� : ", trinum);
		if (strike == 4)
		{
			printf("�����Դϴ�\n");
			break;
		}
		else if (ball == 0 && strike == 0)
			printf("OUT�̤�\n");
		else
			printf("%d B %d S\n", ball, strike);

		//���亸��
		printf("������ : ");
		for (int i = 0; i < 4; i++)
		{
			printf("%d", key[i]);
		}
		printf("\n");
	}
}

int main()
{
	srand((int)time(NULL));
	int *key; //��ǻ�Ͱ� ������ ����
	int level = 1; //�Է¹��� ����
	while (1)
	{
		printf("��ǻ�Ϳ� ���ھ߱� �����մϴ�\n���̵��� �����ϼ���");
		printf("\n""��""�� 1��, ""��""�� 2�� �Է��ϼ��� : ");
		scanf_s("%d", &level);
		if (level != 1 && level != 2)
			printf("1 �Ǵ� 2�� �ƴմϴ�.\n");
		else
			break;
	}

	key = makeKey(level);
	key = reArr(key, level);


	printf("\n���ڰ� �����Ǿ����ϴ�. �������� ���纸����\n=============================================\n\n");



	triArr(key);

	free(key);
	return 0;
}