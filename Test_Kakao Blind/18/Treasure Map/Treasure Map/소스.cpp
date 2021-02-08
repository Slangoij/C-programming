#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;


	for (int i = 0; i < n; i++) {
		string tmpstr;
		for (int j = n-1; j >=0; j--) {
			if ((arr1[i] | arr2[i])&(1 << j))
				tmpstr.push_back('#');
			else
				tmpstr.push_back(' ');
		}
		answer.push_back(tmpstr);
	}

	return answer;
}

int main() {
	int n = 5;
	vector<int> arr1, arr2;

	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);

	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);

	for (int i = 0; i < solution(n, arr1, arr2).size(); i++) {
		cout << solution(n, arr1, arr2)[i] << endl;
	}
}