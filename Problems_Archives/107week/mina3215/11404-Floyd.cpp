#include<iostream>
#include<algorithm>

using namespace std;

int cost[102][102];
long long dist[102][102];
int N, M;

int main() {

	fill(&cost[0][0], &cost[0][0] + 102 * 102, 2e9);
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		//a에서 b까지 가는 비용 c를 넣음
		cost[a][b] = min(c,cost[a][b]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = cost[i][j];
			if (i == j) dist[i][j] = 0;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] >= 2e9) dist[i][j] = 0;
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}


	
	return 0;
}