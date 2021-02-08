#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

vector<int> tempnumbers;
int pos[7] = { -1 };
int idxflag[7] = { 0 };

void setpos(int dep, string numbers, int target) {
	for (int idx = 0; idx < numbers.size(); idx++) {
		if (!idxflag[idx]) {
			pos[dep] = idx;
			if (dep == target) {
				string tempstr = "";
				for (int j = 0; j <= dep; j++) {
					if (pos[j] != -1)
						tempstr.push_back(numbers[pos[j]]);
				}
				tempnumbers.push_back(stoi(tempstr));
			}
			else {
				idxflag[idx] = 1;
				setpos(dep + 1, numbers, target);
				idxflag[idx] = 0;
			}
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	vector<int> sosoo; //해당 범위의 소수
	vector<int> v; // 숫자들 조합
	string temp = numbers; // 소수의 최대크기 저장

	sort(temp.begin(), temp.end(), greater<char>());
	int maxnum = stoi(temp);

	cout << "numbers 정렬 후: " << maxnum << endl;

	if (stoi(temp) > 2)
		sosoo.push_back(2);
	
	for (int i = 3; i <= maxnum; i += 2) {
		int j = 0;
		while (j < sosoo.size() && i%sosoo[j] != 0 && sosoo[j] < sqrt(i))
			j++;
		if (j == sosoo.size() || sosoo[j] >= sqrt(i))
			sosoo.push_back(i);
		
		/*
		while (j < sqrt(i) && i%sosoo[j] != 0) {
			j++;
		}
		if (j >= sqrt(i))
			sosoo.push_back(i);
		*/
		/*
		int siz = sosoo.size();
		while (j < siz && i%sosoo[j] != 0) {
			j++;
		}
		if (j == siz)
			sosoo.push_back(i);
		*/
	}

	cout << "sosoo: ";
	for (int i = 0; i < sosoo.size(); i++)
		cout << sosoo[i] << " ";
	cout << endl;

	for (int i = 0; i < numbers.size(); i++) {
		setpos(0, numbers, i);
	}

	cout << "tempnumbers: ";
	for (int i = 0; i < tempnumbers.size(); i++)
		cout << tempnumbers[i] << " ";
	cout << endl;

	sort(tempnumbers.begin(), tempnumbers.end());

	int tmp = tempnumbers[0];
	v.push_back(tempnumbers[0]);
	for (int i = 0; i < tempnumbers.size(); i++) {
		if (tmp != tempnumbers[i]) {
			tmp = tempnumbers[i];
			v.push_back(tempnumbers[i]);
		}
	}

	cout << "v: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	
	int i = 0;
	int j = 0; 
	while (1) {
		if (i == sosoo.size() || j == v.size())
			break;
		if (sosoo[i] < v[j])
			i++;
		else if (sosoo[i] > v[j])
			j++;
		else {
			answer++;
			i++; j++;
		}
	}

	return answer;
}

int main() {
	string numbers;
	cin >> numbers;

	cout << "정답은 : " << solution(numbers) << "입니다." << endl;
}