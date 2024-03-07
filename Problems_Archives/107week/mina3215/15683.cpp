#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int board[8][8];
int N, M;
int min_cnt = 2e9;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int p = 0;
typedef pair<int, int> pii;

vector<pair<int, pii>> CCTV;
vector<pii> No5;

void find_MinNum(int n, int dir, int cnt, int _board[8][8]) {
	if (n >= CCTV.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (_board[i][j] == 0)cnt++;
			}
		}

		min_cnt = min(min_cnt, cnt);
		return;
	}
	//복사할 배열
	int n_board[8][8];

	int v = CCTV[n].first;

	int y = CCTV[n].second.first;
	int x = CCTV[n].second.second;

	//복사
	//copy(&_board[0][0], &_board[0][0] + 8 * 8, &n_board[0][0]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			n_board[i][j] = _board[i][j];
		}
	}

	for (int d = 0; d < 4; d++) {
		if (v == 1 && dir != d) continue;
		if (v == 2 && ((dir != d) && dir != ((d + 2) % 4))) continue;
		if (v == 3 && ((dir != d) && (dir != (d + 1) % 4)))continue;
		if (v == 4 && dir == d)continue;
		int ny = y;
		int nx = x;
		while (true) {
			ny += dy[d];
			nx += dx[d];
			if (ny >= N || ny < 0 || nx >= M || nx < 0) break;
			if (board[ny][nx] == 6)break;
			if (board[ny][nx] == 0) {
				n_board[ny][nx] = 10;
			}
		}

	}
	//어느 방향을 기준으로 하는가
	for (int i = 0; i < 4; i++) {
		if (CCTV[n + 1].first == 2 && (i == 2 || i == 3)) return ;
		find_MinNum(n + 1, i, cnt, n_board);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	//입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 5)
				No5.push_back({ i,j });
			else if (board[i][j] <= 4 && board[i][j] >= 1)
				CCTV.push_back({ board[i][j],{i, j} });
		}
	}

	//일단 5는 무조건 4방향 확정
	for (int i = 0; i < No5.size();i++) {
		int y = No5[i].first;
		int x = No5[i].second;
		for (int j = 0; j < 4; j++) {
			int ny = y;
			int nx = x;
			while (true) {
				ny += dy[j];
				nx += dx[j];
				if (ny >= N || ny < 0 || nx >= M || nx < 0) break;
				if (board[ny][nx] == 6)break;
				if (board[ny][nx] == 0) board[ny][nx] = 10;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		find_MinNum(0, i, 0, board);
	}
	//0번 CCTV를 보낸다. 
	cout << min_cnt;

	return 0;
}