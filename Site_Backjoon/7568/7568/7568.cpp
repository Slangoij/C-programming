#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, tmp1, tmp2;
    vector<int> answer;
    vector<vector<int>> dungchis;

    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> tmpvec;
        cin >> tmp1 >> tmp2;
        tmpvec.push_back(tmp1);
        tmpvec.push_back(tmp2);
        dungchis.push_back(tmpvec);
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            else if (dungchis[j][0] > dungchis[i][0]
                && dungchis[j][1] > dungchis[i][1])
                cnt++;
        }
        answer.push_back(cnt);
    }

    printf("%d", answer.front());
    for (int i = 1; i < n; i++)
        printf(" %d", answer[i]);
}

/*
vector<vector<int>> dungchis;

bool cmpr(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] > b[0];
}

bool rearr(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int main() {
    int n, tmp1, tmp2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> tmpvec;
        cin >> tmp1 >> tmp2;
        tmpvec.push_back(tmp1);
        tmpvec.push_back(tmp2);
        tmpvec.push_back(i);
        dungchis.push_back(tmpvec);
    }

    sort(dungchis.begin(), dungchis.end(), cmpr);

    vector<int> now = dungchis.front();
    int tmp = 1;
    dungchis.front().push_back(tmp);
    for (int i = 1; i < n; i++) {
        if (now[0] > dungchis[i][0]
            && now[1] > dungchis[i][1]) {
            tmp = i + 1;
            now = dungchis[i];
        }
        dungchis[i].push_back(tmp);
    }

    sort(dungchis.begin(), dungchis.end(), rearr);

    printf("%d", dungchis.front()[3]);
    for (int i = 1; i < n; i++)
        printf(" %d", dungchis[i][3]);
}
*/