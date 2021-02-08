#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int flag[27] = { 0 };

bool comparesize(string a, string b) {
	return a.size() < b.size();
}

bool isMember(int bit, int set) {
	return bit & set;
}

int membercnt(int bit){
	int n = 0;
	for (; bit != 0; n++)
		bit &= bit - 1;

	return n;
}

/*
void bubun(int flag[], int k, int nowsize, int nowmemsize, vector<int> tmpbubuns, vector<vector<int>> bubuns) {
	for (int i = 0; i < nowmemsize; i++) {
		if (flag[i] == 0) {
			if (k == nowsize) {
				cout << "      cekc!!! for " << i << " / nowmemsize: " << nowsize << endl;
				bubuns.push_back(tmpbubuns);
				tmpbubuns.clear();
				cout << "      지금 결과물: " << endl;
				for (int j = 0; j < bubuns.size(); j++) {
					cout << "      ";
					for (int h = 0; h < bubuns[j].size(); h++) {
						cout << bubuns[j][h] << "  ";
					}
					cout << endl;
				}
			}
			else {
				flag[i]++;
				tmpbubuns.push_back(i);
				cout << " i:" << i << " / nowsize: " << nowsize << " / 지금 tmpbubuns: ";
				for (int j = 0; j < tmpbubuns.size(); j++) {
					cout << tmpbubuns[j] << " ";
				}
				cout << endl;
				bubun(flag, k + 1, nowsize, nowmemsize, tmpbubuns, bubuns);
				flag[i]--;
			}
		}
	}
}
*/

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	sort(orders.begin(), orders.end());
	sort(orders.begin(), orders.end(), comparesize);

	int menuarr[28][28] = { 0 };
	vector<int> alphaidx;
	for (int i = 0; i < orders.size(); i++)
		for (int j = 0; j < orders[i].size(); j++)
			menuarr[i][orders[i][j] - 'A']++;

	cout << "문자배열은: " << endl;
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 28; j++)
			cout << menuarr[i][j] << " ";
		cout << endl;
	}

	vector<int> bits;
	int allmembit = 0;
	for (int i = 0; i < orders.size(); i++) {
		int memasbit = 0;
		for (int j = 0; j < 27; j++) {
			if (menuarr[i][j] == 1) {
				memasbit |= (1 << j);
				allmembit |= (1 << j);
			}
		}
		bits.push_back(memasbit);
	}
	for (int i = 0; i < 28; i++)
		if (allmembit & (1 << i))
			alphaidx.push_back(i);

	cout << endl<<"allmembit: " << allmembit << endl << " allalphaidx: ";
	for (int i = 0; i < alphaidx.size(); i++)
		cout << alphaidx[i] << "  ";
	cout << endl << endl << "bits: " << endl;
	for (int i = 0; i < bits.size(); i++)
		cout << bits[i] << " ";
	cout << endl << endl;
	
	vector<pair<int, int>> menucandidates;
	for (int i = 0; i < course.size(); i++) {
		int nowsize = course[i];
		int nowidx = 0;
		for (int j = 0; j < orders.size();j++) {
			if (orders[j].size() >= course[i]) {
				nowidx = j;
				break;
			}
		}

		/*
		int maxbit = 0, minbit = 0;
		for (int j = 0; j < course[i]; j++) {
			minbit |= (1 << alphaidx[j]);
			maxbit |= (1 << alphaidx[alphaidx.size() - j - 1]);
		}
		cout << endl << "maxbit: " << maxbit << " / minbit: " << minbit << endl << endl;
		*/

		int nowmembit = 0;
		int nowmemsize = 0;
		for (int j = nowidx; j < orders.size(); j++)
			for (int k = 0; k < 27; k++)
				if (menuarr[j][k] == 1)
					nowmembit |= (1 << k);

		vector<int> setcandidates;
		for (int j = 0; j < 27; j++) {
			if (nowmembit&(1 << j)) {
				nowmemsize++;
				setcandidates.push_back(j);
			}
		}

		vector<int> idxset;
		cout << "nowsize: " << nowsize << " / nowmemsize: " << nowmemsize << endl
			<< "setcandidates: " << endl;
		for (int j = 0; j < setcandidates.size(); j++) {
			cout << setcandidates[j] << " ";
		}
		cout << endl;

		for (int j = (1 << nowsize) - 1; j < (1 << nowmemsize); j++) {
			if (membercnt(j) == nowsize)
				idxset.push_back(j);
		}

		cout << endl << "idxset: " << endl;
		for (int j = 0; j < idxset.size(); j++) {
			cout << idxset[j] << " ";
		}
		cout << endl;



		vector<int> memcandidates;
		for (int j = 0; j < idxset.size(); j++) {
			int tmpmem = 0;
			for (int k = 0; k < nowmemsize; k++) {
				if (idxset[j] & (1 << k))
					tmpmem |= (1 << setcandidates[k]);
			}
			memcandidates.push_back(tmpmem);
		}

		int maxcnt = 0;
		vector<pair<int, int>> tmpmems;
		for (int j = 0; j < idxset.size(); j++) {
			int cnt = 0;
			for (int k = nowidx; k < orders.size(); k++) {
				if ((bits[k] | memcandidates[j]) == bits[k]) {
					cout << "겹치는 부분집합은: " << memcandidates[j] << " / k: " << k 
						<< " /  bits[k]: " << bits[k] << endl;
					cnt++;
					maxcnt = max(maxcnt, cnt);
				}
			}
			if (cnt >= 2) {
				tmpmems.push_back(make_pair(memcandidates[j], cnt));
			}
		}
		for (int j = 0; j < tmpmems.size(); j++)
			if (tmpmems[j].second == maxcnt)
				menucandidates.push_back(tmpmems[j]);


		/*
		for (int j = minbit; j <= maxbit; j++) {
			if (membercnt(j) == nowsize) {
				cout << "지금 부분집합은: " << j << endl;
				memcandidates.push_back(j);
			}
		}

		int maxcnt = 0;
		vector<pair<int, int>> tmpmems;
		for (int j = 0; j < memcandidates.size(); j++) {
			int cnt = 0;
			for (int k = nowidx; k < orders.size(); k++) {
				if ((bits[k] | memcandidates[j]) == bits[k]) {
					cout << "겹치는 부분집합은: " << memcandidates[j] << "/ k: " << k << " /  bits[k]: " << bits[k] << endl;
					cnt++;
					maxcnt = max(maxcnt, cnt);
				}
			}
			if (cnt >= 2) {
				tmpmems.push_back(make_pair(memcandidates[j],cnt));
			}
		}
		for (int j = 0; j < tmpmems.size(); j++)
			if (tmpmems[j].second == maxcnt)
				menucandidates.push_back(tmpmems[j]);
		*/

		cout << "메뉴 후보는: " << endl;
		for (int i = 0; i < menucandidates.size(); i++)
			cout << menucandidates[i].first << " / " << menucandidates[i].second << endl;
		cout << endl;
	}

	for (int i = 0; i < menucandidates.size(); i++) {
		string ansstr;
		for (int j = 0; j < 27; j++) {
			if ((menucandidates[i].first & (1 << j))) {
				ansstr.push_back('A' + j);
			}
		}
		answer.push_back(ansstr);
	}

	sort(answer.begin(), answer.end());

	cout << "정답은: " << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return answer;
}

int main() {
	vector<string> orders;
	vector<int> course;

	/*
	orders.push_back("ABCFG");
	orders.push_back("AC");
	orders.push_back("CDE");
	orders.push_back("ACDE");
	orders.push_back("BCFG");
	orders.push_back("ACDEH");

	course.push_back(2);
	course.push_back(3);
	course.push_back(4);


	orders.push_back("ABCDE");
	orders.push_back("AB");
	orders.push_back("CD");
	orders.push_back("ADE");
	orders.push_back("XYZ");
	orders.push_back("XYZ");
	orders.push_back("ACD");

	course.push_back(2);
	course.push_back(3);
	course.push_back(5);
	*/


	orders.push_back("XYZ");
	orders.push_back("XWY");
	orders.push_back("WXA");

	course.push_back(2);
	course.push_back(3);
	course.push_back(4);



	solution(orders, course);
}