#include <stdio.h>
#define win 3
#define drw 2
#define los 1

int array[4][6][3];
int result[4] = { 1 };
int allresult[4] = { 0 };
int MatRes[15];

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

void gag(int i, int count, int a[6][3]) {
	for (int j = 0; j < 3; j++) {
		if ((j == 0 && a[geti(i)][0] > 0 && a[getj(i)][2] > 0)
			||( j == 1 && a[geti(i)][2] > 0 && a[getj(i)][0] > 0)
			|| (j == 2 && a[geti(i)][1] > 0 && a[getj(i)][1] > 0)) {
			if (j == 0)
				MatRes[i] = win;
			else if (j == 1)
				MatRes[i] = los;
			else
				MatRes[i] = drw;
			if (i == 14) {
				if (j == 0) {
					a[geti(i)][0]--;
					a[getj(i)][2]--;
				}
				else if (j == 1) {
					a[geti(i)][2]--;
					a[getj(i)][0]--;
				}
				else {
					a[geti(i)][1]--;
					a[getj(i)][1]--;
				}
				result[count] = 1;
				for (int f = 0; f < 6; f++) {
					for (int g = 0; g < 3; g++) {
						if (a[f][g] != 0)
							result[count] = 0;
					}
				}
				if (result[count] == 1)
					allresult[count] = 1;
			}
			else {
				if (j == 0) {
					a[geti(i)][0]--;
					a[getj(i)][2]--;
					gag(i + 1, count, a);
					a[geti(i)][0]++;
					a[getj(i)][2]++;
				}
				else if (j == 1) {
					a[geti(i)][2]--;
					a[getj(i)][0]--;
					gag(i + 1, count, a);
					a[geti(i)][2]++;
					a[getj(i)][0]++;
				}
				else {
					a[geti(i)][1]--;
					a[getj(i)][1]--;
					gag(i + 1, count, a);
					a[geti(i)][1]++;
					a[getj(i)][1]++;
				}
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
			scanf_s("%d", &array1[i][j]);
	basicresult = basictest(array1);
	gag(0, 0, array1);
	_a = (allresult[0]&&basicresult);
	printf("%d %d %d", allresult[0], basicresult, _a);

	return 0;
	*/
	
	int _a[4];
	int basicresult[4];

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				scanf_s("%d", &array[k][i][j]);
			}
		}
		basicresult[k] = 0;
		basicresult[k] = basictest(array[k]);
		gag(0, k, array[k]);
		allresult[k] = allresult[k];
		_a[k] = (basicresult[k] && allresult[k]);
	}

	for (int k = 0; k < 4; k++) {
		printf("%d ", _a[k]);
	}

	return 0;
}