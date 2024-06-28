#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<vector<char>> map;
vector<vector<int>> fireTime;
vector<pair<int, int>> fireStart;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void MoveFire() {
	queue<pair<int, int>> q;

	for (const auto fs : fireStart) {
		q.push({ fs.first, fs.second});
		fireTime[fs.second][fs.first] = 0;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
				if (map[ny][nx] != '#' && fireTime[ny][nx] == -1) {
					q.push({ nx, ny});
					fireTime[ny][nx] = fireTime[y][x] + 1;
				}
			}
		}
	}
}

int bfs(int sx, int sy) {
	queue<tuple<int, int, int>> q;
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	q.push({ sx, sy, 0 });
	visited[sy][sx] = true;

	while (!q.empty()) {
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R) {
				return t + 1;
			}

			if (map[ny][nx] == '.' && !visited[ny][nx]) {
				if (fireTime[ny][nx] == -1 || fireTime[ny][nx] > t + 1) {
					q.push({ nx, ny, t + 1 });
					visited[ny][nx] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	map.resize(R, vector<char>(C));
	fireTime.resize(R, vector<int>(C, -1));

	int sx = 0, sy = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				sx = j;
				sy = i;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'F') {
				fireStart.push_back({ j, i });
			}
		}
	}

	MoveFire();
	int res = bfs(sx, sy);

	if (res == -1) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else {
		cout << res << '\n';
	}

	return 0;
}
