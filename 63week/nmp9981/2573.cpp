#include <iostream>
#include <queue>
using namespace std;

int n, m;
int times = 0;//시간
const int maxi = 301;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
int meltIce[maxi][maxi];//녹이는 양
int dx[4] = { -1,1,0,0 };//4방 탐색
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> world[i][j];
	}
}
//초기화
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = false;
			meltIce[i][j] = 0;
		}
	}
}
//덩어리 검사
int Ice(int i,int j) {
	queue <pair<int,int>> q;
	q.push({ i,j});
	visit[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음 지점
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
			if (visit[nx][ny]) continue;//방문 조건
			if (world[nx][ny] <= 0) continue;//바닷물

			q.push({ nx,ny});
			visit[nx][ny] = true;
		}
	}
	return 1;
}
//덩어리
int Lump() {
	int lump = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//미방문이고 육지이다
			if (!visit[i][j] && world[i][j]>0) lump += Ice(i, j);
		}
	}
	return lump;
}
//녹이기
void Melt() {
	//녹는 양
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (world[i][j] <= 0) continue;//바다는 탐색할 필요 없다
			int meltAmount = 0;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (world[ni][nj] == 0) meltAmount++;
			}
			meltIce[i][j] = meltAmount;
		}
	}
	//녹이기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) world[i][j] = max(0,world[i][j] - meltIce[i][j]);
	}
}
//다 녹았는가?
bool IsAllMelt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (world[i][j] > 0) return false;//다 안녹음
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	while (true) {
		init();//초기화
		if (Lump() >= 2) {//덩어리 개수
			cout << times;//시간
			break;
		}
		Melt();//녹이기
		if (IsAllMelt()) {//다 녹았는가?
			cout << 0;
			break;
		}
		times++;
	}
	return 0;
}
