#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<math.h>

using namespace std;

int N, M, T, D;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int MAP[25][25];
long long visited[25 * 25][2];

int cal(int nv, int d) {
	if (d) {
		if (nv < 0)
			return pow(nv, 2);
		return 1;
	}
	else {
		if (nv > 0)
			return pow(nv, 2);
		return 1;
	}

}

void check_time(int d) {

	priority_queue<tuple<long long,int,int>> pq;
	pq.push({ 0,0,0 });

	while (!pq.empty()) {
		long long v;
		int y,x;
		tie(v,y,x) = pq.top();
		pq.pop();
		v *= -1;

		if (visited[y * M + x][d]!=2e9) continue;
		visited[y * M + x][d] = v;
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny * M + nx][d]!=2e9) continue;

			int nv = MAP[y][x] - MAP[ny][nx];
			if (abs(nv) > T) continue;
			
			pq.push({ -(v + cal(nv, d)),ny,nx });
		}
	}

}

int main() {
	cin >> N >> M >> T >> D;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			char n;
			cin >> n;
			MAP[i][j] = n >= 'a' ? int(n) - int('a') + 26 : int(n) - int('A');
		}
	}

	fill(&visited[0][0], &visited[0][0] + 25 * 25 * 2, 2e9);

	// 가는 길
	check_time(0);
	// 오는 길
	check_time(1);
	
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i * M + j][0] + visited[i * M + j][1] - 2 <= D) {
				ans = max(ans, MAP[i][j]);
				//if (MAP[i][j] == 41) cout << visited[i * M + j][0] + visited[i * M + j][1]<<'\n';
			}
		}
	}

	cout << ans;
}