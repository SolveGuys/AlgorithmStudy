#include<iostream>
#include<vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> bite(N+1);
	vector<int> cost(N + 1);
	for ( int i = 1; i < N + 1; i++ ) {
		cin >> bite[i];
	}
	for ( int i = 1; i < N + 1; i++ ) {
		cin >> cost[i];
	}
	vector<vector<int>> dp(N + 1, vector<int>(100 * N + 1, 0));
	for ( int i = 1; i < N + 1; i++ ) {
		for ( int j = 0; j < 100 * N + 1; j++ ) {
			if ( cost[i] > j ) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], bite[i] + dp[i - 1][j - cost[i]]);
			}
		}
	}

	for ( int j = 0; j < 100 * N + 1; j++ ) {
		if ( dp[N][j] >= M ) {
			cout << j << endl;
			break;
		}
	}
	return 0;
}