#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool check(int x, int y, int N, int M) {
	if (x < 0 || x >= M || y < 0 || y >= N) return false;

	return true;
}

int bfs(vector<vector<int>>& t, int N, int M, vector<vector<int>>& virus) {
	queue<pair<int, int>> q;
	for (const auto v : virus) {
		q.push({ v[0], v[1] });
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny, N, M)) {
				if (t[ny][nx] == 0) {
					t[ny][nx] = 2;
					q.push({ nx, ny });
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (t[i][j] == 0) {
				count++;
			}
		}
	}

	return count;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	vector<vector<int>> virus;
	int max = 0;

	for(int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				virus.push_back({ j, i });
			}
		}
	}

	for (int i = 0; i < N * M - 2; ++i) {
		vector<vector<int>> t = map;
		if (t[i / M][i % M] != 0)
			continue;
		for (int j = i + 1; j < N * M - 1; ++j) {
			if (t[j / M][j % M] != 0)
				continue;
			for (int k = j + 1; k < N * M; ++k) {
				if (t[k / M][k % M] != 0)
					continue;
				
				t[i / M][i % M] = 1;
				t[j / M][j % M] = 1;
				t[k / M][k % M] = 1;
				
				int calc = bfs(t, N, M, virus);
				if (max < calc) max = calc;
				
				t = map;
			}
		}
	}

	cout << max << '\n';

	return 0;
}
