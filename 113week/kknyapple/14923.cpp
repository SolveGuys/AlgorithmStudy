#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>
#include <queue>
#include <string>
#include<math.h>
using namespace std;

struct pos {
	int y, x, k; // k : 벽 부수기 여부
};
int n, m, hx, hy, ex, ey;
int a[1004][1004];
int visited[1004][1004][2];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

int bfs(int y, int x) {
	visited[y][x][1] = 1;
	queue<pos> q;
	q.push({ y,x,1 });

	while (!q.empty()) {
			pos cur = q.front();
			q.pop();

			if (cur.y == ey && cur.x == ex) { // 목적지 도착했을 때
				return visited[cur.y][cur.x][cur.k] - 1;
			}

			for (int i = 0; i < 4; i++) {
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue; // 범위 벗어나는 경우

				// 벽이 있더라도 이전에 벽을 부순적이 없다면, 벽을 부수고 최단거리 계산
				// 벽이 있고 방문하지 않았던 곳이라면
				if (a[ny][nx] && cur.k) {
					visited[ny][nx][0] = visited[cur.y][cur.x][1] + 1; // 이동한 거리 기록
					q.push({ ny, nx, 0 });
				}

				// 벽이 없고 방문하지 않았던 곳이라면
				else if (!a[ny][nx] && !visited[ny][nx][cur.k]) {
					visited[ny][nx][cur.k] = visited[cur.y][cur.x][cur.k] + 1; // 이동한 거리 기록
					q.push({ ny, nx, cur.k });
				}
			}
	}

	return -1; // 목적지 도착할 수 없는 경우
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> hy >> hx;
	cin >> ey >> ex;

	hy--; hx--; ey--; ex--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	cout << bfs(hy, hx) << "\n";

	return 0;
}
