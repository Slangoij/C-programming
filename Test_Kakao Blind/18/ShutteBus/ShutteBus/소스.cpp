#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable);

int main() {
	int n = 10, t = 60, m = 45;
	vector<string> timetable;
	for (int i = 0; i < 16; i++)
		timetable.push_back("23:59");

	cout << solution(n, t, m, timetable) << endl;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	vector<int> bus;
	int bustime = 540 - t;

	for (int i = 0; i < n; i++) {
		bustime += t;
		for (int j = 0; j < m; j++)
			bus.push_back(bustime);
	}
	int lastbus = bus.back();
	sort(bus.begin(), bus.end(), greater<int>());

	sort(timetable.begin(), timetable.end(), greater<string>());
	vector<int> crew;
	for (int i = 0; i < timetable.size(); i++)
		crew.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));

	cout << "bus: " << endl;
	for (int i = 0; i < bus.size(); i++) {
		cout << bus[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl << "crew: " << endl;
	for (int i = 0; i < crew.size(); i++) {
		cout << crew[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl << endl;

	int anstime = 540, lastcrew = crew.front();
	while (bus.size() > 1 && crew.size() > 1) {
		cout << "마지막 crew: " << crew.back() << " / 마지막 bus: " << bus.back() << endl;
		cout << "crew size: " << crew.size() << " / bus size: " << bus.size() << endl << endl;
		if (crew.back() <= bus.back()) {
			crew.pop_back();
			lastcrew = crew.back();
		}
		bus.pop_back();
	}
	cout << "마지막 crew: " << lastcrew << endl;
	cout << "crew size: " << crew.size() << " / bus size: " << bus.size() << endl << endl;
	/*
	if (bus.empty() && lastcrew > 0)
		anstime = lastcrew - 1;
	else
		anstime = lastbus;
	*/

	if (bus.size() == 1 && lastcrew <= lastbus)
		anstime = lastcrew - 1;
	else
		anstime = lastbus;


	cout << endl << endl << "anstime: " << anstime << endl << endl;

	/*
	int hh = anstime / 60;
	int mm = anstime % 60;

	if (hh <= 9) {
		answer += '0';
		if (hh == 0)
			answer += '0';
		else
			answer += to_string(hh);
	}
	else
		answer += to_string(hh);
	answer += ':';
	if (mm <= 9) {
		answer += '0';
		if (mm == 0)
			answer += '0';
		else
			answer += to_string(mm);
	}
	else
		answer += to_string(mm);
	*/

	if ((anstime / 60) < 10)
		answer += '0';
	answer += to_string(anstime / 60);
	answer += ':';
	if ((anstime % 60) < 10)
		answer += '0';
	answer += to_string(anstime % 60);

	return answer;
}

/*
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	vector<int> bus;
	int bustime = 540 - t;

	for (int i = 0; i < n; i++) {
		bustime += t;
		for (int j = 0; j < m; j++)
			bus.push_back(bustime);
	}
	sort(bus.begin(), bus.end());

	sort(timetable.begin(), timetable.end());
	vector<int> crew;
	for (int i = 0; i < timetable.size(); i++) {
		int tmp1 = stoi(timetable[i].substr(0, 2));
		int tmp2 = stoi(timetable[i].substr(3, 2));
		crew.push_back(tmp1 * 60 + tmp2);
	}

	int waitarr[1500] = { 0 };
	for (int i = 0; i < crew.size(); i++)
		waitarr[crew[i]]++;

	int anstime = 0;
	while (!bus.empty()) {
		cout << "now bus: " << bus.back() << endl;
		cout << "crew size: " << crew.size() << " / bus size: " << bus.size() << endl << endl;
		int i = 0;
		for (; i < crew.size(); i++) {
			if (crew[i] <= bus.back()) {
				waitarr[crew[i]]--;
				bus.pop_back();
			}
			else
				continue;
		}
		crew

	}












	cout << "용용 " << endl;

	if (bus.size() > 1) {
		cout << "bus: " << bus.back() << " 만큼남음" << endl << endl;
		anstime = bus.back();
	}
	else {
		cout << "똑같이 남음: " << crew.back() << endl << endl;
		anstime = crew.back() - 1;
	}
	cout << "anstime: " << anstime << endl << endl;




	int hh = anstime / 60;
	int mm = anstime % 60;

	cout << "hh: " << hh << " : " << "mm: " << mm << endl << endl;
	if (hh <= 9) {
		answer += '0';
		if (hh == 0)
			answer += '0';
		else
			answer += to_string(hh);
	}
	else
		answer += to_string(hh);
	answer += ':';
	if (mm <= 9) {
		answer += '0';
		if (mm == 0)
			answer += '0';
		else
			answer += to_string(mm);
	}
	else
		answer += to_string(mm);

	return answer;
}
*/