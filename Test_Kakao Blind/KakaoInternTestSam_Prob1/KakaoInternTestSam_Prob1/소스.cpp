#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> pushed;

	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {


			if (board[j][moves[i] - 1] != 0) {

				cout << "size: " << pushed.size() << ", 해당숫자: " << board[j][moves[i] - 1] << endl;
				for (int i = 0; i < pushed.size(); i++)
					cout << pushed[i] << " ";
				cout << endl;

				if (pushed.size()==0||board[j][moves[i] - 1] != pushed[pushed.size() - 1])
					pushed.push_back(board[j][moves[i] - 1]);
				else {
					pushed.pop_back();
					answer+=2;
				}
				
				board[j][moves[i] - 1] = 0;
				break;
			}

		}
	}
	/*
	while (1) {
		int i = 0;
		for (; i < pushed.size() - 1; i++) {
			if (pushed[i] == pushed[i++] && pushed[i] != 0) {
				pushed[i] = pushed[i++] = 0;
				answer++;
				break;
			}
		}
		if (i == pushed.size() - 1)
			break;
	}
	*/

	return answer;
}

int main() {
	vector<vector<int>> board;
	vector<int> moves;

	int temp;
	for (int i = 0; i < 5; i++) {
		vector<int> v;
		for (int j = 0; j < 5; j++) {
			cin >> temp;
			v.push_back(temp);
		}
		board.push_back(v);
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	moves.push_back(1);
	moves.push_back(5);
	moves.push_back(3);
	moves.push_back(5);
	moves.push_back(1);
	moves.push_back(2);
	moves.push_back(1);
	moves.push_back(4);

	cout << "정답은 : " << solution(board, moves) << endl;

	return 0;
}