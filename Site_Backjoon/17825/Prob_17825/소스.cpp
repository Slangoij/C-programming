#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int x, y;
};

pos posarr[4] = { 0, 0 };
int answer = 0;
vector<int> answers;

bool issamepos(pos a, pos b) {
	if (a.x == b.x &&a.y == b.y)
		return true;
	else
		return false;
}

bool isoverlap(pos posarr[4], int path[4][30]) {
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			int i_x = posarr[i].x, i_y = posarr[i].y;
			int j_x = posarr[j].x, j_y = posarr[j].y;
			if (i_x && j_x
				&& path[i_y][i_x] != -1
				&& issamepos(posarr[i], posarr[j]))
				return true;
			else if (path[i_y][i_x] == path[j_y][j_x]) {
				int val = path[i_y][i_x];
				if (val == 25 || (val == 30&&((!i_x&&j_x)||(i_x&&!j_x))) || val == 35 || val == 40)
					return true;
			}
		}
	}
	return false;
}

void dfs(int diceidx, vector<int> dices, pos posarr[], int path[4][30]) {
	if (diceidx == 10) {
		answers.push_back(answer);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int dx = dices[diceidx], or_x = posarr[i].x, to_x = posarr[i].x + dx;
			int dy = 0, or_y = posarr[i].y;
			if (!posarr[i].y)
				if (to_x == 5)
					dy = 1;
				else if (to_x == 10)
					dy = 2;
				else if (to_x == 15)
					dy = 3;
			int to_y = posarr[i].y + dy;
			if (to_y == 0 && to_x > 21) {
				to_x = 21; dx = 21 - posarr[i].x;
			}
			else if (to_y == 1 && to_x > 13) {
				to_x = 13; dx = 13 - posarr[i].x;
			}
			else if (to_y == 2 && to_x > 17) {
				to_x = 17; dx = 17 - posarr[i].x;
			}
			else if (to_y == 3 && to_x > 23) {
				to_x = 23; dx = 23 - posarr[i].x;
			}

			posarr[i].x += dx; posarr[i].y += dy;

			if (path[or_y][or_x] == -1 || isoverlap(posarr, path)) {
				posarr[i].x -= dx; posarr[i].y -= dy;
				continue;
			}
			else {
				if (path[to_y][to_x] != -1) {
					answer += path[to_y][to_x];
					//cout << "answer: " << answer << endl;
				}
				dfs(diceidx + 1, dices, posarr, path);
				if (path[to_y][to_x] != -1)
					answer -= path[to_y][to_x];
				posarr[i].x -= dx; posarr[i].y -= dy;
			}
		}
	}
}


int main() {
	int path[4][30] = { 0 };

	for (int i = 1; i <= 20; i++)
		path[0][i] = 2 * i;
	for (int i = 5; i <= 8; i++)
		path[1][i] = 3 * i - 5;
	for (int i = 10; i <= 12; i++)
		path[2][i] = 2 * i;
	for (int i = 16; i <= 18; i++)
		path[3][i] = 44 - i;
	path[3][15] = 30;
	for (int i = 0; i < 4; i++) {
		int val = (i + 5) * 5;
		path[1][i + 9] = path[3][i + 19] = path[2][i + 13] = val;
	}

	// 마지막 -1 로 저장
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (path[i][j] != 40)
			j++;
		path[i][j + 1] = -1;
	}

	cout << "지금 상태 : " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 30; j++) {
			printf("%3d", path[i][j]);
		}
		cout << endl;
	}

	vector<int> dices;
	int dice;
	for (int i = 0; i < 10; i++) {
		cin >> dice;
		dices.push_back(dice);
	}

	dfs(0, dices, posarr, path);
	sort(answers.begin(), answers.end(),greater<int>());

	cout << "정답은: " << answers[0] << endl << endl;
}