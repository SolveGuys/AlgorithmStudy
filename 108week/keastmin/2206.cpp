#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
vector<string> map;
vector<vector<vector<bool>>> visited;

bool check(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	return true;
}

int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, 1, 0});
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x, y, dist, wall;
		tie(x, y, dist, wall) = q.front();
		q.pop();
		
		if (x == M - 1 && y == N - 1) return dist;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny)) {
				if (map[ny][nx] == '1' && wall == 0) {
					visited[ny][nx][1] = true;
					q.push({ nx, ny, dist + 1, 1 });
				}
				else if (map[ny][nx] == '0' && !visited[ny][nx][wall]) {
					visited[ny][nx][wall] = true;
					q.push({ nx,ny,dist + 1, wall });
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
	map.resize(N);
	visited.resize(N, vector<vector<bool>>(M, vector<bool>(2, false)));
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	cout << bfs() << '\n';

	return 0;
}
