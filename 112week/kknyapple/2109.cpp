#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<memory.h>
#include<stack>
using namespace std;

int n, p, d, day[10004], res;
vector<pair<int, int>> v;

bool cmp(pair<int, int> &a, pair<int, int>& b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back({ p,d });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto lecture : v) {
		for (int i = lecture.second; i >= 1; i--) {
			if (day[i] == 0) {
				day[i] = 1;
				res += lecture.first;
				break;
			}
		}
	}

	cout << res << "\n";

	return 0;
}
