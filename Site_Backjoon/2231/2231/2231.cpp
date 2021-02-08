#include <iostream>
#include <string>

using namespace std;

int initer(int m) {
    int sum = m;
    string tmpstr = to_string(m);
    for (int i = 0; i < tmpstr.length(); i++)
        sum += stoi(tmpstr.substr(i, 1));
    return sum;
}

int main() {
    int n;
    cin >> n;
    int m = 1;
    while (m <= n) {
        if (initer(m) == n)
            break;
        else
            m++;
    } 

    if (m == n + 1)
        cout << 0;
    else
        cout << m;
}