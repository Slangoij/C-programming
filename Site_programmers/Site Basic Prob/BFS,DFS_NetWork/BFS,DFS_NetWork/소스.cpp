#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> unvisited;

void visitdownonce(int i, vector<vector<int>> computers) {
	for (vector<int>::iterator itr = unvisited.begin(); itr != unvisited.end();) {
		if (*itr == i)
			itr = unvisited.erase(itr);
		else
			++itr;
	}
	vector<int> crntvec;
	for (int k = 0; k < unvisited.size(); k++) {
		if (computers[i][unvisited[k]] == 1) {
			crntvec.push_back(unvisited[k]);
		}
	}

	if (crntvec.size() == 0) {
		return;
	}
	else {
		for (int p = 0; p < crntvec.size(); p++) {
			for (int k = 0; k < unvisited.size(); k++) {
				if (unvisited[k] == crntvec[p])
					visitdownonce(crntvec[p], computers);
			}
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	while (unvisited.size() > 0) {
		answer++;
		visitdownonce(unvisited[0], computers);
	}

	return answer;
}

int main() {
	int n;
	int temp;
	int ding;
	vector<vector<int>> vec;

	while (1) {
		unvisited.clear();
		vec.clear();

		cout << "크기는: ";
		cin >> n;
		for (int i = 0; i < n; i++)
			unvisited.push_back(i);
		for (int i = 0; i < n; i++) {
			vector<int> row;
			for (int j = 0; j < n; j++) {
				cin >> temp;
				row.push_back(temp);
			}
			vec.push_back(row);
		}

		cout << "정답은 : " << solution(n, vec) << endl;

		cout << "계속하려면 1, 아니면 0: ";
		cin >> ding;
		if (ding == 0)
			break;
	}

	return 0;
}