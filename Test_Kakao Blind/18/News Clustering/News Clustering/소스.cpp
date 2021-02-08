#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2);

int main() {
	string a, b;

	a = "zzzz12";
	b = "ZZZZ12";

	cout << "시작한다" << endl << solution(a, b) << "이다.~" << endl;
}

int solution(string str1, string str2) {
	int answer = 0;
	int letarr1[26][26] = { 0 };
	int letarr2[26][26] = { 0 };
	int Union = 0, Cross = 0;

	for (int i = 0; i < str1.size() - 1; i++)
		if (isalpha(str1[i]) != 0 && isalpha(str1[i + 1]) != 0)
			letarr1[tolower(str1[i]) - 97][tolower(str1[i + 1]) - 97]++;
	for (int i = 0; i < str2.size() - 1; i++)
		if (isalpha(str2[i]) != 0 && isalpha(str2[i + 1]) != 0)
			letarr2[tolower(str2[i]) - 97][tolower(str2[i + 1]) - 97]++;

	for (int i = 0; i < 26; i++) {
		cout << endl;
		for (int j = 0; j < 26; j++) {
			cout << letarr1[i][j] << letarr2[i][j] << " , ";
			if (j == 12)
				cout << endl;
			if (letarr1[i][j] > 0 || letarr2[i][j] > 0) {
				Union += (letarr1[i][j] > letarr2[i][j]) ? letarr1[i][j] : letarr2[i][j];
				Cross += (letarr1[i][j] < letarr2[i][j]) ? letarr1[i][j] : letarr2[i][j];
			}
		}
	}

	cout << endl << "합집합: " << Union << "  교집합: " << Cross << endl;

	if (Union != 0)
		answer = (65536 * Cross) / Union;
	else answer = 65536;

	return answer;
}

/*
int Size(int s)
{
	int n = 0;
	for (; s != 0; n++)
		s &= s - 1;
	return n;
}

int solution(string str1, string str2) {
	int answer = 0;
	int BitSet1 = 0, BitSet2 = 0;
	vector<int> strvec1, strvec2;

	for (int i = 0; i < str1.size() - 1; i++)
		if (isalpha(str1[i]) != 0 && isalpha(str1[i + 1]) != 0)
			strvec1.push_back((tolower(str1[i]) - 96) * 26 + (tolower(str1[i + 1]) - 96));
	for (int i = 0; i < str2.size() - 1; i++)
		if (isalpha(str2[i]) != 0 && isalpha(str2[i + 1]) != 0)
			strvec2.push_back((tolower(str2[i]) - 96) * 26 + (tolower(str2[i + 1]) - 96));

	cout << "1의 문자열: " << endl;
	for (int i = 0; i < strvec1.size(); i++)
		cout << strvec1[i] << " ";
	cout << endl << "2의 문자열: " << endl;
	for (int i = 0; i < strvec2.size(); i++)
		cout << strvec2[i] << " ";
	cout << endl << endl;

	for (int i = 0; i < strvec1.size(); i++)
		BitSet1 |= 1 << strvec1[i];
	for (int i = 0; i < strvec2.size(); i++)
		BitSet2 |= 1 << strvec2[i];

	int UnionBit = 0, CrossBit = 0, CheckBit = 0;
	UnionBit = BitSet1 | BitSet2;
	CrossBit = BitSet1 & BitSet2;

	cout << endl << "유니온 크기: " << Size(UnionBit) << endl <<
		"크로스 크기: " << Size(CrossBit) << endl;
	if (Size(UnionBit) != 0)
		answer = (65536 * Size(CrossBit)) / Size(UnionBit);
	else answer = 65536;

	return answer;
}
*/