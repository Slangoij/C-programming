#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
	string answer = "";

	string id = new_id;
	string newid1, newid2;

	for (int i = 0; i < id.size(); i++) {
		if (isupper(id[i])) {
			cout << "여기1 / i: " << i << endl;
			newid1.push_back(tolower(id[i]));
		}
		else if (!islower(id[i]) && !isdigit(id[i]) && id[i] != '-' && id[i] != '_' && id[i] != '.') {
			cout << "여기2 / i: " << i << endl;
			i++;
		}
		else
			newid1.push_back(id[i]);
	}

	cout << newid1 << endl;
	
	for (int i = 0; i < newid1.size(); i++) {
		if (newid1[i] == '.'&&i == 0)
			i++;
		if (newid1[i] == '.'&& newid1[i + 1] == '.'&& i + 1 != newid1.size())
			i++;
		newid2.push_back(newid1[i]);
	}

	cout << newid2 << endl;
	cout << newid2.size() << endl;

	if (newid2.size() > 1) {
		if (newid2[0] == '.')
			newid2 = newid2.substr(1);
	}
	if (newid2.size()) {
		cout << "newid.size(): " << newid2.size() << endl;
		if (newid2.back() == '.')
			newid2.pop_back();
	}
	cout << "====================" << endl;

	if (!newid2.size())
		newid2 = "aaa";
	else if (newid2.size() >= 16) {
		newid2 = newid2.substr(0, 15);
		if (newid2.back() == '.')
			newid2.pop_back();
	}
	else if (newid2.size() <= 2) {
		int i = newid2.size() - 1;
		while (newid2.size() < 3)
			newid2 += newid2[i];
	}

	answer = newid2;

	return answer;
}

int main() {
	//string a = "...!@BaT#*..y.abcdefghijklm";

	//string a = "z-+.^.";

	//string a = "=.=";

	//string a = "123_.def";

	string a = "abcdefghijklmn.p";

	cout << solution(a) << endl;
}