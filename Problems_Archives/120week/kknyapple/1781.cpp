#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <memory.h>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
int n, d, p, ret;
vector <pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> d >> p;
		v.push_back({ d,p });
	}

	priority_queue <int, vector<int>, greater<int>> pq;

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (v[i].first < pq.size()) pq.pop();
	}

	while (pq.size()) {
		ret += pq.top();
		// cout << pq.top() << " ";
		pq.pop();
	}

	cout << ret << "\n";

	return 0;
}
