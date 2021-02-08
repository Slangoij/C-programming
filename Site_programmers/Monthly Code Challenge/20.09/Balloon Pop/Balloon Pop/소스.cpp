#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
int solution(vector<int> a) {
	int answer = 1;

	int amin = *min_element(a.begin(), a.end());
	int minidx = find(a.begin(), a.end(), amin) - a.begin();
	int front = a.front();
	int back = a.back();

	int i = 1;
	if (minidx != 0) {
		while (i < minidx) {
			if (a[i - 1] > a[i] && a[i] < front)
				answer++;
			i++;
		}
		answer++;
	}
	if (i < a.size() - 1) {
		int j = a.size() - 2;
		answer++;
		while (j > minidx) {
			if (a[j] < a[j + 1] && a[j] < back)
				answer++;
			j--;
		}
	}

	return answer;
}
*/

/*
vector<int> popbigone(int left,int right, vector<int> a) {
	if (a[left] < a[right])
		a.erase(a.begin() + right);
	else
		a.erase(a.begin() + left);

	return a;
}
vector<int> popsmlone(int left, int right, vector<int> a) {
	if (a[left] > a[right])
		a.erase(a.begin() + right);
	else
		a.erase(a.begin() + left);

	return a;
}
int solution(vector<int> a) {
	int answer = 1;

	vector<int> ans{ *min_element(a.begin(), a.end()) };

	int left, right;
	vector<int> tmpa;
	for (int i = 0; i < a.size() - 1; i++) {
		for (int j = 0; j < a.size() - 1; j++) {
			tmpa = a;
			left= i, right = i + 1;
			for (int k = 0; k < a.size() - 1; k++) {
				if (k == j)
					tmpa = popsmlone(left, right, tmpa);
				else
					tmpa = popbigone(left, right, tmpa);

				if (right >= tmpa.size() && right > 1)
					left--, right--;
				
				//for (int m = 0; m < tmpa.size(); m++)
				//	cout << tmpa[m] << " ";
				//printf("   ");
				
			}
			if (find(ans.begin(), ans.end(), tmpa.front()) == ans.end()) {
				ans.push_back(tmpa.front());
				answer++;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << "ans" << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
		if (i % 10 == 0 && i > 9)
			cout << endl;
	}
	cout << endl;

	return answer;
}
*/

int solution(vector<int> a) {
	int answer = 0;
	int len = a.size();
	vector<int> left(len);
	vector<int> right(len);

	int min = a.front();
	for (int i = 0; i < len; i++) {
		if (a[i] < min)
			min = a[i];
		left[i] = min;
	}

	min = a.back();
	for (int i = len - 1; i >= 0; i--) {
		if (a[i] < min)
			min = a[i];
		right[i] = min;
	}

	for (int i = 0; i < len; i++) {
		if (a[i] <= left[i] || a[i] <= right[i])
			answer++;
	}

	return answer;
}

/*
int dwnwrd(int answer, int str, int end, vector<int> a) {
	int nowval = a[str], i = str + 1;
	while (i < end) {
		if (a.front() < a[i] && a[i] < a.back()) {
			nowval = a[i];
			if (nowval < a[i]&&)
				while (a[i - 1]<a[i] && a[i]>a[i + 1] && i < a.size() - 2) {
					answer--;
					a.erase(a.begin() + i);
				}
			i++;
		}
		else
			a.erase(a.begin() + i);
	}

	return answer;
}
int upwrd(int answer, int str, int end, vector<int> a) {
	int nowval = a[str], i = str + 1;
	while (i < end) {
		if (a.front() > a[i] && a[i] > a.back()) {
			nowval = a[i];
			if ((a[i - 1]<a[i] && a[i]>a[i + 1]))
				while (a[i - 1]<a[i] && a[i]>a[i + 1] && i < a.size() - 2) {
					answer--;
					a.erase(a.begin() + i);
				}
			i++;
		}
		else
			a.erase(a.begin() + i);
	}

	return answer;
}
int solution(vector<int> a) {
	int answer = a.size();

	int amin = *min_element(a.begin(), a.end());
	int minidx = find(a.begin(), a.end(), amin) - a.begin();

	if (amin == a.front()) {
		answer = dwnwrd(answer, 0, a.size() - 1, a);
	}
	else if (amin == a.back()) {
		answer = upwrd(answer, 0, a.size() - 1, a);
	}
	else{
		answer = dwnwrd(answer, 0, a.size() - 1, a);
		a.erase(find(a.begin(), a.end(), amin) - 1);
		answer = upwrd(answer, 0, a.size() - 1, a);
	}

	cout << "ans: " << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	return answer;
}
*/


int main() {
	vector<int> a{ 9,4,7,1,3,2,6,5,8 };

	cout << "´äÀº: "<<solution(a) << endl;
}