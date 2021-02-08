#include <stdio.h>
#define win 3
#define drw 2
#define los 1

int array[6][3];
int MatRes[15];
int index = 0;
int result = 1;
int allresult = 0;

int geti(int i) {
	if (i < 0)
		return -1;
	if (i < 5)
		return 0;
	else if (i < 9)
		return 1;
	else if (i < 12)
		return 2;
	else if (i < 14)
		return 3;
	else if (i < 15)
		return 4;
	else
		return -1;
}

int getj(int i) {
	if (i < 0)
		return -1;
	if (i < 5)
		return i + 1;
	else if (i < 9)
		return i - 3;
	else if (i < 12)
		return i - 6;
	else if (i < 14)
		return i - 8;
	else if (i < 15)
		return i - 9;
	else
		return -1;
}

void printarray(int a[6][3]) {
	for (int i = 0; i < 6; i++)
		printf("%2d%2d%2d |", a[i][0], a[i][1], a[i][2]);
	putchar('\n');
}

void gag(int i, int a[6][3]) {
	for (int j = 0; j < 3; j++) {
		if (j == 0 && a[geti(i)][0] > 0 && a[getj(i)][2] > 0) {
			MatRes[i] = win;
			if (i == 14) {
				a[geti(i)][0]--;
				a[getj(i)][2]--;
				for (int x = 0; x < 15; x++)
				{
					printf("%2d", MatRes[x]);
				}
				putchar('\n');
				printarray(a);
				result = 1;
				for (int f = 0; f < 6; f++) {
					for (int g = 0; g < 3; g++) {
						if (a[f][g] != 0)
							result = 0;
					}
				}
				if (result == 1)
					allresult = 1;
			}
			else {
				a[geti(i)][0]--;
				a[getj(i)][2]--;
				gag(i + 1, a);
				a[geti(i)][0]++;
				a[getj(i)][2]++;
			}

		}
		if (j == 1 && a[geti(i)][2] > 0 && a[getj(i)][0] > 0) {
			MatRes[i] = los;
			if (i == 14) {
				a[geti(i)][2]--;
				a[getj(i)][0]--;
				printf("MatRes : ");
				for (int x = 0; x < 15; x++)
				{
					printf("%2d", MatRes[x]);
				}
				putchar('\n');
				printarray(a);
				result = 1;
				for (int f = 0; f < 6; f++) {
					for (int g = 0; g < 3; g++) {
						if (a[f][g] != 0)
							result = 0;
					}
				}
				if (result == 1)
					allresult = 1;
			}
			else
			{
				a[geti(i)][2]--;
				a[getj(i)][0]--;
				gag(i + 1, a);
				a[geti(i)][2]++;
				a[getj(i)][0]++;
			}

		}
		if (j == 2 && a[geti(i)][1] > 0 && a[getj(i)][1] > 0) {
			MatRes[i] = drw;
			if (i == 14) {
				a[geti(i)][1]--;
				a[getj(i)][1]--;
				printf("MatRes : ");
				for (int x = 0; x < 15; x++)
				{
					printf("%2d", MatRes[x]);
				}
				putchar('\n');
				printarray(a);
				result = 1;
				for (int f = 0; f < 6; f++) {
					for (int g = 0; g < 3; g++) {
						if (a[f][g] != 0)
							result = 0;
					}
				}
				if (result == 1)
					allresult = 1;
			}
			else {
				a[geti(i)][1]--;
				a[getj(i)][1]--;
				gag(i + 1, a);
				a[geti(i)][1]++;
				a[getj(i)][1]++;
			}
		}
	}
}


/*
//각 단계에서 동시에 조합하는 알고리즘 필요
void ggag(int a[6][3]) {
   for (int i = 0; i < 6; i++) {
	 int *pos = calloc(5 - i, sizeof(int));
	 for (int k = 0; k < 5 - i; k++) {
	   pos[k] = 0;
	 }
	 while (1) {
	   int j = i + 1;
	   int s = 0;
	   while (j < 6) {
		 if (a[i][0] > 0 && a[j][2] > 0) {
			pos[s] = win;
		 }
		 if (a[i][2] > 0 && a[j][0] > 0) {
			pos[s] = los;
		 }
		 if (a[i][1] > 0 && a[j][1] > 0) {
			pos[s] = drw;
		 }
		 j++;
		 s++;
	   }
	   for (int k = 0; k < 5 - i; k++) {
		 if (pos[k] != 0)
			break;
	   }


	 }
	 free(pos);
   }
}*/

int basictest(int a[6][3]) {
	for (int i = 0; i < 6; i++) {
		if (a[i][0] + a[i][1] + a[i][2] != 5) {
			printf("기본조건111\n");
			return 0;
		}
	}
	return 1;
}

int main() {
	/*
	int basicresult = 0;
	int _a;

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			scanf_s("%d", &array[i][j]);
	basicresult = basictest(array);
	gag(0, array);
	_a = (allresult&&basicresult);
	printf("%d %d %d", allresult, basicresult, _a);

	return 0;
	*/
	

	int _a1, _a2, _a3, _a4;
	int allresult1, allresult2, allresult3, allresult4;
	int basicresult1, basicresult2, basicresult3, basicresult4;

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)

			scanf_s("%d", &array[i][j]);
	basicresult1 = 0;
	basicresult1 = basictest(array);
	gag(0, array);
	allresult1 = allresult;
	_a1 = (basicresult1 && allresult1);
	printf("basicresult: %d, allresult: %d, _a: %d\n", basicresult1, allresult1, _a1);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			scanf_s("%d", &array[i][j]);
	basicresult2 = 0;
	basicresult2 = basictest(array);
	gag(0, array);
	allresult2 = allresult;
	_a2 = (basicresult2 && allresult2);
	printf("basicresult: %d, allresult: %d, _a: %d\n", basicresult2, allresult2, _a2);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			scanf_s("%d", &array[i][j]);
	basicresult3 = 0;
	basicresult3 = basictest(array);
	gag(0, array);
	allresult3 = allresult;
	_a3 = (basicresult3 && allresult3);
	printf("basicresult: %d, allresult: %d, _a: %d\n", basicresult3, allresult3, _a3);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			scanf_s("%d", &array[i][j]);
	basicresult4 = 0;
	basicresult4 = basictest(array);
	gag(0, array);
	allresult4 = allresult;
	_a4 = (basicresult4 && allresult4);
	printf("basicresult: %d, allresult: %d, _a: %d\n", basicresult4, allresult4, _a4);

	//printf("%d %d %d %d", _a1, _a2, _a3, _a4);

	return 0;
}