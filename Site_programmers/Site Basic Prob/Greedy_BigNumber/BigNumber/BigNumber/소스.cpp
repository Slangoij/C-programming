#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmpr(pair<char, int> a, pair<char, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	else
		return a.first > b.first;
}

bool cmpr2(pair<char, int> a, pair<char, int> b) {
	return a.second < b.second;
}

string solution(string number, int k) {
	string answer = "";

	while (k>0) {
		int i = 0;
		while (number[i] >= number[i + 1] && i < number.size())
			i++;
		if (i == number.size())
			break;
		else {
			k--;
			number.erase(number.begin() + i);
		}
	}

	number.erase(number.end() - k, number.end());

	return number;

	/*
	vector<pair<char, int>> numidx;
	for (int i = 0; i < number.size(); i++) {
		numidx.push_back(make_pair(number[i], i));
	}

	sort(numidx.begin(), numidx.end(), cmpr);

	int nowmaxnumidx = numidx.front().second;
	for (int i = numidx.size() - 1; i > 1 && k > 0; i--) {
		if (numidx[i].second < nowmaxnumidx) {
			numidx.erase(numidx.begin() + i);
			k--;
		}
	}
	if (k > 0)
		for (int i = 0; i < k; i++)
			numidx.pop_back();

	sort(numidx.begin(), numidx.end(), cmpr2);

	for (int i = 0; i < numidx.size(); i++)
		answer += numidx[i].first;
	*/
}

int main() {
	string number = "4177252841";
	int k = 4;

	cout << solution(number, k) << endl;
}