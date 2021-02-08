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

int *makeKey(int level) // 4자리 배열 생성 및 정렬
{
	int *key;
	int odddigit[5] = { 1,3,5,7,9 };
	int evendigit[5] = { 0,2,4,6,8 };

	key = (int *)calloc(4, sizeof(int));

	//level,switch안에 각각 생성평가 반복

	if (level == 1) //난이도 하일때 모두 홀수짝수이고 오름내림차순
	{
		switch (rand() % 2) //모두짝수또는 모두홀수로 생성
		{
		case 0: //모두 홀수
			for (int i = 0; i < 4; i++)
			{
				key[i] = odddigit[rand() % 5];
			}
			while (1) //겹치는지만 평가
			{
				int multi = 0; //겹치는게 있는지
				for (int i = 0; i < 4; i++) //중복확인
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

		case 1:  //모두 짝수
			for (int i = 0; i < 4; i++)
			{
				key[i] = evendigit[rand() % 5];
			}
			while (1)
			{
				//겹치는지만 평가 
				int multi = 0; //겹치는게 있는지
				for (int i = 0; i < 4; i++) //중복확인
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
		bubble(key, 4); //오름또는 내림으로 정렬
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

	else if (level == 2) //난이도 중일때 오름내림 또는 홀수짝수 둘중 하나만
	{
		switch (rand() % 2)
		{
		case 0: //오름내림차순
			for (int i = 0; i < 4; i++)
			{
				key[i] = rand() % 10;
			}
			//겹치는지, 모두홀수짝수가 아닌지 평가 
			while (1)
			{
				//초기화 필수
				int multi = 0;
				int oddpos[4] = { 0,0,0,0 };
				int alleven = 0;
				int allodd = 0;

				for (int i = 0; i < 4; i++) //중복체크,홀수개수 세기
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
		case 1: //모두홀수짝수
			switch (rand() % 2) //모두짝수또는 모두홀수로 생성
			{
			case 0: //모두 홀수
				for (int i = 0; i < 4; i++)
				{
					key[i] = odddigit[rand() % 5];
				}
				break;
			case 1:  //모두 짝수
				for (int i = 0; i < 4; i++)
				{
					key[i] = evendigit[rand() % 5];
				}
				break;
			}
			//오름내림차순 아닌지 평가
			while (1)
			{
				int multi[4] = { 0,0,0,0 };
				int multione = 0;
				int randind1 = rand() % 4;
				int randind2 = (randind1 + rand() % 3 + 1) % 4;
				int arrup[3] = { 0,0,0 };
				int arrupall = 0;
				int arrdnall = 0;

				for (int i = 0; i < 4; i++) //오름횟수 세기
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

	else  //난이도 상일때
	{
		for (int i = 0; i < 4; i++)
		{
			key[i] = rand() % 10;
		}
		while (1)
		{
			int multi = 0; //겹치는게 있는지
			int oddpos[4] = { 0,0,0,0 };
			int allodd = 0;
			int alleven = 0;
			int arrup[3] = { 0,0,0 };
			int arrupall = 0;
			int arrdnall = 0;

			for (int i = 0; i < 4; i++) //중복확인
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
				// 모두 홀수,짝수가 아니고 오름,내림차순 정렬도 아니라면 생성완료
				break;
			else
				key[rand() % 4] = rand() % 10;
		}		
	}

	return key;
}

void triArr(int *key) //
{
	int trinum = 0; //턴
	Arrcouple keycouple[4];
	Arrcouple targetcouple[4];
	char keyinsert[5];
	char a[1];

	for (int i = 0; i < 4; i++)
	{
		keycouple[i].digit = key[i];
		keycouple[i].pos = i;
	}

	while (1) // 정답맞출 때까지 입력 받고 턴과 결과 출력
	{
		trinum++; //턴 수

		while (1)  //비교할 숫자 제대로 입력할때까지 입력받기
		{
			printf("츄라이할 숫자열을 입력하세요 : ");
			scanf_s("%s", &keyinsert, sizeof(keyinsert));

			int checkall = 0;

			for (int i = 0; i < 4; i++) //형식에 맞으면 targetcoulpe에 순서대로 넣고 아니면 다시
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

			if (checkall == 0)  //체크하기
				break;
			else
				printf("숫자를 입력하시옹\n");
		}

		int ball = 0;
		int strike = 0;
		for (int i = 0; i < 4; i++) //볼, 스트라이크 계산
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

		printf("\n현재 턴 횟수는 : %d, \n결과는 : ", trinum);
		if (strike == 4)
		{
			printf("\t정답입니다!\n\n");
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
	int *key; //컴퓨터가 생성한 숫자
	int level = 1; //입력받을 버퍼
	while (1)
	{
		printf("컴퓨터와 숫자야구 시작합니다\n난이도를 선택하세요");
		printf("\n""하""는 1을, ""중""은 2를, ""상""은 3을 입력하세요 : ");
		scanf_s("%d", &level);
		if (level != 1 && level != 2 && level != 3)
			printf("1 또는 2 또는 3이 아닙니다.\n");
		else
			break;
	}

	srand((int)time(NULL));
	key = makeKey(level);

	printf("\n숫자가 생성되었습니다. 이제부터 맞춰보세요\n=============================================\n\n");

	/*
	for (int j = 0; j < 100; j++)
	{
		key = makeKey(level);

		printf("정답은 ");
		for (int i = 0; i < 4; i++)
		{
			printf("%d ", key[i]);
		}
		printf("입니다.\n");

	}
	*/

	triArr(key);

	free(key);

	return 0;
}