#include <iostream>
#include <cstring>
using namespace std;

int n, m;
const int maxi = 501;
int dp[maxi][maxi];//조합값담는 배열
int world[maxi][maxi];//지도
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	memset(dp, -1, sizeof(dp));
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> world[i][j];
	}
}

//내리막길 경우의 수
int dfs(int x, int y) {
	//탐색 완료
	if (x == n - 1 && y == m - 1) {
		return 1;//경우의 수 1 증가
	}

	//이미 방문한곳
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;

	//다음 지점
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위내에 드는가?
		if (world[x][y] > world[nx][ny]) {//내리막길이면
			dp[x][y] += dfs(nx, ny);//거슬러 올라간다
		}
	}
	return dp[x][y];
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	cout << dfs(0, 0);//출력
	return 0;
}
