#include<iostream>
#include<algorithm>

using namespace std;

int RGB[1001][3];
int DP[1001][3];

int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	fill(&DP[0][0], &DP[0][0] + 1000 * 3, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			DP[i][j] = min(DP[i - 1][(j + 1) % 3], DP[i - 1][(j + 2) % 3]);
			DP[i][j] += RGB[i][j];
		}
	}

	int ans = min(DP[N][0], DP[N][1]);
	ans = min(ans, DP[N][2]);

	cout << ans;
}