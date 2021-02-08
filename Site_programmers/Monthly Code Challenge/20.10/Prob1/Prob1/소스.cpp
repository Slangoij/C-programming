#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string tothr(int n) {
	string tmp;

	while (n / 3 != 0) {
		tmp += to_string(n % 3);
		n /= 3;
	}
	if(n>0)
		tmp += to_string(n % 3);

	return tmp;
}

int solution(int n) {
	int answer = 0;

	string a = tothr(n);
	cout << a << endl;
	for (int i = 0; i < a.size(); i++)
		answer += pow(3, a.size() - i-1)*stoi(a.substr(i, 1));

	return answer;
}

int main() {
	cout << solution(45) << endl;
}