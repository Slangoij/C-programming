#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> nextidx(int x, int y, int n, int **arr) {
	if (x < n - 1 && (y == 0 || (arr[x][y - 1] != 1 && arr[x + 1][y] == 1)))
		return { x + 1,y };
	else if (y < n - 1 && (x == n - 1 || (arr[x + 1][y] != 1 && arr[x][y + 1] == 1)))
		return { x,y + 1 };
	else
		return { x - 1,y - 1 };
}

vector<int> solution(int n) {
	vector<int> answer;
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[i + 1];
		for (int j = 0; j <= i; j++)
			arr[i][j] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += i;
	vector<int> idxs{ 0,0 };
	for (int i = 2; i <= sum; i++) {
		idxs = nextidx(idxs[0], idxs[1], n, arr);
		arr[idxs[0]][idxs[1]] = i;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			answer.push_back(arr[i][j]);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return answer;
}

int main() {
	int n = 4;
	vector<int> answer = solution(n);
	for(int i=0;i<answer.size();i++)
		cout << answer[i] << " ";
}