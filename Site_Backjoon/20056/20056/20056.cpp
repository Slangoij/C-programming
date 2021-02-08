#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct fire {
	int r, c, m, s, d;
};

vector<fire> fires;

fire move(fire nowfire, int d, int s,int n) {
	if (d == 0 || d == 1 || d == 7) {
		nowfire.r = (nowfire.r - s) % n;
		if (nowfire.r < 0)
			nowfire.r += n;
	}
	else if (d > 2 && d < 6) {
		nowfire.r = (nowfire.r + s) % n;
	}

	if (d > 0 && d < 4) {
		nowfire.c = (nowfire.c + s) % n;
	}
	else if (d > 4 && d < 8) {
		nowfire.c = (nowfire.c - s) % n;
		if (nowfire.c < 0)
			nowfire.c += n;
	}

	return nowfire;
}

int solution(int n,int k) {
	vector<vector<fire>> hashedloca;
	vector<int> posvec;

	for (int it = 0; it < k; it++) {
		hashedloca.clear(), posvec.clear();
		for (int i = 0; i < n * n; i++)
			hashedloca.push_back({ { -1,-1,-1,-1,-1 } });

		int hashed;
		for (int i = 0; i < fires.size(); i++) {
			fires[i] = move(fires[i], fires[i].d, fires[i].s, n);
			hashed = fires[i].r * n + fires[i].c;
			if (hashedloca[hashed].front().r == -1) {
				hashedloca[hashed] = { fires[i] };
				posvec.push_back(hashed);
			}
			else
				hashedloca[hashed].push_back(fires[i]);
		}

		fires.clear();

		for (int i = 0; i < posvec.size(); i++) {
			int nowhashed = posvec[i];
			if (hashedloca[nowhashed].size() > 1) {
				int msum = 0, ssum = 0;
				bool dallodd = true, dalleven = true;
				for (int j = 0; j < hashedloca[nowhashed].size(); j++) {
					msum += hashedloca[nowhashed][j].m;
					ssum += hashedloca[nowhashed][j].s;
					if (hashedloca[nowhashed][j].d % 2)
						dalleven = false;
					else
						dallodd = false;
				}
 				if (msum / 5) {
					int tmpr = nowhashed / n;
					int tmpc = nowhashed % n;
					int tmpm = msum / 5;
					int tmps = ssum / hashedloca[nowhashed].size();
					for (int j = 0; j < 4; j++) {
						int tmpd = j * 2;
						if (!dalleven && !dallodd)
							tmpd++;
						fires.push_back({ tmpr,tmpc,tmpm,tmps,tmpd });
					}
				}
			}
			else
				fires.push_back(hashedloca[posvec[i]].front());
		}
	}

	int answer = 0;
	for (int i = 0; i < fires.size(); i++)
		answer += fires[i].m;

	return answer;
}

int main() {
	int n, m, k;

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		fire tmp;
		cin >> tmp.r >> tmp.c
			>> tmp.m >> tmp.s >> tmp.d;
		fires.push_back({ tmp.r - 1,tmp.c - 1,tmp.m,tmp.s,tmp.d });
	}

	cout << solution(n, k);
	cout << "itis~" << endl;
}