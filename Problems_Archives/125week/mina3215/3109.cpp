#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int R, C;

int dy[] = { -1,0,1 };
int dx[] = { 1,1,1 };

int ans = 0;

vector<vector<int>> check(10001, vector<int>(501));
vector<string> v(10001);

void DFS(int y, int x, bool &isGoal) {
	if (x == C) {
		isGoal = true;
		ans++;
		return;
	}
	check[y][x] = 1;

	for (int i = 0;i < 3;i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R) continue;
		if (v[ny][nx] == 'x')continue;
		if (check[ny][nx]) continue;
		DFS(ny, nx, isGoal);
		if (isGoal) return;
	}

	return;

}

int main() {
	cin >> R >> C;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < R; i++) {
		fill(check[i].begin(), check[i].end(), 0);
	}

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		v[i] = s;
	}

	for (int y = 0; y < R; y++) {
		bool isGoal = false;
		DFS(y, 0, isGoal);
	}
	

	cout << ans;

	return 0;
}