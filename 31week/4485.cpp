#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,num;
const int maxi = 126;
const int inf = 1e+8;
int cave[maxi][maxi];//동굴
int money[maxi][maxi];//잃은 액수
int dx[4] = { -1,1,0,0 };//4방 탐색
int dy[4] = { 0,0,-1,1 };

//초기화
void init() {
	memset(cave, 0, sizeof(cave));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) money[i][j] = inf;
	}
}

//입력
void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> cave[i][j];
	}
}

//너비 우선 탐색
void bfs(int st_x, int st_y) {
	queue<pair<int, int>> q;
	q.push({ st_x,st_y });
	money[st_x][st_y] = cave[st_x][st_y];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위내에 드는가?
			//더 금액이 적으면
			if (money[nx][ny] > money[x][y] + cave[nx][ny]) {
				money[nx][ny] = money[x][y] + cave[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	num = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;

		init();//초기화
		input();//입력
		bfs(0, 0);//탐색
		cout << "Problem " << num << ": " << money[n - 1][n - 1] << "\n";//출력
		num++;
	}
	return 0;
}
