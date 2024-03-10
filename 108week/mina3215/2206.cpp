#include<iostream>

using namespace std;

int N, M;
int min_V = 2e9;
int MAP[1001][1001];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

struct Info {
	int y, x;
	int prev;
	int n;
	bool is_broken;
};

void DFS(Info info) {
	if (info.y == M && info.x == N) {
		min_V = min(min_V, info.n);
		return;
	}
	if (min_V <= info.n) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = info.y;
		int nx = info.x;
		int move = 0;
		
		if (info.prev == i) continue; // 이전에 움직인 방향으론 가지 않는다. 
		if (info.prev!=-1&&(info.prev + 2) % 4 == i)continue; // 이전에 온 방향으론 돌아가지 않는다. 
		
		Info new_info = { 0, 0, i, 0, info.is_broken };

		while (true) {
			// 다음 위치가 범위 이상이면 가지 않는다. 
			if (ny + dy[i] <= 0 || nx + dx[i] <= 0 || ny + dy[i] > N || nx + dx[i] > M) break;
			// 벽이면 분기.
			if (MAP[ny + dy[i]][nx + dx[i]]) {
				// 1. 이미 벽을 부쉈거나, 안부쉈는 것 관계없이 DFS. 
				new_info.y = ny;
				new_info.x = nx;
				new_info.n = info.n + move;
				DFS(new_info);
				//이미 벽을 부쉈다면?
				if (new_info.is_broken) {
					break; //DFS하고 끝내. 
				}
				//아니면 계속 진행한다. new_info.is_broken = ture로 변경( 벽 부숨 ) >> 다음 벽은 못 부순다. 
				new_info.is_broken = true;
			}

			ny += dy[i];
			nx += dx[i];
			move++;
		}
		new_info.y = ny;
		new_info.x = nx;
		new_info.n = info.n + move;
		if(info.is_broken!=new_info.is_broken) DFS(new_info);
	}

	return;

}

int main() {
	cin >> N >> M;
	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		int j = 1;
		for (auto c : s) MAP[i][j++] = int(c)-48;
	}
	Info start = { 1,1,-1,1,false };
	DFS(start);
	if (min_V == 2e9)min_V = -1;
	cout << min_V;
}