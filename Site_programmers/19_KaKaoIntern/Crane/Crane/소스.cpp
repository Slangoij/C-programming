#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int size = board.size();

	vector<vector<int>> newboard;
	for (int i = 0; i < size; i++) {
		vector<int> tmpvec;
		for (int j = size - 1; j >= 0; j--) {
			if (board[j][i])
				tmpvec.push_back(board[j][i]);
			else
				break;
		}
		newboard.push_back(tmpvec);
	}

	vector<int> baguni;
	for (int i = 0; i < moves.size(); i++) {
		int move = moves[i] - 1; 
		if (!newboard[move].empty()) {
			if (baguni.empty() || newboard[move].back() != baguni.back())
				baguni.push_back(newboard[move].back());
			else {
				baguni.pop_back();
				answer += 2;
			}
			newboard[move].pop_back();
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> board{ {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} };
	vector<int> moves{ 1, 5, 3, 5, 1, 2, 1, 4 };

	cout << solution(board, moves) << endl;
}