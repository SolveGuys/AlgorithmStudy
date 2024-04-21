/**********************************************************
2024-04-18
https://github.com/keastmin
백준/14923/미로 탈출
난이도: 골드4
유형: 그래프 이론, 그래프 탐색, 너비 우선 탐색
**********************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M, sX, sY, eX, eY;
vector<vector<int>> map;
vector<vector<vector<bool>>> visited;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

bool check(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	return true;
}

int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({sX, sY, 0, 0});
	visited[sY][sX][0] = true;

	while (!q.empty()) {
		int x, y, d, w;
		tie(x, y, d, w) = q.front();
		q.pop();

		if (x == eX && y == eY) return d;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny)) {
				if (w == 0 && map[ny][nx] == 1) {
					q.push({ nx, ny, d + 1, 1 });
					visited[ny][nx][1] = true;
				}
				else if (map[ny][nx] == 0 && !visited[ny][nx][w]) {
					q.push({ nx, ny, d + 1, w });
					visited[ny][nx][w] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> sY >> sX;
	cin >> eY >> eX;
	map.resize(N, vector<int>(M));
	visited.resize(N, vector<vector<bool>>(M, vector<bool>(2, false)));
	sX--; sY--; eX--; eY--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int res = bfs();
	cout << res << '\n';

	return 0;
}
