/**********************************************************
2024-04-16
https://github.com/keastmin
백준/2234/성곽
난이도: 골드3
유형: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 비트마스킹
**********************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<vector<bool>>> wall; // [0]: 서, [1]: 북, [2]: 동, [3]: 남

// [0]: 서, [1]: 북, [2]: 동, [3]: 남
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int roomCount = 0;
int roomScale = 0;
int roomMaxScale = 0;

string translate(int num) {
	string res = "";

	while (num > 0) {
		if (num % 2) res += "1";
		else res += "0";
		num /= 2;
	}

	while (res.size() < 4) {
		res += "0";
	}

	return res;
}

void bfs(int x, int y, int w) {
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[y][x] = true;

	int s = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		s++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!wall[y][x][i] && !visited[ny][nx]) {
					q.push({ nx, ny});
					visited[ny][nx] = true;
				}
			}
		}
	}

	// 0: 벽을 부수지 않았을 때, 1: 벽을 부쉈을 때
	if (w == 0) roomScale = max(roomScale, s);
	if (w == 1) roomMaxScale = max(roomMaxScale, s);

	//cout << roomCount << ' ' << roomScale << ' ' << roomMaxScale << '\n';
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map.resize(M, vector<int>(N));
	visited.resize(M, vector<bool>(N, false));
	wall.resize(M, vector<vector<bool>>(N, vector<bool>(4, false)));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			// 해당 칸에서 벽이 있는 위치 구분
			int num = map[i][j];
			string res = translate(num);
			for (int k = 0; k < res.size(); k++) {
				if (res[k] == '1') {
					wall[i][j][k] = true;
				}
			}
		}
	}

	// 벽을 부수지 않은 일반적인 상태 카운트
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				roomCount++;
				bfs(j, i, 0);
			}
		}
	}

	// 벽이 존재하는 칸에 대해 벽이 있는 방향의 벽을 부순 후 bfs 진행, 그리고 다시 벽 생성
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				if (wall[i][j][k]) {
					visited.assign(M, vector<bool>(N, false));
					wall[i][j][k] = false;
					bfs(j, i, 1);
					wall[i][j][k] = true;
				}
			}
		}
	}

	cout << roomCount << '\n' << roomScale << '\n' << roomMaxScale;

	return 0;
}
