/**********************************************************
2024-05-03
https://github.com/keastmin
백준/1600/말이 되고픈 원숭이
난이도: 골드3
유형: 그래프 이론, 그래프 탐색, 너비 우선 탐색
**********************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int K, M, N;
vector<vector<int>> map;
vector<vector<vector<bool>>> visited;

int dx[12] = { 0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[12] = { -1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2 };

bool check(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	else if (map[y][x] == 1) return false;
	return true;
}

int bfs() {
	// x, y, dist, jump
	queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, 0, 0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x, y, dist, jump;
		tie(x, y, dist, jump) = q.front();
		q.pop();

		if (x == M - 1 && y == N - 1) return dist;

		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny)) {
				if (!visited[ny][nx][jump] && i < 4) {
					q.push({ nx, ny, dist + 1, jump});
					visited[ny][nx][jump] = true;
				}
				else {
					if (!visited[ny][nx][jump + 1] && jump < K) {
						q.push({nx, ny, dist + 1, jump + 1 });
						visited[ny][nx][jump + 1] = true;
					}
				}
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> K >> M >> N;
	map.resize(N, vector<int>(M));
	visited.resize(N, vector<vector<bool>>(M, vector<bool>(K + 1, false)));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	cout << bfs() << '\n';

	return 0;
}
