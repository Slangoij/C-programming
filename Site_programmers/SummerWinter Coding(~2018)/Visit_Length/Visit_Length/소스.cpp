#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cordi {
	int x, y;
};

struct road {
	cordi a, b;
};

bool issamecordi(cordi a, cordi b) {
	if (a.x == b.x&&a.y == b.y)
		return true;
	else
		return false;
}

bool issameroad(road roada, road roadb) {
	if (issamecordi(roada.a, roadb.a) && issamecordi(roada.b, roadb.b)
		|| issamecordi(roada.a, roadb.b) && issamecordi(roada.b, roadb.a))
		return true;
	else
		return false;
}

cordi move(cordi a, char dir) {
	cordi b;
	switch (dir) {
	case 'L':
		b = { a.x - 1,a.y };
		break;
	case 'R':
		b = { a.x + 1,a.y };
		break;
	case 'U':
		b = { a.x,a.y + 1 };
		break;
	case 'D':
		b = { a.x,a.y - 1 };
		break;
	default:
		break;
	}

	return b;
}

int solution(string dirs) {
	int answer = 0;
	vector<road> hroads, vroads;
	cordi charac = { 0,0 };
	for (int i = 0; i < dirs.size(); i++) {
		cordi newcharac = move(charac, dirs[i]);
		if (newcharac.x >= -5 && newcharac.x <= 5 && newcharac.y >= -5 && newcharac.y <= 5) {
			road newroad = { charac,newcharac };
			if (dirs[i] == 'R' || dirs[i] == 'L') {
				if (hroads.empty()) {
					hroads.push_back(newroad);
					answer++;
				}
				else {
					int j = 0;
					for (; j < hroads.size()&& !issameroad(hroads[j], newroad); j++) {
					}
					if (j==hroads.size()) {
						hroads.push_back(newroad);
						answer++;
					}
				}
			}
			else {
				if (vroads.empty()) {
					vroads.push_back(newroad);
					answer++;
				}
				else {
					int j = 0;
					for (; j < vroads.size() && !issameroad(vroads[j], newroad); j++) {
					}
					if (j == vroads.size()) {
						vroads.push_back(newroad);
						answer++;
					}
				}
			}
			charac = newcharac;
		}
	}

	return answer;
}

/*
int solution(string dirs) {
	vector<road> roads;
	for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			roads.push_back({ {i,j},{i + 1,j},false });
			roads.push_back({ {i,j},{i,j + 1},false });
		}
		roads.push_back({ {i,5},{i + 1,5},false });
	}
	for (int i = -5; i < 5; i++) {
		roads.push_back({ {5,i},{5,i + 1},false });
	}
	if(newcharac.x==charac.x){
		minset={charac.x,min(newcharac.y,charac.y)};
		maxset={charac.x,max(newcharac.y,charac.y)};
	}
	else{
		minset={min(newcharac.x,charac.x),charac.y};
		maxset={max(newcharac.x,charac.x),charac.y};
	}
	for (int j = 0; j < roads.size(); j++) {
		if (issameroad(roads[j], { charac,newcharac }) && issameroad(roads[j], { charac,newcharac })) {
			if (roads[j].passed == false) {
				roads[j].passed = true;
				answer++;
			}
			break;
		}
	}
}
*/	

int main() {
	cout << solution("ULURRDLLU") << endl;
}