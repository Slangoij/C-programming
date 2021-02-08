#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define hashsize 1000;

/*
struct player {
	int count;
	string name;
};
*/

int hashed(string temp) {
	int mul = 1;
	int x = 0;
	for (int i = 0; temp[i] != 0; i++) {
		x = ((temp[i] * mul) + x) % hashsize;
		mul *= 29;
	}
	if (x < 0) x = -x;
	return x % hashsize;
}

int hashed1(string temp) {
	int mul = 2;
	int x = 0;
	for (int i = 0; temp[i] != 0; i++) {
		x = ((temp[i] * mul) + x) % hashsize;
		mul *= 31;
	}
	if (x < 0) x = -x;
	return x % hashsize;
}

/*
int hashing(string temp, vector<player> players) {
	for (int i = 0; i < players.size(); i++) {
		if (temp == players[i].name)
			return i;
	}
}
*/

string solution(vector<string> participant, vector<string> completion) {
	
	/*
	string answer = "";
	vector<player> players;

	player card;
	card.count = 1;
	card.name = participant[0];
	players.push_back(card);

	//players 해시테이블 만들기
	for (int i = 1; i < participant.size(); i++) {
		int same = false;
		for (int j = 0; j < players.size(); j++) {
			cout << i << "와 " << j << "를 비교중" << endl;
			if (participant[i] == players[j].name) {
				cout << "더하는중" << endl;
				same = true;
				players[j].count++;
			}
		}
		if (same == false) {
			cout << "추가중" << endl;
			player card;
			card.count = 1;
			card.name = participant[i];
			players.push_back(card);
		}
	}

	for (int i = 0; i < players.size(); i++) {
		for (int j = 0; j < completion.size(); j++) {
			if (players[i].name == completion[j])
				players[i].count--;
		}
	}

	for (int i = 0; i < players.size(); i++)
		if (players[i].count == 1)
			answer = players[i].name;*/

	int hashtable[1000][2] = { 0 };

	for (int i = 0; i < participant.size(); i++) {
		hashtable[hashed(participant[i])][0]++;
		hashtable[hashed1(participant[i])][1]++;
	}

	for (int j = 0; j < completion.size(); j++) {
		hashtable[hashed(completion[j])][0]--;
		hashtable[hashed1(completion[j])][1]--;
	}

	for (int i = 0; i < participant.size(); i++) {
		if (hashtable[hashed(participant[i])][0] > 0 && hashtable[hashed1(participant[i])][1] > 0)
			return participant[i];
	}
}

int main() {
	string temp;
	vector<string> participant;
	vector<string> completion;

	while (1) {
		cin >> temp;
		if (temp == "-1")
			break;
		participant.push_back(temp);
	}
	while (1) {
		cin >> temp;
		if (temp == "-1")
			break;
		completion.push_back(temp);
	}
	cout << "participant: ";
	for (int i = 0; i < participant.size(); i++)
		cout << participant[i] << " ";
	cout << endl << "completion: ";
	for (int i = 0; i < completion.size(); i++)
		cout << completion[i] << " ";

	cout << endl << "정답은 : " << solution(participant, completion) << endl;

	return 0;
}