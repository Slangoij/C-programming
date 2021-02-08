#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, now = 1, num = 1;
    string answer;
    cin >> n;

    while (now < n) {
        num++;
        now += num;
    }

    if (num % 2) {
        answer += to_string(now - n + 1);
        answer += "/";
        answer += to_string(n + num - now);
    }
    else {
        answer += to_string(n + num - now);
        answer += "/";
        answer += to_string(now - n + 1);
    }

    cout << answer;
}