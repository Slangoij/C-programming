#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> convey;
vector<int> robot;

void rotate(int n) {
    int tmp = convey.back();
    for (int i = convey.size() - 2; i >= 0; i--)
        convey[i + 1] = convey[i];
    convey[0] = tmp;
    /*
    */
    for (int i = 0; i < robot.size(); i++) {
        robot[i]++;
    }
    if (!robot.empty() && robot.front() >= n - 1)
        robot.erase(robot.begin());
}

int solution(int n, int k, vector<int> a) {
    int answer = 1, zero = 0;
    convey = a;

    rotate(n);
    if (convey[0]) {
        robot.push_back(0);
        convey[0]--;
        if (!convey[0])
            zero++;
    }

    int now, next;
    while (zero < k) {
        rotate(n);
        while (!robot.empty() && robot.front() >= n - 1)
            robot.erase(robot.begin());
        for (int i = 0; i < robot.size(); i++) {
            now = robot[i], next = now + 1;
            if (convey[next] && (!i || (i && next != robot[i - 1]))) {
                convey[next]--;
                if (!convey[next])
                    zero++;
                robot[i] = next;
            }
        }
        /*
        if (!robot.empty() && !robot.front())
            sort(robot.begin(), robot.end(), greater<int>());
        */
        if (convey[0] && (robot.empty() || (!robot.empty() && robot.back()))) {
            robot.push_back(0);
            convey[0]--;
            if (!convey[0])
                zero++;
        }
        answer++;
    }

    return answer;
}

int main() {
    int n, k;
    vector<int> a;

    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    cout << "Á¤´äÀº : " << solution(n, k, a);
}