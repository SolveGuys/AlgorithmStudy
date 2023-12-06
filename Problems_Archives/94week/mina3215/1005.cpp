#include<bits/stdc++.h>

using namespace std;

int T;
int node[1001][1001];
int DP[1001];
int times[1001];
int start = 0;

void BFS(int N) {
	queue<int> q;
	q.push(start);
	DP[start] = times[start];
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (node[start][i]) {
				if (DP[start] + times[i] > DP[i]) {
					q.push(i);
					DP[i] = DP[start] + times[i];
				}
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		fill(&node[0][0], &node[0][0] + 1001 * 1001, 0);
		fill(DP, DP + 1001, 0);
		fill(times, times + 1001, 0);
		int N, K;
		cin >> N >> K; // 건물 개수, 건설 순서 규칙의 총 개수
		for (int i = 1; i <= N; i++) {
			cin >> times[i];
		}
		int now, next;
		for (int i = 0; i < K; i++) {
			cin >> now >> next;
			if (!start) start = now;
			node[now][next] = 1;
		}

		int W;
		cin >> W;
		
		BFS(N);

		cout << DP[W] <<'\n';
	}

}