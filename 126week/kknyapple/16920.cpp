/*
* 플레이어가 순서대로 돌아가며 성을 확장
* Si칸 만큼 확장할 수 있고 위, 왼쪽, 오른쪽, 아래로 확장
* 플레이어 각각 성의 개수 출력
*/

#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

int n, m, p;
string s;
char a[1004][1004];
int si[10];
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int res[10];
queue <pair<int, int>> q[10];

void go(int player) { // bfs
	for (int k = 0; k < si[player]; k++) { // Si칸 만큼 확장
		int qSize = q[player].size();
		if (qSize == 0) return;

		while (qSize--) { // player 성 개수 만큼 반복
			int y, x;
			tie(y, x) = q[player].front();
			q[player].pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
				if (a[ny][nx] == '.') {
					q[player].push({ ny, nx });
					a[ny][nx] = player;
					res[player]++; // 성의 개수 저장
				}

			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> si[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];

			if (a[i][j] >= '1' && a[i][j] <= '9') {
				q[a[i][j]-'0'].push({ i,j });
				res[a[i][j] - '0']++;
			}
		}
	}

	while (1) {
		int cnt = 0;
		for (int player = 1; player <= p; player++) {
			if (q[player].empty()) cnt++;
			else go(player);
		}
		if (cnt == p) break; // 모든 플레이어가 확장을 할 수 없는 경우
	}

	for (int i = 1; i <= p; i++) {
		cout << res[i] << " ";
	}

	return 0;
}
