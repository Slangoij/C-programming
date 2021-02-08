#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sudoku, hori, verti, zeros, answer;
vector<vector<vector<int>>> square;

void recur(int n) {
    if (n == zeros.size())
        answer = sudoku;
    else {
        int nowi = zeros[n][0], nowj = zeros[n][1];
        for (int i = 0; i < hori[nowi].size(); i++) {
            int nownum = hori[nowi][i];
            if (find(verti[nowj].begin(), verti[nowj].end(), nownum) != verti[nowj].end()
                && find(square[nowi / 3][nowj / 3].begin(), square[nowi / 3][nowj / 3].end(), nownum)
                != square[nowi / 3][nowj / 3].end()) {
                verti[nowj].erase(find(verti[nowj].begin(), verti[nowj].end(), nownum));
                square[nowi / 3][nowj / 3].erase(find(
                    square[nowi / 3][nowj / 3].begin(), square[nowi / 3][nowj / 3].end(), nownum));
                hori[nowi].erase(find(hori[nowi].begin(), hori[nowi].end(), nownum));
                sudoku[nowi][nowj] = nownum;
                recur(n + 1);
                if (answer.empty()) {
                    hori[nowi].push_back(nownum);
                    sort(hori[nowi].begin(), hori[nowi].end());
                    verti[nowj].push_back(nownum);
                    sort(verti[nowj].begin(), verti[nowj].end());
                    square[nowi / 3][nowj / 3].push_back(nownum);
                    sort(square[nowi / 3][nowj / 3].begin(), square[nowi / 3][nowj / 3].end());
                    sudoku[nowi][nowj] = 0;
                }
            }
        }
    }
}

int main() {
    int n;
    vector<int> tmp;
    for (int i = 1; i <= 9; i++)
        tmp.push_back(i);
    for (int i = 0; i < 9; i++) {
        hori.push_back(tmp);
        verti.push_back(tmp);
    }
    for (int i = 0; i < 3; i++) {
        vector<vector<int>> tmpvec;
        for (int j = 0; j < 3; j++)
            tmpvec.push_back(tmp);
        square.push_back(tmpvec);
    }
    for (int i = 0; i < 9; i++) {
        vector<int> tmpvec2;
        for (int j = 0; j < 9; j++) {
            cin >> n;
            if (n) {
                hori[i].erase(find(hori[i].begin(), hori[i].end(), n));
                verti[j].erase(find(verti[j].begin(), verti[j].end(), n));
                square[i / 3][j / 3].erase(find(
                    square[i / 3][j / 3].begin(), square[i / 3][j / 3].end(), n));
            }
            else
                zeros.push_back({ i,j });
            tmpvec2.push_back(n);
        }
        sudoku.push_back(tmpvec2);
    }

    recur(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", answer[i][j]);
        printf("\n");
    }
}