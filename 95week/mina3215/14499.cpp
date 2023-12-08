#include<iostream>
#include<algorithm>

using namespace std;

// 동, 서, 북, 남
int dy[] = { 0,0,0,-1,1 };
int dx[] = { 0,1,-1,0,0 };

int N, M, x, y, K; // 세로크기, 가로크기, 주사위 좌표, 명령 K
int board[20][20];
int dice[2][4]; // 세로, 가로 
//북, 중앙, 남, 반대
//서, 중앙 ,동 ,반대

int pivot_col = 1;
int pivot_row = 1;

void check_dice(int comm) {
	pivot_col = (pivot_col + dy[comm] + 4) % 4;
	pivot_row = (pivot_row + dx[comm] + 4) % 4;

	//주사위랑 board에 숫자 표기
	//반대편 숫자 출력
	if (comm < 3) {
		dice[0][pivot_col] = dice[1][pivot_row];
		dice[0][(pivot_col + 2) % 4] = dice[1][(pivot_row + 2) % 4];
	}
	else {
		dice[1][pivot_row] = dice[0][pivot_col];
		dice[1][(pivot_row + 2) % 4] = dice[0][(pivot_col + 2) % 4];
	}

	cout << dice[1][(pivot_row + 2) % 4] << '\n';

}

int main() {
	cin >> N >> M >> y >> x >> K;
	fill(&dice[0][0], &dice[0][0] + 2 * 4, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int comm;

	for (int i = 0; i < K;i++) {
		cin >> comm;
		int ny = y + dy[comm];
		int nx = x + dx[comm];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (board[y][x]) {
			dice[0][pivot_col] = board[y][x];
			dice[1][pivot_row] = board[y][x];
			board[y][x] = 0;
		}
		else {
			board[y][x] = dice[1][pivot_row];
		}
		check_dice(comm);
		y = ny;
		x = nx;
	}

}