#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<int> minTime;
vector<int> minCount;

bool check(int x) {
	if (x < 0 || x >= minTime.size()) return false;
	return true;
}

void bfs() {
	queue<int> q;
	q.push(N);
	minTime[N] = 0;
	minCount[N] = 1;
	
	while (!q.empty()) {
		int curr = q.front();		
		q.pop();
		
		int next[3] = { curr + 1, curr - 1, curr * 2 };
		
		for (const int n : next) {
			if (check(n)) {
				if (minTime[n] == -1) {
					q.push(n);
					minTime[n] = minTime[curr] + 1;;
					minCount[n] = minCount[curr];
				}
				else if (minTime[n] == minTime[curr] + 1) {
					minCount[n] += minCount[curr];
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;

	int m = max(N, K);
	minTime.resize(m * 2, -1);
	minCount.resize(m * 2, 0);

	bfs();

	cout << minTime[K] << '\n' << minCount[K] << '\n';

	return 0;
}
