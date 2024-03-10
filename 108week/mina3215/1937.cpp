#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, max_v = 0;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int forest[501][501];
int DP[501][501];
	

int DFS(int y, int x) {

	if (DP[y][x]>=0) {
		return DP[y][x];
	}
	
	DP[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (forest[ny][nx] <= forest[y][x]) continue;

		DP[y][x] = max(DP[y][x], DFS(ny, nx) + 1);
	}

	return DP[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> forest[i][j];
		}
	}
	fill(&DP[0][0], &DP[0][0] + 501 * 501, -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			DFS(i, j);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, DP[i][j]);
			//cout << DP[i][j];
		}
	}
	cout << ans;

	return 0;
}