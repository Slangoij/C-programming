#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, tmp, answer;
    cin >> n >> m;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    int gap = abs(m - vec[0] - vec[1] - vec[2]);
    answer = vec[0] + vec[1] + vec[2];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (vec[i] + vec[j] + vec[k] <= m
                    && abs(m - vec[i] - vec[j] - vec[k]) < gap) {
                    gap = abs(m - vec[i] - vec[j] - vec[k]);
                    answer = vec[i] + vec[j] + vec[k];
                }
            }
        }
    }

    cout << answer;
}