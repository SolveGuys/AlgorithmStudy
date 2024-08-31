#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>

using namespace std;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int dp[51][51];
int visited[51][51];

string board[51];
int N, M;
int ans = 0;


int dfs(int y, int x) {
	if (visited[y][x])
		ans = -1;
	if (ans == -1)
		return 0;
	if (dp[y][x] != -1)
		return dp[y][x];

	int num = int(board[y][x]) - int('0');
	visited[y][x] = 1;

	int maxSteps = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * num;
		int nx = x + dx[i] * num;
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (board[ny][nx] == 'H')
			continue;
		maxSteps = max(maxSteps, dfs(ny, nx));
	}
	visited[y][x] = 0;

	dp[y][x] = maxSteps + 1;

	return dp[y][x];

}

// 1. ������ �ִ� ���� ���� �ִ� ���� x�� ����.
// 2. ��, �Ʒ�, ������ ���� �� �Ѱ����� ����.
// 3. ������ ������ �� �������� x��ŭ �����δ�. �߰��� �ִ� ������ ����.
int main() {
	cin >> N >> M;
	string s;
	fill(&dp[0][0], &dp[0][0] + 51 * 51, -1);
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int answer = dfs(0, 0);
	ans = ans == -1 ? ans : answer;
	cout << ans;


}