#include <iostream>
#include <queue>
using namespace std;

struct Hero {//영웅 위치
	int xpos, ypos, times;
};
int n, m, t;
const int maxi = 101;
const int inf = 100000000;
int gramTime = inf;//그람을 사용했을때의 시간
int moveTime = 0;//이동 시간
int castle[maxi][maxi];//성
bool visit[maxi][maxi];//방문 여부
int dx[4] = { -1,1,0,0 };//4방 탐색
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> castle[i][j];
	}
}
//그람
int Gram(int x, int y, int hours) {
	return hours + abs(x - n) + abs(y - m);
}
//용사 이동
void HeroMove(int i, int j) {
	queue <Hero> q;
	q.push({ i,j,0 });
	visit[i][j] = true;

	while (!q.empty()) {
		int x = q.front().xpos;
		int y = q.front().ypos;
		int cnt = q.front().times;
		q.pop();

		//시간 초과
		if (cnt > t) {
			moveTime = cnt;
			return;
		}
		//그람
		if (castle[x][y] == 2) gramTime = Gram(x, y, cnt);

		//도착
		if (x == n && y == m) {
			moveTime = cnt;
			return;
		}

		//다음 지점
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;//범위 조건
			if (visit[nx][ny]) continue;//방문 조건
			if (castle[nx][ny] == 1) continue;//장애물

			q.push({ nx,ny,cnt + 1 });
			visit[nx][ny] = true;
		}
	}
	moveTime = inf;//도달 불가
}
//확인
void Check() {
	moveTime = min(moveTime, gramTime);//최종 시간
	//결과 출력
	if (moveTime > t) cout << "Fail";
	else cout << moveTime;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	HeroMove(1, 1);//이동
	Check();//확인
	return 0;
}
