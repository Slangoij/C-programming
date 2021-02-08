#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;

	q.push(truck_weights[0]);
	answer++;
	int lftsize = bridge_length - 1;
	int lftwgt = weight - truck_weights[0];
	cout << "nowansw: "<<answer << endl;
	for (int i = 1; i < truck_weights.size(); i++) {
		if (lftsize > 0 && lftwgt >= truck_weights[i]) {
			q.push(truck_weights[i]);
			answer++;
			lftsize -= 1;
			lftwgt -= truck_weights[i];
			cout << "now plus i: "<<i<<"answ: " << answer << endl;
		}
		else {
			while (!q.empty()) {
				q.pop();
			}
			q.push(truck_weights[i]);
			answer += bridge_length;
			lftsize = bridge_length - 1;
			lftwgt = weight - truck_weights[i];
			cout << "now dequeue i: " << i << "answ: " << answer << endl;
		}
	}
	if (!q.empty())
		answer += bridge_length;
	cout << "nowansw: " << answer << endl;

	return answer;
}

int main() {
	int length = 2;
	int weight = 10;
	vector<int> truckweights;

	truckweights.push_back(7);
	truckweights.push_back(4);
	truckweights.push_back(5);
	truckweights.push_back(6);

	cout << solution(2, 10, truckweights) << endl;

	return 0;
}