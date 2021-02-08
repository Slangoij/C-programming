#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second)
			return a.second > b.second;
		else
			return a.first < b.first;
		/*
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.second > b.second;

		if (a.first + a.second == b.first + b.second)
		   return a.first < b.first;
		else
		   return a.first + a.second > b.first + b.second;
		*/
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	vector<int> timev;
	pair<int, int> crnt = make_pair(-1, -1);
	int present = 0;
	int delayed = 0;

	//sort(jobs.begin(), jobs.end(), less<vector<int> >());

	while (1) {
		if (timev.size() != 0 && timev.size() == jobs.size()) { //모든 작업 저장됐을 때 종료
			cout << "timev: ";
			for (int i = 0; i < timev.size(); i++) {
				cout << timev[i] << " ";
				answer += timev[i];
			}
			break;
		}

		for (int i = 0; i < jobs.size(); i++)
			if (jobs[i][0] == present) {
				pair<int, int> tmp = make_pair(jobs[i][0], jobs[i][1]);
				pq.push(tmp);
			}
		if (crnt.second == -1 && pq.size() > 0) {
			crnt.first = pq.top().first;
			crnt.second = pq.top().second;
			pq.pop();
		}

		printf("present: %3d, crnt: %2d, %2d, delayed: %3d", present, crnt.first, crnt.second, delayed);
		if (pq.size() > 0)
			printf(", pq.top: %2d, %2d", pq.top().first, pq.top().second);
		if (timev.size() > 0) {
			cout << ", timev: ";
			for (int i = 0; i < timev.size(); i++)
				cout << timev[i] << " ";
		}

		while (crnt.second != -1 && present >= crnt.first + crnt.second + delayed) { //현재 진행작업 끝나는 시간이면
			timev.push_back(present - crnt.first); //해당 작업 대기 포함 소요시간 벡터로 저장
			if (pq.size() > 0) { //남아있는 작업이 있으면
				delayed = present - pq.top().first;
				crnt.first = pq.top().first;
				crnt.second = pq.top().second;
				pq.pop();
			}
			else {
				crnt.first = -1;
				crnt.second = -1;
			}
		}
		if (crnt.second == -1 && delayed > 0) //대기열이 비어있으면 딜레이시간 감소
			delayed--;

		cout << endl;

		present++;
	}

	return answer / jobs.size();
}



int main() {
	vector<vector<int>> jobs;
	int size1, temp;

	cout << "작업 size 입력: ";
	cin >> size1;
	cout << "작업 내용 입력: " << endl;
	for (int i = 0; i < size1; i++) {
		vector<int> v;
		for (int j = 0; j < 2; j++) {
			cin >> temp;
			v.push_back(temp);
		}
		jobs.push_back(v);
	}

	cout << "정답은: " << solution(jobs) << endl;
}