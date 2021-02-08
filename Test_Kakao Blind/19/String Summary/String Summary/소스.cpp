#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = 0;

	vector<pair<int, int>> answers;
	for (int i = 1; i <= s.size(); i++) {
		string tmpstr = s.substr(0, i);
		int nowsize = s.size();
		int stacked = 0;
		for (int j = 0; j < s.size() / i - 1; j++) {
			if (tmpstr == s.substr((j + 1)*i, i)) {
				nowsize -= i;
				stacked++;
				if (stacked == 1 || stacked == 9 || stacked == 99 || stacked == 999)
					nowsize++;
			}
			else {
				tmpstr = s.substr((j + 1)*i, i);
				stacked = 0;
			}
		}
		answers.push_back(pair<int, int>(nowsize, i));
	}

	sort(answers.begin(), answers.end());

	cout << "지금 리스트 상태:" << endl;
	for (int i = 0; i < answers.size(); i++)
		cout << answers[i].first << " / " << answers[i].second << endl;
	cout << endl << endl;

	answer = answers[0].first;

	return answer;
}

int main() {
	string s;
	s = "abcabcabcabcdededededede";

	cout << "size: " << s.size() << endl << endl;

	cout << "답은: " << solution(s) << endl;
}