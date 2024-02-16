#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

char cBoard[51][51];
int check[51][51];
int visited[51][51];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int N, M;
int ans0, ans1;
int sy, sx;

void BFS() {
	priority_queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, sy,sx});
	
	while (!q.empty()) {
		tuple<int, int, int, int> t = q.top();
		int g = -get<0>(t);
		int ng = -get<1>(t);
		int y = get<2>(t);
		int x = get<3>(t);
		q.pop();

		if (visited[y][x]) continue;
		
		visited[y][x] = 1;
		
		if (cBoard[y][x]=='F') {
			ans0 = g;
			ans1 = ng;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			//방문한적 있는 노드면 패스
			if (visited[ny][nx]) continue;
			//쓰레기가 있는 노드면
			if (cBoard[ny][nx] == 'g') {
				q.push({ -(g + 1),-ng,ny,nx });
			}
			else {
				q.push({ -g,-(ng + check[ny][nx]),ny,nx });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
	fill(&check[0][0], &check[0][0] + 51 * 51, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cBoard[i][j];
			if (cBoard[i][j] == 'S') {
				sy = i;
				sx = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cBoard[i][j] == 'g') {
				for (int k = 0; k < 4; k++) {
					int ni = i + dy[k];
					int nj = j + dx[k];
					if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
					if (cBoard[ni][nj] == '.') check[ni][nj] = 1;
				}
			}

		}
	}
	BFS();
	cout << ans0<<' '<< ans1;
}