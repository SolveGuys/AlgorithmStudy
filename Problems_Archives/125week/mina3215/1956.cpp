#include<iostream>
#include<algorithm>

using namespace std;

long long MAP[401][401];
int N, M;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		MAP[a][b] = c;
	}
}

int main() {
	fill(&MAP[0][0], &MAP[0][0] + 401 * 401, 2e9);
	input();

	for (int mid = 1;mid < N + 1; mid++) {
		for (int start = 1;start < N+1; start++) {
			for (int end = 1; end < N + 1; end++) {
				MAP[start][end] = min(MAP[start][end], MAP[start][mid] + MAP[mid][end]);
			}
		}
	}
	long long ans = 2e9;

	for (int i = 1; i < N + 1; i++) {
		ans = min(ans, MAP[i][i]);
	}

	if (ans == 2e9)
		ans = -1;
	cout << ans;
}