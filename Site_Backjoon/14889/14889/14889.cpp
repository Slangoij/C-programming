#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> permus, power;
vector<int> permu, strvec, linkvec;
int answer = -1;

void makepermus(int now, int str, int n) {
	if (now >= n / 2)
		permus.push_back(permu);
	else {
		for (int i = str; i <= n; i++) {
			permu.push_back(i);
			makepermus(now + 1, i + 1, n);
			permu.pop_back();
		}
	}
}

int makesum(vector<int> team) {
	int ans = 0;
	for (int i = 0; i < team.size(); i++) {
		for (int j = i + 1; j < team.size(); j++) {
			ans += power[team[i] - 1][team[j] - 1];
		}
	}
	return ans;
}

int main()
{
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> tmpvec;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			tmpvec.push_back(tmp);
			if (i >= j) {

			}
		}
		power.push_back(tmpvec);
	}
	for (int j = 0; j < n; j++)
		for (int i = j + 1; i < n; i++)
			power[j][i] += power[i][j];

	makepermus(0, 1, n);
	/*
	for (int i = 0; i < permus.size() / 2; i++) {
		permus[i].insert(permus[i].end(), permus[permus.size() - i - 1].begin(),
			permus[permus.size() - i - 1].end());
	}
	permus.erase(permus.begin() + (permus.size() / 2), permus.end());
	*/

	for (int i = 0; i < permus.size() / 2; i++) {
		int strteam = i, linkteam = permus.size() - i - 1;
		strvec = permus[strteam], linkvec = permus[linkteam];
		if (answer == -1)
			answer = abs(makesum(strvec)-makesum(linkvec));
		else
			answer = min(answer, abs(makesum(strvec) - makesum(linkvec)));
	}

	cout << answer;
}