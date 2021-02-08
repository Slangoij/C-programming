#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int sum = 0;

void pplma(int i,int size, vector<int> numbers, int target) {
	if (i == size) {
		if (sum == target)
			cnt++;
	}
	else {
		sum += numbers[i];
		for (int j = 0; j < i; j++)
			cout << "  ";
		pplma(i + 1, size, numbers, target);
		sum = sum - 2 * numbers[i];
		for (int j = 0; j < i; j++)
			cout << "  ";
		pplma(i + 1, size, numbers, target);
		sum += numbers[i];
	}
}

int solution(vector<int> numbers, int target) {
	int size = numbers.size();
	int answer = 0;

	pplma(0, size, numbers, target);
	answer = cnt;

	return answer;
}

int main() {
	vector<int> vec;
	int target;
	int in;
	
	cout << "target입력: ";
	cin >> target;
	while (1) {
		cin >> in;
		if (in == -1)
			break;
		vec.push_back(in);
	}

	cout << "vec : ";
	for (vector<int>::iterator itr = vec.begin(), end = vec.end(); itr != end; ++itr)
		cout << *itr << " ";
	cout << endl;

	cout << "정답은 : " << solution(vec, target);

	return 0;
}