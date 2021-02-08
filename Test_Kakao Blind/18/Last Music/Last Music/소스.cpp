#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

struct mylist {
	int idx, plytime, plyperiod;
};

string transmelody(string str) {
	string melody;  // 실제 들었던 

	for (int i = 0; i < str.size(); i++) {
		if (i < str.size() - 1 && str[i + 1] == '#') {
			melody.push_back(tolower(str[i]));
			i++;
		}
		else
			melody.push_back(str[i]);
	}

	return melody;
}

bool cmpr(mylist a, mylist b) {
	if (a.plyperiod == b.plyperiod)
		return a.plytime < b.plytime;
	else
		return a.plyperiod > b.plyperiod;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";

	vector<pair<int,int>> times;
	vector<int> playtimes;
	vector<string> musicnames;
	vector<string> melodies;

	for (int i = 0; i < musicinfos.size(); i++) {
		pair<int, int> time;
		time.first = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
		time.second = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));
		times.push_back(time);

		playtimes.push_back(time.second - time.first);
		musicnames.push_back(musicinfos[i].substr(12, musicinfos[i].find(',', 12) - 12));
		melodies.push_back(transmelody(musicinfos[i].substr(musicinfos[i].find(',', 12) + 1)));
	}

	for (int i = 0; i < musicinfos.size(); i++) {
		printf("times:%5d%5d\n", times[i].first, times[i].second);
		cout << "musicnames: " << musicnames[i] << endl;
		cout << "melodies: " << melodies[i] << endl << endl;
	}

	vector<string> listen;
	for (int i = 0; i < musicinfos.size(); i++) {
		string tmplisten;
		if (playtimes[i] > melodies[i].size()) {
			tmplisten = melodies[i];
			for (int j = melodies[i].size(); j < playtimes[i]; j++) {
				tmplisten += melodies[i][j % melodies[i].size()];
			}
		}
		else {
			tmplisten= melodies[i].substr(0, playtimes[i]);
		}
		listen.push_back(tmplisten);
	}

	cout << "listen 지금 상태가: " << endl;
	for (int i = 0; i < musicinfos.size(); i++) {
		cout << listen[i] << endl;
	}
	cout << endl;


	string tmp = transmelody(m);
	vector<mylist> answers;
	for (int i = 0; i < musicinfos.size(); i++) {
		cout << "plytimes: " << playtimes[i] << " / tmpsize: " << tmp.size() << endl;
		if (playtimes[i] >= tmp.size()) {
			for (int j = 0; j < playtimes[i] - tmp.size() + 1; j++) {
				cout << "     check!!!  i: " << i << "  / j:  " << j << endl;
				if (!tmp.compare(0, tmp.size(), listen[i], j, tmp.size())) {
					cout << "         돼따! " << endl;
					mylist tmplist;
					tmplist.idx = i;
					tmplist.plytime = times[i].first;
					tmplist.plyperiod = playtimes[i];
					answers.push_back(tmplist);
					break;
				}
			}
		}
		/*
		else {
			for (int j = 0; j < tmp.size() - playtimes[i] + 1; j++) {
				cout << "     check!!!  i: " << i << "  / j:  " << j << endl;
				if (!tmp.compare(j, tmp.size(), listen[i], 0, tmp.size())) {
					cout << "         돼따! " << endl;
					mylist tmplist;
					tmplist.idx = i;
					tmplist.plytime = times[i].first;
					tmplist.plyperiod = playtimes[i];
					answers.push_back(tmplist);
					break;
				}
			}
		}
		*/
	}

	cout <<"answers 크기: "<< answers.size() << endl;

	if (!answers.size())
		answer = "(None)";
	else {
		sort(answers.begin(), answers.end(), cmpr);
		answer = musicnames[answers[0].idx];
	}

	return answer;
}

int main() {
	string m = "A#";
	vector<string> musicinfos;

	musicinfos.push_back("13:00,13:02,HELLO,B#A#");
	// musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");

	cout << solution(m, musicinfos) << endl;
}