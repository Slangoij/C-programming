#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
struct tosearch {
	int idxx, idxy, lv;
};
bool isallsamenum(int strx, int stry, int lv, vector<vector<int>> arr) {
	int length = pow(2, lv);
	if (lv == 0)
		return true;
	else {
		int nownum = arr[strx][stry];
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (arr[strx + i][stry + j] != nownum)
					return false;
				//if (arr[strx + i][stry + j] != arr[strx + i + 1][stry + i]
					//|| arr[strx + i][stry + j] != arr[strx + i][stry + i + 1]
					//|| arr[strx + i][stry + j] != arr[strx + i + 1][stry + 1])
					//return false;
			}
		}
		return true;
	}
}
bool ispure(vector<tosearch> now,vector<vector<int>> arr) {
	for (int i = 0; i < now.size(); i++) {
		if (!isallsamenum(now[i].idxx, now[i].idxy, now[i].lv,arr))
			return false;
	}
	return true;
}
vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;

	int lv;
	for (int i = 0; i < 11; i++)
		if (pow(2, i) == arr.size()) {
			lv = i;
			break;
		}

	vector<vector<tosearch>> list;
	vector<tosearch> tmp{ { 0,0,lv } };
	list.push_back(tmp);
	int nowidx = 0;
	int tmpx, tmpy, gap;
	while (!ispure(list[nowidx],arr)) {
		tmp.clear();
		int j = 0;
		while (j < list[nowidx].size()) {
			tmpx = list[nowidx][j].idxx;
			tmpy = list[nowidx][j].idxy;
			if (!isallsamenum(tmpx, tmpy, lv, arr)) {
				gap = pow(2, lv - 1);
				tmp.push_back({ tmpx,tmpy,lv - 1 });
				tmp.push_back({ tmpx + gap,tmpy,lv - 1 });
				tmp.push_back({ tmpx,tmpy + gap,lv - 1 });
				tmp.push_back({ tmpx + gap,tmpy + gap,lv - 1 });
				list[nowidx].erase(list[nowidx].begin() + j);
			}
			else
				j++;
		}
		list.push_back(tmp);
		nowidx++, lv--;
	}

	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < list[i].size(); j++) {
			if (arr[list[i][j].idxx][list[i][j].idxy] == 0)
				cnt0++;
			else
				cnt1++;
		}
	}
	answer = { cnt0,cnt1 };

	return answer;
}

*/

/*
vector<vector<bool>> didarr;
bool isallsamenum(int strx, int stry, int lv, vector<vector<int>> arr) {
	int length = pow(2, lv);
	if (lv == 0)
		return true;
	else {
		int nownum = arr[strx][stry];
		for (int i = length / 2; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (arr[strx + i][stry + j] != nownum)
					return false;
			}
		}
		for (int i = 0; i < length / 2; i++) {
			for (int j = length / 2; j < length; j++) {
				if (arr[strx + i][stry + j] != nownum)
					return false;
			}
		}

		return true;
	}
}
void setallnum(int strx, int stry, int lv) {
	int length = pow(2, lv);
	for (int i = length / 2; i < length; i++)
		for (int j = 0; j < length; j++)
			didarr[strx + i][stry + j] = true;
	for (int i = 0; i < length / 2; i++)
		for (int j = length / 2; j < length; j++)
			didarr[strx + i][stry + j] = true;
}
vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer(2, 0);

	int len = arr.size(), LV = 0;
	for (int i = 0; i < len; i++) {
		vector<bool> tmp(len, false);
		didarr.push_back(tmp);
	}
	for (int i = 0; i < 11; i++)
		if (pow(2, i) == len) {
			LV = i;
			break;
		}

	int lv,nowlen;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (didarr[i][j])
				continue;
			else {
				lv = 0, nowlen = 1;
				while (!(i%nowlen) && !(j%nowlen) && lv <= LV
					&& isallsamenum(i, j, lv, arr) 
					&& i + nowlen <= len && j + nowlen <= len) {
					setallnum(i, j, lv);
					lv++, nowlen = (int)pow(2, lv);
				}
				if (arr[i][j])
					answer[1]++;
				else
					answer[0]++;
			}
		}
	}

	return answer;
}
*/

vector<vector<int>> map;
vector<int> answer(2, 0);

bool isallsamenum(int strx, int stry, int length) {
	if (length == 1)
		return true;
	else {
		int nownum = map[strx][stry];
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (map[strx + i][stry + j] != nownum)
					return false;
			}
		}
		return true;
	}
}
void recur(int strx, int stry, int length) {
	if (isallsamenum(strx, stry, length))
		answer[map[strx][stry]]++;
	else {
		if (isallsamenum(strx, stry, length / 2))
			answer[map[strx][stry]]++;
		else
			recur(strx, stry, length / 2);

		if (isallsamenum(strx + length / 2, stry, length / 2))
			answer[map[strx + length / 2][stry]]++;
		else
			recur(strx + length / 2, stry, length / 2);

		if (isallsamenum(strx, stry + length / 2, length / 2))
			answer[map[strx][stry + length / 2]]++;
		else
			recur(strx, stry + length / 2, length / 2);

		if (isallsamenum(strx + length / 2, stry + length / 2, length / 2))
			answer[map[strx + length / 2][stry + length / 2]]++;
		else
			recur(strx + length / 2, stry + length / 2, length / 2);
	}
}
vector<int> solution(vector<vector<int>> arr) {
	map = arr;
	recur(0, 0, arr.size());
	vector<int> ansvec = answer;

	return ansvec;
}

int main() {
	/*
	vector<vector<int>> a{{1, 1, 1, 1, 1, 1, 1, 1}, 
	{0, 1, 1, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 0, 1, 1, 1, 1},
	{0, 1, 0, 0, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 1, 1, 1}};
	*/

	/*
	vector<vector<int>> a{{1, 1, 0, 0},
	 {1, 0, 0, 0},
	 {1, 0, 0, 1},
	 {1, 1, 1, 1}};
	*/

	/*
	vector<vector<int>> a{ {1, 1, 1, 1},
	 {1, 1, 1, 1},
	 {1, 1, 1, 1},
	 {1, 1, 1, 1} };
	*/

	vector<vector<int>> a;
	for (int i = 0; i < 64; i++) {
		vector<int> tmp;
		for (int j = 0; j < 64; j++)
			/*
			if ((i + j) % 2)
				tmp.push_back(1);
			else
			*/
				tmp.push_back(0);
		a.push_back(tmp);
	}

	vector<int> ans = solution(a);
	
	cout << "answer: " << ans[0] << ", " << ans[1] << endl;
}