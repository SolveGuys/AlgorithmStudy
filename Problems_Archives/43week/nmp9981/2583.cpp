#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n, k;
const int maxi = 101;
bool board[maxi][maxi];//보드판
vector<int> Area;//넓이
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	cin >> m >> n >> k;
	memset(board, false, sizeof(board));//초기화
	for (int c = 0; c < k; c++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//T채우기
		for (int i = m-y2; i < m-y1; i++) {
			for (int j = x1; j < x2; j++) board[i][j] = true;
		}
	}
}

//빈 공간 넓이 구하기
void emptyArea(int x, int y) {
	int square = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });//행,열 기준
	board[x][y] = 1;

	while (!q.empty()) {
		int xpos = q.front().first;
		int ypos = q.front().second;
		q.pop();

		//다음 지점
		for (int dir = 0; dir < 4; dir++) {
			int nx = xpos + dx[dir];
			int ny = ypos + dy[dir];
			if (nx<0 || nx>=m || ny < 0 || ny>=n) continue;
			if (!board[nx][ny]) {
				q.push({ nx,ny });
				board[nx][ny] = true;//방문 체크
				square += 1;//넓이 증가
			}
		}
	}
	Area.push_back(square);//결과 넣기
}

//결과 출력
void result() {
	sort(Area.begin(), Area.end());//정렬
	cout << Area.size() << "\n";
	for (int i = 0; i < Area.size(); i++) {
		cout << Area[i] << " ";
	}
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	//직사각형 넓이 구하기(행,열 기준)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == false) emptyArea(i, j);//빈 공간 탐색
		}
	}
	result();//결과 출력
    return 0;
}
