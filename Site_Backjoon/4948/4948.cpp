#include <iostream>
#include <vector>
using namespace std;

bool isprime(int N) {
    if(N<=2)
        return false;
    for (int i = 2; i * i <= N; i++)
        if (!(N % i))
            return false;
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n = 1;
    vector<int> answer;
    while (!n) {
        cin >> n;
        int ans = 0;
        for (int i = n; i <= 2 * n; i++) {
            if (isprime(i))
                ans++;
        }
        answer.push_back(ans);
    }

    for (int i = 0; i < answer.size(); i++)
        printf("%d\n", answer[i]);
}