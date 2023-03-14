#include <iostream>
using namespace std;

int n;
const int maxi = 501;
int Forest[maxi][maxi];//숲
int canMove[maxi][maxi];//최대 이동 칸수
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int a,int b) {
	return a > b ? a : b;
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Forest[i][j];
			canMove[i][j] = -1;
		}
	}
}
//먹기
int Eat(int x, int y) {
	if (canMove[x][y] != -1) return canMove[x][y];//이미 이동했었다.

	canMove[x][y] = 1;
	//다음 지점
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
		//이전보다 더 큰가?
		if (Forest[nx][ny] > Forest[x][y]) canMove[x][y] = max(canMove[x][y],Eat(nx, ny)+1);
	}
	return canMove[x][y];//거슬러 올라감
}
//시작 지점 고르기
void Select() {
	int maxMove = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			canMove[i][j] = Eat(i, j);
			maxMove = max(maxMove, canMove[i][j]);
		}
	}
	cout << maxMove;//출력
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Select();//시작지점 선택
	return 0;
}
