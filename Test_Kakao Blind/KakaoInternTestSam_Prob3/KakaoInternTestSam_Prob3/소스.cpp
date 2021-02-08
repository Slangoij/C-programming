#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxgap(vector<int> stones, int target);

int solution(vector<int> stones, int k) {
	int answer = 0;
	int maxstone = stones[0];
	int minstone = stones[0];
	vector<int> grsh; //다음 돌이 더 큰지 작은지

	for (int i = 1; i < stones.size(); i++) {
		maxstone = max(maxstone, stones[i]);
		minstone = min(minstone, stones[i]);
	}
	/*
	for (int i = 0; i < stones.size() - 1; i++) {

		if (stones[i + 1] < stones[i])
			grsh.push_back(-1);
		else if (stones[i + 1] > stones[i])
			grsh.push_back(1);
		else
			grsh.push_back(0);

	}
	grsh.push_back(0);

	cout <<", grsh: ";
	for (int i = 0; i < grsh.size(); i++)
		cout << grsh[i] << " ";
	cout << "grsh size: " << grsh.size();
	cout << endl;
	*/

	//출력
	cout << "stones: ";
	for (int i = 0; i < stones.size(); i++)
		cout << stones[i] << " ";
	cout << "stones size: " << stones.size() << ", maxstone: " << maxstone << ", minstone: " << minstone << endl;

	answer = (maxstone + minstone) / 2;
	while (maxgap(stones, answer) != k && minstone != maxstone) {
		cout << "answer: " << answer << " ,maxgap: " << maxgap(stones, answer) << endl;
		if (maxgap(stones, answer) < k)
			minstone = answer;
		else
			maxstone = answer;
		answer = (maxstone + minstone) / 2;
	}
	cout << "yes" << endl;
	while (maxgap(stones, answer - 1) == k) {
		answer--;
	}

	return answer;
}

int maxgap(vector<int> stones, int target) {  //vector<int> grsh)
	vector<int> thatstone;
	vector<int> gaps;
	int temp = 0;

	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] > target) {
			thatstone.push_back(i);
		}
		if (stones[i] <= target)
			temp++;
		else {
			gaps.push_back(temp);
			temp = 0;
		}
	}

	temp = gaps[0];
	for (int i = 0; i < gaps.size(); i++)
		temp = max(temp, gaps[i]);

	return temp;
	/*
	for (int i = 0; i < thatstone.size() - 1; i++) {
		if (gaps.size() == 0 && grsh[i] == 1) {
			gaps.push_back(i);
		}
		if (grsh[i] == -1) {
			int j = i + 1;
			for (; j < thatstone.size() - 1; j++) {
				if (grsh[j] == 1)
					gaps.push_back(i - j);
				break;
			}
			if (j == thatstone.size() - 1)
				gaps.push_back(thatstone.size() - i);
		}
	}

	if (gaps.size() != 0) {
		bigtemp = gaps[0];
		for (int i = 0; i < gaps.size(); i++)
			bigtemp = max(bigtemp, gaps[i]);
	}
	else
		bigtemp = -1;

	return bigtemp;*/
}

int main() {
	vector<int> stones;
	int k;
	int temp;
	cout << "stones 입력: " << endl;
	while(1) {
		cin >> temp;
		if (temp == -1)
			break;
		stones.push_back(temp);
	}
	cout << "k 입력: ";
	cin >> k;

	cout << "정답은: " << solution(stones, k) << endl;
	return 0;
}