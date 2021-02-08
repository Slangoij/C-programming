#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmpr(pair<char, int> a, pair<char, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

string solution(string number, int k) {
	string answer = "";

	vector<pair<char, int>> numidx;
	for (int i = 0; i < number.size(); i++)
		numidx.push_back(make_pair(number[i], i));

	sort(numidx.begin(), numidx.end(), cmpr);

	int nowmaxnumidx = numidx.front().second;
	if (nowmaxnumidx<numidx.size() - k && nowmaxnumidx>k)
		return number.substr(nowmaxnumidx);


	while (k > 0) {
		for (int i = 0; i < numidx.size(); i++) {
			nowmaxnumidx = numidx[i].second;
			for (int j = numidx.size() - 1; j > nowmaxnumidx; j--) {
				if (numidx[j].second < nowmaxnumidx) {
					numidx.erase(numidx.begin() + numidx[j].second);
					k--;
				}
			}
		}
		if (nowmaxnumidx<numidx.size() - k && nowmaxnumidx>k)
			return number.substr(nowmaxnumidx);
	}

	sort()







		/*
		vector<pair<string,int>> answers;
		for(int i=k;i<number.size();i++){
			answers.push_back(numidx[i]);
		}

		sort(answers.begin(),answers.end(),cmpr);

		for(int i=0;i<answers.size();i++){
			answer+=answers[i].first;
		}
		*/
}

int main() {
	vector<vector<int>> triangle{ {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };

	string a = "abcedbsfz";
	sort(a.begin(), a.end(), greater<char>());

	cout << a << endl;
}