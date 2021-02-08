#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(string msg) {
	vector<int> answer;

	vector<string> dic;
	for (int i = 0; i < 26; i++) {
		string tmp;
		tmp.push_back('A' + i);
		dic.push_back(tmp);
	}

	vector<string>::iterator it;
	while (!msg.empty() && msg.size() > 1) {
		int i = 1;
		it = find(dic.begin(), dic.end(), msg.substr(0, i));
		while (it != dic.end() && i < msg.size()) {
			i++;
			it = find(dic.begin(), dic.end(), msg.substr(0, i));
		}
		it = find(dic.begin(), dic.end(), msg.substr(0, i - 1));
		answer.push_back(it - dic.begin() + 1);
		dic.push_back(msg.substr(0, i));
		msg.erase(0, i - 1);
	}
	if (msg.size() == 1)
		answer.push_back(find(dic.begin(), dic.end(), msg) - dic.begin() + 1);

	return answer;
}

int main() {
	string msg = "KAKAO";

	vector<int> ans = solution(msg);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}