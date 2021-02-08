#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define hashsize 100

int hashed(string temp) {
	int mul = 1;
	int x = 0;
	for (int i = 0; temp[i] != 0; i++) {
		x = ((temp[i] * mul) + x) % hashsize;
		mul *= 7;
	}
	if (x < 0) x = -x;
	return x % hashsize;
}
int hashed1(string temp) {
	int mul = 1;
	int x = 0;
	for (int i = 0; temp[i] != 0; i++) {
		x = ((temp[i] * mul) + x) % hashsize;
		mul *= 13;
	}
	if (x < 0) x = -x;
	return x % hashsize;
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	int sizearray[21] = { 0 };
	vector<int> sizevec;

	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size(); i++)
		sizearray[phone_book[i].size()]++;
	for (int i = 0; i < 21; i++)
		if (sizearray[i] != 0)
			sizevec.push_back(i);

	int siz = sizevec.size();

	int ***hashtable = new int **[hashsize];
	for (int i = 0; i < hashsize; i++) {
		hashtable[i] = new int*[hashsize];
		for (int j = 0; j < hashsize; j++) {
			hashtable[i][j] = new int[siz];
		}
	}
	for (int i = 0; i < hashsize; i++) {
		for (int j = 0; j < hashsize; j++) {
			for (int k = 0; k < siz; k++)
				hashtable[i][j][k] = 0;
		}
	}

	for (int i = 0; i < siz; i++) {
		for (int j = 0; j < phone_book.size(); j++) {
			if (phone_book[j].size() > sizevec[i])
				hashtable[hashed(phone_book[j].substr(0, sizevec[i]))][hashed1(phone_book[j].substr(0, sizevec[i]))][i] = 1;
		}
		for (int j = 0; j < phone_book.size(); j++) {
			if (phone_book[j].size() == sizevec[i])
				hashtable[hashed(phone_book[j].substr(0, sizevec[i]))][hashed1(phone_book[j].substr(0, sizevec[i]))][i]++;

		}
	}

	/*
	for (int i = 0; i < hashsize; i++) {
		for (int j = 0; j < hashsize; j++) {
			for (int k = 0; k < siz; k++)
				cout << hashtable[i][j][k] << " ";
			cout << endl;
		}
		cout << endl << endl << endl;
	}
	*/


	for (int i = 0; i < hashsize; i++) {
		for (int j = 0; j < hashsize; j++) {
			for (int k = 0; k < siz; k++) {
				if (hashtable[i][j][k] > 1) {
					//hashtable 메모리반납
					for (int i = 0; i < hashsize; i++) {
						for (int j = 0; j < hashsize; j++) {
							delete[] hashtable[i][j];
						}
						delete[] hashtable[i];
					}
					delete[] hashtable;
					return false;
				}
			}
		}
	}

	//hashtable 메모리반납
	for (int i = 0; i < hashsize; i++) {
		for (int j = 0; j < hashsize; j++) {
			delete[] hashtable[i][j];
		}
		delete[] hashtable[i];
	}
	delete[] hashtable;

	return true;
}

int main() {
	string temp;
	vector<string> phone_book;
	while (1) {
		cin >> temp;
		if (temp == "-1")
			break;
		phone_book.push_back(temp);
	}

	if (solution(phone_book) == false)
		cout << "답은 false입니다" << endl;
	else
		cout << "답은 true입니다" << endl;


	return 0;
}
	
	