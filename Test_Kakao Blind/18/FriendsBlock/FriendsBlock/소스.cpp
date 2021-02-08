#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board);

int main() {
	int m = 5;
	int n = 6;
	vector<string> board;

	/*
	board.push_back("CCBDEA");
	board.push_back("CCADEA");
	*/
	/*
	board.push_back("CCBDE");
	board.push_back("AAADE");
	board.push_back("AAABF");
	board.push_back("CCBBF");
	*/

	board.push_back("AAAAAA");
	board.push_back("BBAATB");
	board.push_back("BBAATB");
	board.push_back("JJJTAA");
	board.push_back("JJJTAA");

	cout << "정답은:   " << solution(m, n, board) << endl << endl;
}

/*
int solution(int m, int n, vector<string> board) {
	int answer = 0;

	vector<vector<int>> newboard;
	for (int j = 0; j < n; j++) {
		vector<int> line;
		for (int i = 0; i < m; i++) {
			line.push_back(board[i][j]);
		}
		newboard.push_back(line);
	}


	return answer;
}
*/


int solution(int m, int n, vector<string> board) {
	int answer = 0;

	int **checkarr = new int*[m];
	int **boardarr = new int*[m];

	for (int i = 0; i < m; i++) {
		checkarr[i] = new int[n];
		boardarr[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			checkarr[i][j] = 0;
			boardarr[i][j] = board[i][j];
		}


	int checkarrin1 = 1;
	// 한번에 지울 것 체크, 지우고 내리기 한번씩
	while (checkarrin1 != 0) {
		checkarrin1 = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				checkarr[i][j] = 0;

		// checkarr에 지울 좌표 체크
		if (m > 1 && n > 1) {
			for (int i = 0; i < m - 1; i++) {
				for (int j = 0; j < n - 1; j++) {
					if (boardarr[i][j] != 0
						&& boardarr[i][j] == boardarr[i + 1][j + 1]
						&& boardarr[i][j] == boardarr[i][j + 1]
						&& boardarr[i][j] == boardarr[i + 1][j]) {
						checkarr[i][j]++, checkarr[i + 1][j + 1]++;
						checkarr[i][j + 1]++, checkarr[i + 1][j]++;
						checkarrin1++;
					}
				}
			}
		}
		else
			break;

		cout << "잠시만 체크퍼르스트" << endl;
		cout << "checkarr는:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (checkarr[i][j] == 0)
					cout << "  0";
				else
					printf("%3d", checkarr[i][j]);
			}
			cout << endl;
		}
		cout << "boardarr는:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				if (boardarr[i][j] == 0)
					cout << "  0";
				else
					printf("%3c", boardarr[i][j]);
			cout << endl;
		}
		cout << endl;

		// 지울 블럭 정답에 입력
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (checkarr[i][j] != 0) {
					answer++;
					boardarr[i][j] = 0;
				}

		cout << "잠시만 체크세ㄱ컨드르" << endl;
		cout << "boardarr는:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				if (boardarr[i][j] == 0)
					cout << "  0";
				else
					printf("%3c", boardarr[i][j]);
			cout << endl;
		}
		cout << endl;

		// 내려서 빈 칸 채우기
		for (int j = 0; j < n; j++) {
			cout << "j: " << j << endl;
			for (int i = m - 1; i > 0; i--) {
				for (int tmp = i - 1; tmp >= 0; tmp--) {
					if (boardarr[i][j] == 0 && boardarr[tmp][j] != 0) {
						boardarr[i][j] = boardarr[tmp][j];
						boardarr[tmp][j] = 0;
						cout << "  잠시 i췍: " << i << " / tmp는: " << tmp << endl;
						break;
					}
				}

				/*
				if (checkarr[i][j] != 0) {
					while (tmpidx >= 0 && checkarr[tmpidx][j] != 0) {
						tmpidx--;
					}
					if (i > 1 && tmpidx >= 0) {
						boardarr[i][j] = boardarr[tmpidx][j];
						boardarr[tmpidx][j] = 0;
					}
					else {
						boardarr[i][j] = 0;
					}
				}
				*/
			}
		}

		cout << "잠시만 체크써드르" << endl;
		cout << "boardarr는:" << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				if (boardarr[i][j] == 0)
					cout << "  0";
				else
					printf("%3c", boardarr[i][j]);
			cout << endl;
		}
		cout << endl;
	}


	for (int i = 0; i < m; i++)
		delete[] checkarr[i], boardarr[i];
	delete[] checkarr, boardarr;


	int i = 0;



	return answer;
}