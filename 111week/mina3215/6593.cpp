#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

int dz[] = { 0,0,0,0,-1,1 };
int dy[] = { 1,-1,0,0,0,0 };
int dx[] = { 0,0,1,-1,0,0 };

char MAP[31][31][31];
int visited[31][31][31];
int L, R, C;
tuple<int, int, int> start;

void input_value() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> MAP[i][j][k];
				if (MAP[i][j][k] == 'S') {
					start = { i,j,k };
					visited[i][j][k] = 1;
				}
			}
		}
	}
}

int find_ans() {
	queue<tuple<int, int, int>> q;
	q.push(start);
	while (!q.empty()) {
		int z, y, x;
		tie(z, y, x) = q.front();
		q.pop();
		for (int i = 0; i < 6;i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (MAP[nz][ny][nx]=='#'||visited[nz][ny][nx]) continue;
			q.push({ nz, ny, nx });
			visited[nz][ny][nx] = visited[z][y][x] + 1;
			if (MAP[nz][ny][nx] == 'E')
				return visited[nz][ny][nx];
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		fill(&MAP[0][0][0], &MAP[0][0][0] + 31 * 31 * 31, 0);
		fill(&visited[0][0][0], &visited[0][0][0] + 31 * 31 * 31, 0);
		cin >> L >> R >> C;
		if (L == 0) break;
		input_value();
		int min = find_ans();
		
		if (min)
			cout << "Escaped in " << min-1 << " minute(s)." << '\n';
		else
			cout << "Trapped!"<<'\n';

	}
}