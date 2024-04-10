#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;
int DP[501][501];
int ans[501][501];

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		fill(&ans[0][0], &ans[0][0] + 501 * 501, 2e9);
		fill(&DP[0][0], &DP[0][0] + 501 * 501, 2e9);
		for (int i = 0; i < N; i++) {
			cin >> DP[i][i];
			ans[i][i] = 0;
		}
		for (int l = 1; l < N; l++) {
			for (int s = 0; s < N - l; s++) {
				for (int m = 0; m < l; m++) {
					DP[s][s + l] = min(DP[s][s + l], DP[s][s + m] + DP[s + m + 1][s + l]);
					ans[s][s + l] = min(ans[s][s + l], ans[s][s + m] + ans[s + m + 1][s + l]+DP[s][s+l]);
				}
			}
		}


		cout << ans[0][N - 1] << '\n';
		
	}
}