#include<iostream>
#include<algorithm>

using namespace std;

int dy[] = { 0,1 };
int dx[] = { 1,0 };

long long DP[102][102];
int board[102][102];
int N;

void find_jump(int y, int x) {
	for (int i = 0; i < 2; i++) {
		int ny = y + (dy[i] * board[y][x]);
		int nx = x + (dx[i] * board[y][x]);
		if (ny >= N || nx >= N) continue;
		DP[ny][nx] += DP[y][x];
	}
}

int main() {
	cin >> N;
	fill(&DP[0][0], &DP[0][0] + N*N, 0);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}
	DP[0][0] = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (DP[y][x]&&board[y][x]!=0) {
				find_jump(y, x);
			}
		}
	}

	cout << DP[N - 1][N - 1];
}