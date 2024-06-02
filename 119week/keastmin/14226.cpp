#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int S;
vector<int> dp;

void BFS() {
	// 이모티콘 갯수, 클립보드, 시간
	queue<tuple<int, int, int>> q;

	// visited[a][b]: 화면에 a개의 이모티콘, 클립보드에 b개의 이모티콘
	vector<vector<int>> visited((S + 1) * 2, vector<int>((S + 1) * 2, false));
	visited[1][0] = true;
	q.push({ 1, 0, 0 });

	while (!q.empty()) {
		int i, c, t;
		tie(i, c, t) = q.front();
		q.pop();
		dp[i] = t;

		if (S == i) return;

		if (i > 0 && i < (S + 1) * 2) {
			if (!visited[i][i]) {
				q.push({ i, i, t + 1 });
				visited[i][i] = true;
			}
			if (!visited[i - 1][c]) {
				q.push({ i - 1, c, t + 1 });
				visited[i - 1][c] = true;
			}
		}
		if (c > 0 && i + c < (S + 1) * 2) {
			if (!visited[i + c][c]) {
				q.push({ i + c, c, t + 1 });
				visited[i + c][c] = true;
			}
		}
	}
}

int main() {
	cin >> S;
	dp.resize((S + 1) * 2);

	BFS();
	cout << dp[S] << '\n';

	return 0;
}
