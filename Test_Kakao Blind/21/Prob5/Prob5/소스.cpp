#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

enum { A_start, B_finish };

struct timelabel {
	int time, label;
};

bool cmpr(timelabel a, timelabel b) {
	if (a.time == b.time)
		return a.label < b.label;
	else
		return a.time < b.time;
}

bool compareanswer(pair<int,int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

int timetrans(string a) {
	int total = 0;

	total += stoi(a.substr(0, 2)) * 3600;
	total += stoi(a.substr(3, 2)) * 60;
	total += stoi(a.substr(6, 2));

	return total;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";

	int playtime, adtime;
	vector<timelabel> logvec;

	playtime = timetrans(play_time);
	adtime = timetrans(adv_time);
	for (int i = 0; i < logs.size(); i++) {
		logvec.push_back({ timetrans(logs[i].substr(0, 8)),A_start });
		logvec.push_back({ timetrans(logs[i].substr(9, 8)),B_finish });
	}

	sort(logvec.begin(), logvec.end(), cmpr);

	vector<pair<int,int>> answertimes;

	int maxidx = 0;
	for (int i = 0; i < logvec.size(); i++) {
		if (logvec[i].time >= playtime - adtime) {
			maxidx = i;
			break;
		}
	}

	for (int i = 0; i <= maxidx; i++) {
		int tmptotal = 0;
		if (logvec[i].label == A_start) {
			int adstr = logvec[i].time;
			int adend = adstr + adtime;
			if (adend > playtime) {
				answertimes.push_back(make_pair(tmptotal, 0));
				break;
			}
			else {
				vector<int> laststrtimes;
				for (int j = i; j < logvec.size() && logvec[j].time <= adend; j++) {
					if (logvec[j].label == A_start) {
						laststrtimes.push_back(logvec[j].time);
					}
					else if (logvec[j].label == B_finish && laststrtimes.size() == 0) {
						tmptotal += logvec[j].time - adstr;
					}
					else {
						tmptotal += logvec[j].time - laststrtimes.back();
						laststrtimes.pop_back();
					}

				}
				while (laststrtimes.size() != 0) {
					tmptotal += adend - laststrtimes.back();
					laststrtimes.pop_back();
				}
				answertimes.push_back(make_pair(tmptotal, adstr));
			}
		}
	}

	sort(answertimes.begin(), answertimes.end(), compareanswer);

	int lastanswer = answertimes[0].second; //answertime.front().second;

	if ((lastanswer / 3600) < 10)
		answer += '0';
	answer += to_string(lastanswer / 3600);
	answer += ':';
	if (((lastanswer / 60) % 60) < 10)
		answer += '0';
	answer += to_string((lastanswer / 60) % 60);
	answer += ':';
	if ((lastanswer % 60) < 10)
		answer += '0';
	answer += to_string(lastanswer % 60);

	return answer;
}

int main() {
	vector<string> logs;

	string play_time = "99:59:59";
	string adv_time = "25:00:00";

	logs.push_back("69:59:59-89:59:59");
	logs.push_back("01:00:00-21:00:00");
	logs.push_back("79:59:59-99:59:59");
	logs.push_back("11:00:00-31:00:00");

	/*
	string play_time = "02:03:55";
	string adv_time = "00:14:15";
	
	logs.push_back("01:20:15-01:45:14");
	logs.push_back("00:40:31-01:00:00");
	logs.push_back("00:25:50-00:48:29");
	logs.push_back("01:30:59-01:53:29");
	logs.push_back("01:37:44-02:02:30");
	*/

	/*
	string play_time = "50:00:00";
	string adv_time = "50:00:00";

	logs.push_back("15:36:51-38:21:49");
	logs.push_back("10:14:18-15:36:51");
	logs.push_back("38:21:49-42:51:45");
	*/


	cout << "Á¤´äÀº: " << solution(play_time, adv_time, logs) << endl;
}