#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct set {
	int card, x, y;
};

/*
int flag[7] = { 0, };
void jagui(int i, int size, int flag[], vector<int> permu, vector<vector<int>> permus) {
	for (int j = 0; j < size; j++) {
		if (!flag[j]) {
			permu.push_back(j);
			if (i == size)
				permus.push_back(permu);
			else {
				flag[j] = 1;
				jagui(i + 1, size, flag, permu, permus);
				flag[j] = 0;
			}
		}
	}
}

*/

int onedirect(int a, int b) {
	if (a == b)
		return 0;
	else if (abs(a - b) == 2 && (a == 0 || a == 3))
		return 2;
	else
		return 1;
}

int getmoves(set str, set end) {
	return onedirect(str.x, end.x) + onedirect(str.y, end.y);
}

bool cmpr(set a, set b) {
	if (a.card == b.card) {
		return a.x < b.x;
	}
	else
		return a.card < b.card;
}

int solution(vector<vector<int>> board, int r, int c) {
	int answer = 0;
	int nowstrcard = board[r][c];

	vector<set> strcards;
	vector<set> cards;

	strcards.push_back({ board[r][c],c,r });
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j]) {
				if (i == r && j == c)
					continue;
				else if (nowstrcard&&board[i][j] == nowstrcard)
					strcards.push_back({ board[i][j],j,i });
				else
					cards.push_back({ board[i][j],j,i });
			}
		}
	}

	/*
	   for (int i = 0; i < cards.size() - 1; i++) {
		  for (int j = i + 1; j < cards.size(); j++) {
			 if (cards[i].card == cards[j].card) {
				vector<set> tmpcardset;
				tmpcardset.push_back(cards[i]);
				tmpcardset.push_back(cards[j]);
				cardset.push_back(tmpcardset);
			 }
		  }
	   }
	*/

	sort(cards.begin(), cards.end(), cmpr);

	vector<vector<set>> cardset;
	for (int i = 0; i < cards.size() / 2; i++) {
		vector<set> tmpcards;
		tmpcards.push_back(cards[2 * i]);
		tmpcards.push_back(cards[2 * i + 1]);
		cardset.push_back(tmpcards);
	}

	//jagui(0, cardset.size(), flag, permu, permus);
	vector<vector<int>> permus;
	vector<int> permu;
	for (int i = 0; i < cardset.size(); i++)
		permu.push_back(i);
	do permus.push_back(permu);
	while (next_permutation(permu.begin(), permu.end()));


	vector<int> answers;
	for (int i = 0; i < permus.size(); i++) {
		for (int j = 0; j < (1 << cardset.size()); j++) {
			int tmpanswer = 0;
			int cardsetlastidx = cardset.size() - 1;
			int firbit = !!(j & (1 << cardsetlastidx));
			int lastbit = !!(j & 1);
			if (strcards.size() > 1)
				tmpanswer += getmoves(strcards.front(), strcards.back());
			tmpanswer += getmoves(strcards.back(), cardset[permus[i][0]][firbit % 2]);
			for (int k = 0; k < permus[i].size() - 1; k++) {
				int nowbit = !!(j & (1 << (cardsetlastidx - k)));
				int nextbit = !!(j & (1 << (cardsetlastidx - k - 1)));
				tmpanswer += getmoves(cardset[permus[i][k]][nowbit % 2],
					cardset[permus[i][k]][(nowbit + 1) % 2]);
				tmpanswer += getmoves(cardset[permus[i][k]][(nowbit + 1) % 2],
					cardset[permus[i][k + 1]][nextbit % 2]);
			}
			tmpanswer += getmoves(cardset[permus[i].back()][lastbit % 2], 
				cardset[permus[i].back()][(lastbit + 1) % 2]);
			answers.push_back(tmpanswer);
		}
	}

	sort(answers.begin(), answers.end());

	answer = answers.front() + cards.size();
	if (strcards.size() > 1)
		answer += 1;
	return answer;
}


int main() {
	vector<vector<int>> board;

	/*
	int r = 1;
	int c = 0;
	vector<int> tmpboard1;
	tmpboard1.push_back(1);
	tmpboard1.push_back(0);
	tmpboard1.push_back(0);
	tmpboard1.push_back(3);
	board.push_back(tmpboard1);

	vector<int> tmpboard2;
	tmpboard2.push_back(2);
	tmpboard2.push_back(0);
	tmpboard2.push_back(0);
	tmpboard2.push_back(0);
	board.push_back(tmpboard2);

	vector<int> tmpboard3;
	tmpboard3.push_back(0);
	tmpboard3.push_back(0);
	tmpboard3.push_back(0);
	tmpboard3.push_back(2);
	board.push_back(tmpboard3);

	vector<int> tmpboard4;
	tmpboard4.push_back(3);
	tmpboard4.push_back(0);
	tmpboard4.push_back(1);
	tmpboard4.push_back(0);
	board.push_back(tmpboard4);
	*/

	int r = 0;
	int c = 1;
	vector<int> tmpboard1;
	tmpboard1.push_back(3);
	tmpboard1.push_back(0);
	tmpboard1.push_back(0);
	tmpboard1.push_back(2);
	board.push_back(tmpboard1);

	vector<int> tmpboard2;
	tmpboard2.push_back(0);
	tmpboard2.push_back(0);
	tmpboard2.push_back(1);
	tmpboard2.push_back(0);
	board.push_back(tmpboard2);

	vector<int> tmpboard3;
	tmpboard3.push_back(0);
	tmpboard3.push_back(1);
	tmpboard3.push_back(0);
	tmpboard3.push_back(0);
	board.push_back(tmpboard3);

	vector<int> tmpboard4;
	tmpboard4.push_back(2);
	tmpboard4.push_back(0);
	tmpboard4.push_back(0);
	tmpboard4.push_back(3);
	board.push_back(tmpboard4);

	cout << "Á¤´äÀº: " << solution(board, r, c) << endl;
}