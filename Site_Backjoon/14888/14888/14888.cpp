#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> answer;
vector<long long> tmpans;
vector<int> nums, opers, tmpopers;

long long cal(int num1, int op, int num2) {
	switch (op) {
	case 0:
		return num1 + num2;
		break;
	case 1:
		return num1 - num2;
		break;
	case 2:
		return num1 * num2;
		break;
	case 3:
		return num1 / num2;
		break;
	}
}

long long revcal(int num1, int op, int num2) {
	switch (op) {
	case 0:
		return num1 - num2;
		break;
	case 1:
		return num1 + num2;
		break;
	case 2:
		return num1 / num2;
		break;
	case 3:
		return num1 * num2;
		break;
	}
}

void recur(int now, int target) {
	if (now == target) {
		if (answer.empty())
			answer = { tmpans.back(),tmpans.back() };
		else {
			answer[0] = max(answer[0], tmpans.back());
			answer[1] = min(answer[1], tmpans.back());
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (tmpopers[i]) {
				tmpopers[i]--;
				tmpans[now] = cal(tmpans[now - 1], i, nums[now]);
				recur(now + 1, target);
				if (tmpopers[i] < opers[i])
					tmpopers[i]++;
			}
		}
	}
}

int main()
{
	int n,tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
		tmpans.push_back(nums[0]);
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		opers.push_back(tmp);
	}
	tmpopers = opers;

	recur(1, n);

	printf("%lld\n%lld", answer[0], answer[1]);
}