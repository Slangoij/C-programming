#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool iseven(string p) {
	int left = 0, right = 0;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(')
			left++;
		else if (p[i] == ')')
			right++;
	}

	return left == right;
}

bool isright(string p) {
	vector<int> left,right;

	for (int i = 0; i < p.size(); i++) {
		cout << "left.size는: " << left.size() << endl;
		if (p[i] == '(') {
			left.push_back(0);
		}
		else if (p[i] == ')') {
			if (left.size() == 0)
				right.push_back(0);
			else {
				left.pop_back();
			}
		}
	}

	return left.size() == 0 && right.size() == 0;
}


string jagui(string p) {
	cout << "지금 p는: " << p << endl << endl;
	if (p.size() == 0 || isright(p))
		return p;
	else {
		int idx = 2;
		string u = p.substr(0, idx);
		string v = p.substr(idx);
		while (!iseven(u) && idx <= p.size()) {
			idx += 2;
			u = p.substr(0, idx);
			v = p.substr(idx);
		}

		cout << "u는: " << u << endl;
		cout << "v는: " << v << endl;

		if (isright(u))
			return u + jagui(v);
		else {
			string x = "";
			if (u.size() > 2)
				for (int i = 1; i < u.size() - 1; i++) {
					if (u[i] == '(')
						x.push_back(')');
					else if (u[i] == ')')
						x.push_back('(');
				}

			return '(' + jagui(v) + ')' + x;
		}
	}
}


string solution(string p) {
	return jagui(p);
}

int main() {
	string p = "()))((()";

	cout << "정답은: " << solution(p) << endl;
}