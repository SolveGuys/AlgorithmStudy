#include <iostream>
#include <queue>
#pragma warning(disable:4996)//scanf에러 무시
using namespace std;

int m, n;
const int maxi = 101;
const int inf = 800000;
int maze[maxi][maxi];//미로
int wall[maxi][maxi];//i,j에서 벽을 몇개 부수는가?  
//4방탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
			wall[i][j] = inf;
		}
	}
}
//미로 탈출
void Escape() {
	wall[1][1] = 0;
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>m) continue;//범위 조건
			
			if (maze[nx][ny] == 1) {//벽
				if (wall[nx][ny] > wall[x][y] + 1) {//더 작은 값이 오면
					wall[nx][ny] = wall[x][y] + 1;
					q.push({ nx, ny });
				}
			}
			else if (maze[nx][ny] == 0) {//빈 방
				if (wall[nx][ny] > wall[x][y]) {//더 작은 값이 오면
					wall[nx][ny] = wall[x][y];
					q.push({ nx, ny });
				}
			}
		}
	}
	cout << wall[n][m];//출력
}
int main() {
	//빠른 입력
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	input();//입력
	Escape();//미로 탈출
	return 0;
}
