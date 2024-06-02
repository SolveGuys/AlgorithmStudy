#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> swapMap;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int lT = 0;
int lC = 0;

bool check(int x, int y, vector<vector<bool>>& v) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;
	else if (v[y][x]) return false;
	return true;
}

int bfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[y][x] == 1) {
			cnt++;
			swapMap[y][x] = 0;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny, visited)) {
				q.push({ nx, ny });
				visited[ny][nx] = true;
			}
		}
	}

	map = swapMap;

	//cout << '\n';
	//for (const auto ma : map) {
	//	for (const auto m : ma) {
	//		cout << m << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map.resize(N, vector<int>(M));
	swapMap.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			swapMap[i][j] = map[i][j];
		}
	}

	while (true) {
		int res = bfs();
		if (res == 0) break;
		lT++;
		lC = res;
	}

	cout << lT << '\n' << lC << '\n';

	return 0;
}
