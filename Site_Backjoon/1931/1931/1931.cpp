#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpr(vector<int> a, vector<int> b) {
    if (a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int main() {
    int n, str, end;
    int answer = 1;
    vector<vector<int>> meeting;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str >> end;
        meeting.push_back({ str,end });
    }
    sort(meeting.begin(), meeting.end(), cmpr);
    vector<int> now = meeting.front();
    int i = 1;
    while (i < n) {
        if (meeting[i][0] >= now[1]) {
            answer++;
            now = meeting[i];
        }
        i++;
    }

    cout << answer;
}