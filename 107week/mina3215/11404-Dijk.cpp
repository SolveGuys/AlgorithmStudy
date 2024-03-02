#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N,M;

long long cost[102][102];
typedef pair<int, int> pii;

void Dijkstra(int n, vector<vector<pair<int,pii>>> &b_stop) {
	long long  visited[102];
	priority_queue<pair<int,int>> pq;

	fill(visited, visited + 102, 2e9);


	visited[n] = 0;
	int start = n;

	pq.push({ 0, n });

	while (!pq.empty()) {
		int v = -pq.top().first;
		int b = pq.top().second;
		pq.pop();

		if (visited[b] < v) continue;
		
		visited[b] = v;

		for (int i = 0; i < b_stop[b].size(); i++) {
			
			int l = b_stop[b][i].second.second;
			int c = -visited[start]+b_stop[b][i].first;
			
			if (visited[l] < -c) continue;
			
			pq.push({ c, l });
		}
	}

	for (int i = 1; i <= N; i++) {
		cost[n][i] = visited[i]-1;
		if (cost[n][i] < 0) cost[n][i] = 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> M;

	vector<vector<pair<int, pii>>> b_stop(N+1);
	
	for (int j = 0; j < M; j++) {
		int a, b, c;
		cin >> a >> b >> c;
		b_stop[a].push_back({ -c,{a, b} });
	}

	for (int i = 1; i <= N; i++) {
		Dijkstra(i,b_stop);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout <<cost[i][j]<<' ';
		}
		cout << '\n';
	}

}