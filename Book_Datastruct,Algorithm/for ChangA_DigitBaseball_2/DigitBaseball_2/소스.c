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

int *makeKey(int level) // 레벨에 따라 4자리 배열 생성 및 정렬
{
	int *key;

	key = (int *)calloc(4, sizeof(int));

	for (int i = 0; i < 4; i++)
	{
		key[i] = rand() % 10;
	}
	while (1) // 배열 중복 확인
	{
		int k = 0; //겹치는게 있는지 확인용 변수
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
	int oddpos[4] = { 0,0,0,0 }; //모두 홀수 개수
	int oddnum = 0;
	int allodd = 0;
	int alleven = 0;
	int arrup[3] = { 0,0,0 }; //뒤가 큰 쌍 개수
	int arrupnum = 0;
	int arrupall = 0;
	int arrdnall = 0;

	for (int i = 0; i < 4; i++)
	{
		if (key[i] < key[i + 1] && i != 4) //오름횟수 세기
		{
			arrup[i] = 1;
			arrupnum++;
		}
		if ((key[i] % 2) == 1)  //홀수개수 세기
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


	//1레벨일때는 오름내림+모두짝수or홀수, 2레벨일때는 오름내림,짝홀편중 1개만,3레벨일때는 모두 x
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



void triArr(int *key) //입력받고 맞출 때까지 볼, 스트라이크 알려주기
{
	int trinum = 0; //턴
	Arrcouple keycouple[4];
	Arrcouple targetcouple[4];
	char keyinsert[5];
	char a[1];

	for (int i = 0; i < 4; i++) //정답 배열 구조체 형태로 변환
	{
		keycouple[i].digit = key[i];
		keycouple[i].pos = i;
	}

	while (1) // 정답맞출 때까지 반복해서 입력 받고 턴과 결과 출력
	{
		trinum++;

		while (1)  //비교할 숫자 제대로 입력할때까지 입력받기
		{
			printf("츄라이할 숫자열을 입력하세요 : ");
			scanf_s("%s", keyinsert, sizeof(keyinsert));

			int checkall = 0; //형식에 맞는지 체크용도 변수
			for (int i = 0; i < 4; i++) //형식에 맞으면 targetcoulpe에 순서대로 넣고 아니면 다시
			{
				targetcouple[i].pos = i;
				a[0] = keyinsert[i];

				if (atoi(a) < 0 || atoi(a) > 9) //형식 안맞을때 
				{
					checkall = 1;
				}
				else
					targetcouple[i].digit = atoi(a);
			}

			if (checkall == 0 && sizeof(keyinsert) < 6)  //체크하기
				break;
			else
				printf("형식에 맞지 않습니다. 제대로 입력plz~!\n");
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
						strike++;
					else
						ball++;
				}
			}
		}

		printf("현재 턴 횟수는 : %d, \n결과는 : ", trinum);
		if (strike == 4)
		{
			printf("정답입니다\n");
			break;
		}
		else if (ball == 0 && strike == 0)
			printf("OUTㅜㅜ\n");
		else
			printf("%d B %d S\n", ball, strike);

		//정답보기
		printf("정답은 : ");
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
	int *key; //컴퓨터가 생성한 숫자
	int level = 1; //입력받을 버퍼
	while (1)
	{
		printf("컴퓨터와 숫자야구 시작합니다\n난이도를 선택하세요");
		printf("\n""하""는 1을, ""상""은 2를 입력하세요 : ");
		scanf_s("%d", &level);
		if (level != 1 && level != 2)
			printf("1 또는 2가 아닙니다.\n");
		else
			break;
	}

	key = makeKey(level);
	key = reArr(key, level);


	printf("\n숫자가 생성되었습니다. 이제부터 맞춰보세요\n=============================================\n\n");



	triArr(key);

	free(key);
	return 0;
}