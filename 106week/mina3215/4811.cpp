#include<iostream>

using namespace std;

long long dp[61][31];//h갯수

int main() {
	
	fill(&dp[0][0], &dp[0][0] + 60 * 30, 0);

	dp[0][1] = 1; // 첫날 h가 1인 상황 1.
	for (int i = 1; i <= 60; i++) {
		for (int j = 0; j <= 30; j++) {
			if (j - 1 >= 0)
				dp[i][j] += dp[i-1][j - 1];
			if (j + 1 <= 30)
				dp[i][j] += dp[i-1][j + 1];
		}
	}
	int n;
	while (cin >> n && n != 0) {
		cout << dp[2*n-1][0] << '\n';
	}
}