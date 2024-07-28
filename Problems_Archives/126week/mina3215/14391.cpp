#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int ans = 0;
int N, M;
int paper[5][5];
int visited[5][5];

void input() {
	cin >> N >> M;

	fill(&visited[0][0], &visited[0][0] + 5*5, 0);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		// atoi(s[i][j]) 안됨. 방법 찾아보기 + 왜 안되는지 찾아보기
		for (int j = 0; j < M;j++) {
			paper[i][j] = int(s[j]) - int('0');
		}
	}
}

bool check_visited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j])
				return false;
		}
	}
	return true;
}

bool check_line(int y, int x, bool isDx, int d) {
	if (isDx) {
		for (int cnt = d; cnt >= 0; cnt--) {
			if (visited[y][x + cnt])
				return false;
		}
		return true;
	}

	for (int cnt = d; cnt >= 0; cnt--) {
		if (visited[y+cnt][x])
			return false;
	}
	return true;
}

int fill_visited(int y, int x, bool isDx, int d, int val) {

	int line = 0;

	if (isDx) {
		for (int cnt = 0; cnt <= d; cnt++) {
			line *= 10;
			visited[y][x + cnt] = val;
			line += paper[y][x + cnt];
		}
		return line;
	}
	for (int cnt = 0; cnt <=d; cnt++) {
		line *= 10;
		visited[y+cnt][x] = val;
		line += paper[y + cnt][x];
	}
	return line;
	
}

void recursive(int _y, int _x, int sum) {
	if (check_visited()) {
		ans = max(ans, sum);
		return;
	}

	for (int y = _y; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (visited[y][x])
				continue;
			for (int dx = M-1; dx >= 0;dx--) {
				if (x + dx >= M)
					continue;
				if (!check_line(y, x, true, dx))
					continue;
				sum += fill_visited(y, x, true, dx, 1);
				recursive(y, x, sum);
				sum -= fill_visited(y, x, true, dx, 0);

			}

			for (int dy = N-1; dy >= 0;dy--) {
				if (y + dy >= N)
					continue;
				if (!check_line(y, x, false, dy))
					continue;
				sum += fill_visited(y, x, false, dy, 1);
				recursive(y, x, sum);
				sum -= fill_visited(y, x, false, dy, 0);
			}

			return;
		}
	}
}

int main() {
	input();
	recursive(0, 0, 0);
	cout << ans;



}