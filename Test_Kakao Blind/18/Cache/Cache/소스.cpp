#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities);

int main() {
	int cacheSize = 3;
	vector<string> cities;
	for (int i = 0; i < 3; i++) {
		cities.push_back("Jeju");
		cities.push_back("Pangyo");
		cities.push_back("Seoul");
		// cities.push_back("NewYork");
		// cities.push_back("LA");
	}

	cout << solution(cacheSize, cities) << endl;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> newcities;
	for (int i = 0; i < cities.size(); i++) {
		string newcity;
		for (int j = 0; j < cities[i].size(); j++)
			newcity.push_back(toupper(cities[i][j]));
		newcities.push_back(newcity);
	}

	if (cacheSize == 0)
		answer = newcities.size() * 5;
	else {
		for (int i = 0; i < newcities.size(); i++)
			cout << newcities[i] << endl;
		cout << endl << endl;

		list<string> cache;
		cache.push_front(newcities[0]);
		answer = 5;
		cout << 0 << " for " << newcities[0] << "    answer now: " << answer << endl;
		for (int i = 1; i < newcities.size(); i++) {
			for (list<string>::iterator it = cache.begin(); it != cache.end(); it++) {
				if (newcities[i] == *it) {
					cache.erase(it);
					answer -= 4;
					break;
				}
			}
			if (cache.size() >= cacheSize) {
				cache.pop_back();
			}
			cache.push_front(newcities[i]);
			answer += 5;
			cout << i << " for " << newcities[i] << "    answer now: " << answer << endl;
		}
	}

	return answer;
}