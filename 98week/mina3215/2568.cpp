#include<bits/stdc++.h>

using namespace std;

int N;
int region[104][104];
int visited[104][104];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int DFS(int y, int x, int h) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (region[ny][nx] > h && !visited[ny][nx]) DFS(ny, nx, h);
	}
	return 0;

}
int main() {
	cin >> N;
	fill(&region[0][0], &region[0][0] + 104 * 104, 0);
	int max_v = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> region[i][j];
		}
	}

	for (int h = 0; h <= 100; h++) {
		int ans = 0;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (region[i][j] > h && !visited[i][j]) {
					DFS(i, j, h);
					++ans;
				}
			}
		}
		max_v = max(max_v, ans);
	}
	cout << max_v;


}