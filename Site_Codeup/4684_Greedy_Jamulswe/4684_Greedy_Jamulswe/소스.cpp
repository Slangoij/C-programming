#include <iostream>
#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

using namespace std;

int whatidid[4] = { -1 };
int lastresult[4] = { 0 };

void check_1(int *arr, int N, int i);
void check_2(int *arr, int N, int i);

bool arrcheck(int *arr, int N) {
	for (int i = 0; i < N; i++)
		if (arr[i] != i + 1)
			return false;
	return true;
}

void pushleft(int *arr, int N, int k) {
	for (int j = 0; j < k; j++)
		for (int i = 0; i < N - 1; i++)
			swap(int, arr[i], arr[i + 1]);
}

void pushright(int *arr, int N, int k) {
	for (int j = 0; j < k; j++)
		for (int i = N - 1; i > 0; i--)
			swap(int, arr[i], arr[i - 1]);
}

void turnrl(int *arr, int N, int p, int q) {
	int k = (q - p + 1) / 2;
	for (int i = 0; i < k; i++)
		swap(int, arr[p + i], arr[q - i]);
}

void printarr(int *arr, int N) {
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
}


void check_1(int *arr, int N, int i) {
	if (i == 0 || i == 2) {
		for (int j = 0; j < N; j++) {
			pushright(arr, N, j);
			whatidid[i] = j;
			check_2(arr, N, i + 1);
			pushleft(arr, N, j);
			whatidid[i] = -1;
		}
	}
}

void check_2(int *arr, int N, int i) {
	if (i == 1) {
		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				turnrl(arr, N, j, k);
				whatidid[1] = j + 1;
				whatidid[3] = k + 1;
				check_1(arr, N, i + 1);
				turnrl(arr, N, j, k);
				whatidid[1] = -1;
				whatidid[3] = -1;
			}
		}
	}
	else if (i == 3) {
		if (arrcheck(arr, N) == true) {
			cout << whatidid[2] << endl << whatidid[1] << " "
				<< whatidid[3] << endl << whatidid[0] << endl << endl;
			lastresult[0] = whatidid[2];
			lastresult[1] = whatidid[1];
			lastresult[2] = whatidid[3];
			lastresult[3] = whatidid[0];
		}
	}
}



int main() {
	int N;
	cin >> N;

	int *arr = new int[N];


	for (int i = 0; i < N; i++)
		cin >> arr[i];
	check_1(arr, N, 0);
	/*

	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		pushright(arr, N, i);
		printarr(arr, N);
		cout << endl;
		pushleft(arr, N, i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			turnrl(arr, N, i, j);
			printarr(arr, N);
			cout << endl;
			turnrl(arr, N, i, j);
		}
	}
	*/


	cout << lastresult[0] << endl << lastresult[1] << " "
		<< lastresult[2] << endl << lastresult[3];

	delete[] arr;

	return 0;
}