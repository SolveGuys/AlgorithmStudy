#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int N, M;
int max_V = 0;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

vector<pair<int, int>> v;

int check_virus(int MAP[9][9]) {
	
	int visited[9][9];
	fill(&visited[0][0], &visited[0][0] + 9 * 9, 0);
	int cnt = 0;

	queue<pair<int, int>> q;

	for (pair<int, int> p : v) {
		q.push(p);
		visited[p.first][p.second] = 1;
		while (!q.empty()) {
			int y, x;
			tie(y, x) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (MAP[ny][nx] != 0)continue;
				if (visited[ny][nx]) continue;
				q.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}
	}

	//cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cout << MAP[i][j] << ' ';
			if (!visited[i][j]&&!MAP[i][j])
				cnt++;
		}
		//cout << '\n';
	}

	return cnt;

}

void install_wall(int py, int n, int MAP[9][9]) {
	
	if (n == 3) {
		max_V = max(check_virus(MAP), max_V);
		return;
	}

	int _MAP[9][9];
	copy(&MAP[0][0], &MAP[0][0] + 9 * 9, &_MAP[0][0]);

	for (int i = py; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_MAP[i][j] == 0) {
				_MAP[i][j] = 1;
				install_wall(i, n + 1, _MAP);
				_MAP[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int MAP[9][9];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2)
				v.push_back({ i,j });
		}
	}
	install_wall(0, 0, MAP);

	cout << max_V;
}