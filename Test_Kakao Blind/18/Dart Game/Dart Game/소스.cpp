#include <string>
#include <iostream>
#include <vector>

using namespace std;

int SDT(string parsed, int length) {
	int roundpoint;
	int tmppoint = 0;
	string tmpstr;

	tmpstr.push_back(parsed[0]);
	if (length == 2)
		tmpstr.push_back(parsed[1]);

	if (parsed[length] == 'S')
		roundpoint = stoi(tmpstr);
	else if (parsed[length] == 'D')
		roundpoint = pow(stoi(tmpstr), 2);
	else if (parsed[length] == 'T')
		roundpoint = pow(stoi(tmpstr), 3);

	return roundpoint;
}

int solution(string dartResult) {
	int answer = 0;

	vector<pair<int, int>> paridx;
	for (int i = 0; i < dartResult.size() - 1; i++) {
		pair<int, int> forparse;
		forparse.second = 1;
		if (dartResult[i] >= '0'&&dartResult[i] <= '9') {
			forparse.first = i;
			if (i < dartResult.size() - 1 && dartResult[i + 1] >= '0'&&dartResult[i + 1] <= '9') {
				forparse.second = 2;
				i++;
			}
			paridx.push_back(forparse);
		}
	}

	vector<int> roundpoint;
	for (int i = 0; i < paridx.size(); i++) {
		roundpoint.push_back(SDT(dartResult.substr(paridx[i].first, paridx[i].second + 1),
			paridx[i].second));
		cout << "paridx : " << paridx[i].first << " / " << paridx[i].second << endl;
		cout << "라운드 기본점수는요~: " << dartResult.substr(paridx[i].first, paridx[i].second) << endl;
		cout << "roundpoint: " << roundpoint[i] << endl << endl;
	}

	for (int i = 0; i < paridx.size(); i++) {
		int j;
		if (i == 2)
			j = dartResult.size() - 1;
		else
			j = paridx[i + 1].first - 1;
		if (dartResult[j] == '#') {
			roundpoint[i] = -roundpoint[i];
		}
		else if (dartResult[j] == '*') {
			roundpoint[i] *= 2;
			if (i != 0)
				roundpoint[i - 1] *= 2;
		}
	}

	for (int i = 0; i < paridx.size(); i++) {
		answer += roundpoint[i];
		cout << "최종 roundpoint: " << roundpoint[i] << endl << endl;
	}

	return answer;
}

int main() {
	string dartResult = "1S2D*3T";

	cout << solution(dartResult) << endl;
}