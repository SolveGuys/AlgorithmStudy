#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int k,w,h;
const int maxi = 201;
int board[maxi][maxi];//맵
int visit[maxi][maxi][31];//방문 시간
//축 이동
int dx[12] = {-2,-1,1,2,-2,-1,2,1,0,0,-1,1};
int dy[12] = {-1,-2,-2,-1,1,2,1,2,-1,1,0,0};

//입력
void input() {
	cin >> k>>w>>h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}
	memset(visit, -1, sizeof(visit));//초기화
}
//원숭이 이동
void monkey_move() {
	queue<pair<pair<int, int>,int>> q;
	q.push({ {0,0},k });//위치, 남은 횟수
	visit[0][0][k] = 0;//처음은 0

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		//목표 도달
		if (x == h - 1 && y == w - 1) {
			cout << visit[x][y][cnt];
			return;
		}

		//다음 지점
		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//범위내에 드는가
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			//장애물인가?
			if (board[nx][ny] == 1) continue;

			if (i >= 8) {//기본 이동
				if (visit[nx][ny][cnt] == -1) {//미방문이면
					visit[nx][ny][cnt] = visit[x][y][cnt]+1;
					q.push({ {nx,ny},cnt });
				}
			}
			else {//말 이동
				if (cnt <= 0) continue;//횟수 소진
				if (visit[nx][ny][cnt-1] == -1) {//미방문이면
					visit[nx][ny][cnt-1] = visit[x][y][cnt]+1;
					q.push({ {nx,ny},cnt-1 });
				}
			}
		}
	}
	cout << -1;//도달 불가
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	monkey_move();//원숭이 이동
	return 0;
}
