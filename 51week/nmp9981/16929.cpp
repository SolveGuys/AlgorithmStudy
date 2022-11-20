#include <iostream>
using namespace std;

int n,m,sx,sy;
const int maxi = 51;
string board[maxi];//보드판
bool visit[maxi][maxi];//방문 여부
//4방향
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) cin >> board[i];
}
//사이클 존재여부
void Cycle(int x, int y, char s,int depth) {
	//도착
	if (sx == x && sy == y && depth >= 4) {
		cout << "Yes";//사이클 존재
		exit(0);
	}
	//다음 지점
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
		if (visit[nx][ny] == true) continue;//방문 조건
		if (board[nx][ny] != s) continue;//문자 조건

		visit[nx][ny] = true;
		Cycle(nx, ny, s, depth + 1);
	}
	visit[x][y] = false;
	return;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == true) continue;//방문 여부
			sx = i, sy = j;//도착점 지정
			Cycle(i, j, board[i][j], 1);//사이클 검사
		}
	}
	cout << "No";//사이클이 존재하지 않음
	return 0;
}
