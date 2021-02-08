#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum { A_start, B_finish };

struct timelabel {
	int time, label;
};

int solution(vector<string> lines);
int fintime(string date);
int protime(string date);
bool compr(timelabel &a, timelabel &b);

int main() {
	vector<string> lines;
	lines.push_back("2016-09-15 01:00:04.002 2.0s");
	lines.push_back("2016-09-15 01:00:07.000 2s");

	cout << "������" << solution(lines);
}

int fintime(string date) {
	int h = stoi(date.substr(11, 2));
	int m = stoi(date.substr(14, 2));
	float s = stof(date.substr(17, 6)) * 1000;

	return (((h * 60) + m) * 60) * 1000 + s;
}

int protime(string date) {
	date.erase(date.find("s"));
	int ss = (int)(stof(date.substr(24)) * 1000);

	return ss;
}

bool compr(timelabel &a, timelabel &b) {
	if (a.time == b.time)
		return a.label < b.label;
	else
		return a.time < b.time;
}


int solution(vector<string> lines) {
	int answer = 0;
	int onwork = 0;
	vector<timelabel> onpro;

	for (int i = 0; i < lines.size(); i++) {
		int tmptime = fintime(lines[i]);
		cout << "lines[i]: " << lines[i] << " tmptime: " << tmptime << "  protime: " << protime(lines[i]) << endl;
		onpro.push_back({ tmptime - protime(lines[i]) + 1, A_start });
		onpro.push_back({ tmptime + 999, B_finish });
	}

	sort(onpro.begin(), onpro.end(), compr); // ����ð� ���� ����

	for (int i = 0; i < onpro.size(); i++) {
		cout << onpro[i].time << "  " << onpro[i].label << endl;
	}


	for (int i = 0; i < onpro.size(); i++) {
		if (onpro[i].label == A_start) {
			onwork++;
			answer = max(answer, onwork);
		}
		else
			onwork--;
	}

	return answer;
}

/*
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.second < b.second;
}

int solution(vector<string> lines) {
	int answer = 0;
	int onpro = 0;
	vector<int> onproidx;
	vector<int> idxtodel;
	vector < pair<int, int>> linesnum;
	vector<int> checktime;
	pair<int, int> tempair;

	for (size_t i = 0; i < lines.size(); i++) {
		tempair.second = fintime(lines[i]);
		tempair.first = tempair.second - protime(lines[i]);

		linesnum.push_back(tempair);
	}

	sort(linesnum.begin(), linesnum.end()); //���۽ð� ���� ����
	int firtime = linesnum.front().first; //���� ���۽ð� ����

	��ü �ð� 0���� ����
	for (size_t i = 0; i < linesnum.size(); i++) {
	   linesnum[i].second -= firtime;
	   linesnum[i].first -= firtime;
	}

	sort(linesnum.begin(), linesnum.end(), cmp); //����ð� ���� ����
	int lasttime = linesnum.back().second;  //���� ����ð� ����

	sort(linesnum.begin(), linesnum.end());  // �ٽ� ���۽ð� ���� ����

	for (size_t i = 0; i < linesnum.size(); i++) //��� �߰� ���� ���
		cout << linesnum[i].first << "  " << linesnum[i].second << endl;

	cout << endl << "���ʽ���:" << firtime << "  " << "��������:" << lasttime << endl << endl;

	onproidx.push_back(0);
	for (int i = firtime; i <= lasttime; i++) {    // i: ���μ����ϴ� ���� �ð�
		cout << "�������" << i << endl;
		for (int j = 0; j < linesnum.size(); j++) {  // ���� ���μ��� ��������
			if (linesnum[j].second <= i + 1 || linesnum[j].first >= i) {
				cout << "��������" << i << endl;
				cout << "j���" << j << endl;
				onpro++;
				onproidx.push_back(j);
				if (onpro > answer)
					answer = onpro;
			}
			else
				break;
		}

		for (int k = 0; k < onproidx.size(); k++) {  // �����μ��̿��� ������ ���μ��� ����
			if (linesnum[onproidx[k]].first < i || linesnum[onproidx[k]].second > i + 1) {
				onpro--;
				idxtodel.push_back(k);
			}
		}
		for (int l = idxtodel.size(); l == 0; l--) // ���� ���μ��� ��������
			onproidx.erase(onproidx.begin() + idxtodel[l]);

		cout << "�Ϳ쿩��" << i << endl;
		idxtodel.clear();
	}

	return answer;
}
*/
