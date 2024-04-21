#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

vector<vector<int>> MAP(1001, vector<int>(1001));
int N, M;
int Hx, Hy, Ex, Ey;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };



int BFS() {
	vector<vector<int>> visited0(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> visited1(N + 1, vector<int>(M + 1, 0));

	queue<tuple<int, int, int>> q;
	q.push({ Hy,Hx,0 });

	while (!q.empty()) {
		int y, x, v;
		tie(y, x, v) = q.front();
		q.pop();
		if (y == Ey && x == Ex) return v ? visited1[y][x] : visited0[y][x];

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > N || nx > M) continue;
			// 벽이다.
			if (MAP[ny][nx]) {
				// 벽을 부술 수 있고, 벽을 부수고 이 위치에 도착한 적 없음.
				// 이번에 벽을 부수겠다.
				if (!v && !visited1[ny][nx]) {
					visited1[ny][nx] = visited0[y][x] + 1;
					q.push({ ny,nx,1 });
				}
			}
			else {
				// 벽은 아니다. 
				// 이미 벽을 부쉈다. 
				if (v) {
					if (visited1[ny][nx]) continue;
					visited1[ny][nx] = visited1[y][x] + 1;
				}
				else {
					if (visited0[ny][nx]) continue;
					visited0[ny][nx] = visited0[y][x] + 1;
				}
				q.push({ ny,nx,v });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> Hy >> Hx;
	cin >> Ey >> Ex;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}

	cout<< BFS();

}