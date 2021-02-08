#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum condi1 { all1, cpp, java, python };
enum condi2 { all2, backend, frontend };
enum condi3 { all3, junior, senior };
enum condi4 { all4, chichken, pizza };

int to_num(int condinum, string a) {
	switch (condinum) {
	case 0:
		if (a == "cpp")
			return cpp;
		else if (a == "java")
			return java;
		else if (a == "python")
			return python;
		else if (a == "-")
			return all1;
	case 1:
		if (a == "backend")
			return backend;
		else if (a == "frontend")
			return frontend;
		else if (a == "-")
			return all2;
	case 2:
		if (a == "junior")
			return junior;
		else if (a == "senior")
			return senior;
		else if (a == "-")
			return all3;
	case 3:
		if (a == "chicken")
			return chichken;
		else if (a == "pizza")
			return pizza;
		else if (a == "-")
			return all4;
	default:
		return -1;
	}
}

vector<vector<int>> transtonum(vector<string> info, string parstr) {
	vector<vector<int>> tmpinfos;

	for (int i = 0; i < info.size(); i++) {
		vector<int> tmpinfo;
		int nowidx = 0, nextidx = 0;
		for (int j = 0; j < 4; j++) {
			if (j == 3)
				nextidx = info[i].find(" ", nowidx);
			else
				nextidx = info[i].find(parstr, nowidx);
			tmpinfo.push_back(to_num(j, info[i].substr(nowidx, nextidx - nowidx)));
			if (j == 3)
				nowidx = nextidx + 1;
			else
				nowidx = nextidx + parstr.size();
		}
		tmpinfo.push_back(stoi(info[i].substr(nowidx)));
		tmpinfos.push_back(tmpinfo);
	}

	return tmpinfos;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	vector<vector<int>> infonum = transtonum(info, " "), querynum = transtonum(query, " and ");
	sort(infonum.begin(), infonum.end());

	for (int i = 0; i < querynum.size(); i++) {
		vector<int> tmpidx;
		for (int j = 0; j < infonum.size(); j++)
			tmpidx.push_back(j);

		for (int j = 0; j < 5; j++) {
			if (!tmpidx.empty()) {
				vector<int> newtmpidx;
				if (!querynum[i][j]) {
					newtmpidx = tmpidx;
					continue;
				}

				for (int k = 0; k < tmpidx.size(); k++) {
					if (j != 4) {
						if (querynum[i][j] == infonum[tmpidx[k]][j]) {
							newtmpidx.push_back(tmpidx[k]);
						}
					}
					else {
						if (querynum[i][j] <= infonum[tmpidx[k]][j]) {
							newtmpidx.push_back(tmpidx[k]);
						}
					}
				}
				tmpidx = newtmpidx;
			}
			else {
				tmpidx.clear();
				break;
			}
		}
		
		answer.push_back(tmpidx.size());
	}
	
	return answer;
}

int main() {
	vector<string> info, query;

	info.push_back("python frontend senior chicken 210");
	info.push_back("java backend junior pizza 150");
	info.push_back("python frontend senior chicken 150");
	info.push_back("cpp backend senior pizza 260");
	info.push_back("java backend junior chicken 80");
	info.push_back("python backend senior chicken 50");
	/*
	*/



	query.push_back("java and backend and junior and pizza 100");
	query.push_back("python and frontend and senior and chicken 200");
	query.push_back("cpp and - and senior and pizza 250");
	query.push_back("- and backend and senior and - 150");
	query.push_back("- and - and - and chicken 100");
	query.push_back("- and - and - and - 150");
	/*
	*/


	vector<int> tmpsolution = solution(info, query);

	cout << "Á¤´äÀº: " << endl;
	for (int i = 0; i < tmpsolution.size(); i++) {
		cout << tmpsolution[i] << ", ";
	}
}