#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

/*
vector<pair<int,int>> dfs(int str, int n, int** map, bool check[]) {
	vector<int> candid;
	stack<int> s;
	check[str] = true;

	while (!s.empty()) {
		int crntnode = s.top();
		s.pop();
		for (int i = 0; i < n; i++) {
			if (map[crntnode][i]) {
				int nextnode = map[crntnode][i];
				if (check[i] == false) {
					check[i] = true;
					s.push(crntnode);
					s.push(nextnode);
				}
			}
		}
	}
}
*/

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	int *check = new int[n + 1]; // DFS용 flag
	int **map = new int*[n + 1];

	for (int i = 0; i <= n; i++) {
		check[i] = false;
		map[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)
			map[i][j] = 0;
	}


	for (int i = 0; i < fares.size(); i++) {
		map[fares[i][0]][fares[i][1]] += fares[i][2];
		map[fares[i][1]][fares[i][0]] += fares[i][2];

	}

	// 경로 추적 한번 및 저장

	vector<vector<pair<int, int>>> to_a, to_b;

	sort(fares.begin(), fares.end());

	vector<pair<int,int>> stac;
	stac.push_back(make_pair(s, 0));
	check[s] = true;
	int lastsearch = 0;
	while (!stac.empty()) {
		int crntnode = stac.back().first;
		int i = lastsearch + 1;
		for (; i <= n; i++) {
			if (map[crntnode][i]) {
				int nextnode = i;
				if (check[nextnode] == false) {
					lastsearch = 0;
					check[nextnode] = true;
					stac.push_back(make_pair(nextnode, map[crntnode][nextnode]));
					if (nextnode == a)
						to_a.push_back(stac);
					else if (nextnode == b)
						to_b.push_back(stac);
					break;
				}
			}
		}

		if (i == n + 1) {
			check[crntnode] = false;
			lastsearch = crntnode;
			stac.pop_back();
		}
	}

	vector<int> answers;
	for (int i = 0; i < to_a.size(); i++) {
		for (int j = 0; j < to_b.size(); j++) {
			int idx = 0, tmpanswer = 0;
			int mididx = (to_a[i].size() < to_b[j].size()) ? 
				to_a[i].size() : to_b[j].size();
			int lastidx = (to_a[i].size() > to_b[j].size()) ? 
				to_a[i].size() : to_b[j].size();

			while (idx < mididx&&to_a[i][idx].first == to_b[j][idx].first) {
				tmpanswer += to_a[i][idx].second;
				idx++;
			}

			for (int k = idx; k < mididx; k++) {
				tmpanswer += to_a[i][k].second;
				tmpanswer += to_b[j][k].second;
			}
			if (to_a[i].size() > to_b[j].size())
				for (int k = mididx; k < lastidx; k++)
					tmpanswer += to_a[i][k].second;
			else
				for (int k = mididx; k < lastidx; k++)
					tmpanswer += to_b[j][k].second;

			answers.push_back(tmpanswer);
		}
	}

	sort(answers.begin(), answers.end());

	for (int i = 0; i <= n; i++)
		delete[] map[i];
	delete[] check, map;

	return answers[0];
}

int main() {
	int n = 6;
	int s = 4;
	int a = 6;
	int b = 2;

	vector<vector<int>> fares;
	vector<int> fare;
	fare.push_back(4);
	fare.push_back(1);
	fare.push_back(10);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(3);
	fare.push_back(5);
	fare.push_back(24);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(5);
	fare.push_back(6);
	fare.push_back(2);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(3);
	fare.push_back(1);
	fare.push_back(41);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(5);
	fare.push_back(1);
	fare.push_back(24);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(4);
	fare.push_back(6);
	fare.push_back(50);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(2);
	fare.push_back(4);
	fare.push_back(66);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(2);
	fare.push_back(3);
	fare.push_back(22);
	fares.push_back(fare);
	fare.clear();

	fare.push_back(1);
	fare.push_back(6);
	fare.push_back(25);
	fares.push_back(fare);
	fare.clear();


	cout << "정답은: " << endl << solution(n, s, a, b, fares) << endl;
}