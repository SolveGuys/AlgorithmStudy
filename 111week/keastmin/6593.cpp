#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int F, R, C;
int sX, sY, sZ;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

bool check(int x, int y, int z, vector<vector<vector<bool>>>& v, vector<vector<vector<char>>>& m) {
	if (x < 0 || x >= C || y < 0 || y >= R || z < 0 || z >= F) return false;
	else if (v[z][y][x]) return false;
	else if (m[z][y][x] == '#') return false;
	return true;
}

int bfs(vector<vector<vector<char>>>& m) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<vector<vector<bool>>> visited(F, vector<vector<bool>>(R, vector<bool>(C, false)));
	q.push({ {sX, sY}, {sZ, 0} });
	visited[sZ][sY][sX] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		int t = q.front().second.second;
		q.pop();

		if (m[z][y][x] == 'E') {
			return t;
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (check(nx, ny, nz, visited, m)) {
				q.push({ {nx, ny},{nz, t + 1} });
				visited[nz][ny][nx] = true;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	while (true) {
		cin >> F >> R >> C;
		if (F == 0 && R == 0 && C == 0) break;

		vector<vector<vector<char>>> map(F, vector<vector<char>>(R, vector<char>(C)));

		for (int i = 0; i < F; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> map[i][j][k];

					if (map[i][j][k] == 'S') {
						sX = k;
						sY = j;
						sZ = i;
					}
				}
			}
		}

		int res = bfs(map);
		if (res == -1) {
			cout << "Trapped!" << '\n';
		}
		else {
			cout << "Escaped in " << res << " minute(s)." << '\n';
		}
	}

	return 0;
}
