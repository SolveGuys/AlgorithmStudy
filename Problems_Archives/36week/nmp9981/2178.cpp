#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <queue>
using namespace std;

int n,m;
const int maxi = 101;
int maze[maxi][maxi];//미로
int visit[maxi][maxi];//지나가는 칸수
//이동
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%1d", &maze[i][j]);
	}
}

//미로 이동
void move() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = 1;//첫번째칸 방문

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//종료
		if (x == n - 1 && y == m - 1) {
			cout << visit[x][y];//출력
			return;
		}

		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//범위내에 드는가?
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			//이미 방문한 지역인가?
			if (visit[nx][ny] != 0) continue;
			//장애물이 있는가?
			if (maze[nx][ny] == 0) continue;

			q.push({ nx,ny });
			visit[nx][ny] = visit[x][y] + 1;//다음 지점 방문
		}
	}
}
int main()
{
	//빠른 입력
	//ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	move();//미로 이동
	return 0;
}
